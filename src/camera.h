#pragma once

#include "ray.h"

class camera
{
public:
	camera(const vec3& origin, const vec3& lowerLeft, const vec3& horizontal, const vec3& vertical)
		: origin(origin),
		  lowerLeft(lowerLeft),
		  horizontal(horizontal),
		  vertical(vertical) {}

	vec3 origin;
	vec3 lowerLeft;
	vec3 horizontal;
	vec3 vertical;

	ray getRay(float u, float v)
	{
		return ray(origin, lowerLeft + u * horizontal + v * vertical - origin);
	}
};
