#pragma once
#include "ray.h"

class Material;

struct Intersection
{
	float t;
	vec3 p;
	vec3 normal;
	const Material* pMaterial;
};

class Intersectable 
{
public:
	virtual ~Intersectable() = default;
	virtual bool intersect(const ray& r, float tMin, float tMax, Intersection& intersectOut) = 0;
};
