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

void PNG::setPixel(int row, int column, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	data[row*x + column*y]	   = r;
	data[row*x + column*y + 1] = g;
	data[row*x + column*y + 2] = b;
	data[row*x + column*y + 3] = a;
}