#pragma once
#include "ray.h"

struct Intersection
{
	float t;
	vec3 p;
	vec3 normal;
};

class Intersectable 
{
public:
	virtual ~Intersectable() = default;
	virtual bool intersect(const ray& r, float tMin, float tMax, Intersection& intersectOut) = 0;
};
