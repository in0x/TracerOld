#pragma once

//https://github.com/nothings/stb
#include "stb_image.h"
#include "stb_image_write.h"

#include <cassert>

class PNG
{
public:
	PNG(const char* filePath, int _x, int _y, int _comp) : x(_x), y(_y), components(_comp) 
	{
		loadFromImage(filePath, x, y, components);
	}

	PNG(int _x, int _y, int _comp) : x(_x), y(_y), components(_comp)
	{
		data =  new unsigned char[_x*_y*components];
	}

	~PNG()
	{
		//stbi_image_free(data);
	}

	// Public members

	int x;
	int y;
	int components;

	// Public member functions

	bool loadFromImage(const char* filePath, int x, int y, int compPerPixel);
	bool saveToImage(const char* filePath);

	template<class ...PixelValues>
	void setPixel(int row, int column, PixelValues... pack)
	{
		assert(sizeof...(pack) == components);

		unsigned char values[] = {pack...};

		for (int idx = 0; idx < sizeof...(pack); idx++)
		{
			data[idx + (row * components + column * components * x)] = values[idx];
		}
	}


private:
	// Private members

	unsigned char* data;
};
