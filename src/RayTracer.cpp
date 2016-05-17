#include <fstream>

#include "Vec3f.h"
#include "ray.h"
#include "PNG.h"

vec3 color(const ray& r)
{
	vec3 unitDir = r.direction().unitVector();

	// Rescale unitDir.y from -1 - 1 to 0 - 1
	float t = 0.5f * ( unitDir.y + 1.f );

	// Lerp white - blue.
	return (1.f - t) * vec3(1.f, 1.f, 1.f) + t * vec3(0.5f, 0.7f, 1.f);
}

int main()
{	
	PNG img(200, 100, 3);

	// Image plane dimensions.
	vec3 origin(0.f,0.f,0.f);
	vec3 lowerLeftCorner(-2.f, -1.f, -1.f);
	vec3 height(4.f, 0.f, 0.f);
	vec3 width(0.f, 2.f, 0.f);
	
	// Raymarch through all pixels.
	for (int j = img.y - 1; j >= 0; j--)
	{
		for (int i = 0; i < img.x ; i++)
		{
			float u = float(i) / float(img.x);
			float v = float(j) / img.y;

			ray r(origin, lowerLeftCorner + u * width + v * height);
			vec3 col = color(r);

			img.setPixel(i, img.y - 1 - j, 255.99f * col.x, 255.99f * col.y, 255.99f * col.z);
		}
	}

	if (!img.saveToImage("test.png")) std::cout << "Failed to save image" << std::endl;

    return 0;
}

