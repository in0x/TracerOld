#include <fstream>

#include "Vec3f.h"
#include "ray.h"
#include "PNG.h"

vec3 color(const ray& r)
{
	vec3 unitDir = r.direction().unitVector();
	float t = 0.5f * ( unitDir.y + 1.f );
	return (1.f - t) * vec3(1.f, 1.f, 1.f) + t * vec3(0.5f, 0.7f, 1.f);
}

int main()
{	
	PNG image(200, 100, 4);
	image.saveToImage("test.png");

	std::ofstream outStream("img1.ppm");
	
	float pixelsX = 200;
	float pixelsY = 100;

	outStream << "P3\n" << pixelsX << " " << pixelsY << "\n255\n";

	for (int j = pixelsY - 1; j >= 0; j--)
	{
		for (int i = 0; i < pixelsX; i++)
		{
			vec3 col(float(i) / pixelsX, float(j) / pixelsY, 0.2f);

			int ir = int(255.99f * col.x);
			int ig = int(255.99f * col.y);
			int ib = int(255.99f * col.z);

			outStream << ir << " " << ig << " " << ib << "\n";
		}
	}

	outStream.close();
    return 0;
}

