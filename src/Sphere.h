#ifndef SPHERE_H
#define SPHERE_H

#include "Intersectable.h"

class Sphere : public Intersectable
{
public:
	Sphere() {}
	Sphere(vec3& center, float radius) : m_center(center), m_radius(radius) {}

	virtual bool intersect(const ray& r, float tMin, float tMax, Intersection& intersectOut) override;

private:
	vec3 m_center;
	float m_radius;
};

bool Sphere::intersect(const ray& r, float tMin, float tMax, Intersection& intersectOut)
{
	return true;
}

#endif // SPHERE_H