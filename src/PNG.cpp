#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "PNG.h"

bool PNG::loadFromImage(const char* filePath, int x, int y, int compPerPixel)
{
	data = stbi_load(filePath, &x, &y, &compPerPixel, 0);

	if (data == nullptr)
	{
		return false;
	}

	return true;
}

bool PNG::saveToImage(const char* filePath)
{
	if (!stbi_write_png(filePath, x, y, components, data, x * components * sizeof(unsigned char)))
	{
		return false;
	}
	
	return true;
}
