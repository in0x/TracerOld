#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

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
	virtual bool intersect(const ray& r, float tMin, float tMax, Intersection& intersectOut) = 0;
};


#endif // INTERSECTABLE_H