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
	PNG img(200, 100, 3);
	
	for (int j = img.y - 1; j >= 0; j--)
	{
		for (int i = 0; i < img.x ; i++)
		{
			vec3 col(float(i) / float(img.x), float(j) / float(img.y), 0.2f);
			img.setPixel(i, img.y - 1 - j, 255.99f * col.x, 255.99f * col.y, 255.99f * col.z);
		}
	}

	if (!img.saveToImage("test.png")) std::cout << "Failed to save image" << std::endl;

    return 0;
}

