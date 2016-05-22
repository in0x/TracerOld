#include <fstream>
#include <cassert>

#include "Sphere.h"
#include "Lambertian.h"
#include "Metal.h"
#include "IntersectableList.h"
#include "PNG.h"
#include "camera.h"
#include "MathUtil.h"

vec3 color(const ray& r, IntersectableList& world, int depth)
{
	Intersection record;
	if (world.intersect(r, 0.001f, std::numeric_limits<float>::max(), record))
	{
		ray scattered;
		vec3 attenuation;
		if (depth > 0 && record.pMaterial->scatter(r, record, attenuation, scattered))
		{
			return attenuation * color(scattered, world, depth - 1);
		}
		else return vec3(0, 0, 0);
	}
	else
	{
		vec3 unitDir = r.direction.unitVector();
		float t = 0.5f * (unitDir.y + 1.f);
		return (1.f - t) * vec3(1.f, 1.f, 1.f) + t * vec3(0.5f, 0.7f, 1.f);
	}
}

int main()
{	
	PNG img(400, 200, 3);
	int samples = 50;
	camera cam(vec3(0.f, 0.f, 0.f), vec3(-2.f, -1.f, -1.f), vec3(4.f, 0.f, 0.f), vec3(0.f, 2.f, 0.f));

	Lambertian lambertRed(vec3(0.8f, 0.3f, 0.3f));
	Lambertian lambertYellow(vec3(0.8f, 0.8f, 0.f));
	Metal metalSilver(vec3(0.8f, 0.6f, 0.2f), 0.f);
	//Metal metalGold(vec3(0.8f, 0.8f, 0.8f));

	IntersectableList world;
	world.Add(std::make_unique<Sphere>(vec3(0.f, 0.f, -1.f), 0.5f, lambertRed));
	world.Add(std::make_unique<Sphere>(vec3(0.f, -100.5f, -1.f), 100.f, lambertYellow));
	world.Add(std::make_unique<Sphere>(vec3(1.f, 0.f, -1.f), 0.5f, metalSilver));

	// Raymarch through all pixels.
	for (int j = img.y - 1; j >= 0; j--)
	{
		// Mutli-sample around pixel for AA.
		for (int i = 0; i < img.x ; i++)
		{
			vec3 col(0,0,0);
			for (int s = 0; s < samples; s++)
			{
				float u = float(i + Math::getRandom()) / float(img.x);
				float v = float(j + Math::getRandom()) / float(img.y);

				ray r = cam.getRay(u, v);
				vec3 p = r.pointAtParam(2.0);
				col += color(r, world, 10);
			}
			col /= float(samples);
			col = vec3(sqrt(col.x), sqrt(col.y), sqrt(col.z));
			img.setPixel(i, img.y - 1 - j, 255.99f * col.x, 255.99f * col.y, 255.99f * col.z);
		}
	}

	if (!img.saveToImage("test.png")) std::cout << "Failed to save image" << std::endl;

    return 0;
}

