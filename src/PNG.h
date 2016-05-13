#ifndef PNG_H
#define PNG_H

//https://github.com/nothings/stb
#include "stb_image.h"
#include "stb_image_write.h"

class PNG
{
public:
	PNG(unsigned char* _data, int _x, int _y, int _comp) :
		data(_data), x(_x), y(_y), components(_comp) {}

	PNG(int _x, int _y, int _comp) : x(_x), y(_y), components(_comp)
	{
		data =  new unsigned char[_x*_y];
	}

	~PNG()
	{
		stbi_image_free(data);
	}

	// Public members

	int x;
	int y;
	int components;

	// Public member functions

	bool loadFromImage(const char* filePath, int x, int y, int compPerPixel);
	bool saveToImage(const char* filePath);
	void setPixel(int row, int column, unsigned char r, unsigned char g, unsigned char b, unsigned char a);

private:
	// Private members

	unsigned char* data;
};

#endif // PNG_H