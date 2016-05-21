#pragma once

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

// Solve:
// t * t * dot( B, B ) + 2 * t * dot( B, A - C ) + dot( A-C, A-C ) - R * R = 0
bool Sphere::intersect(const ray& r, float tMin, float tMax, Intersection& intersectOut)
{
	vec3 origToCenter = r.origin() - m_center;

	float a = r.direction().dot(r.direction());
	float b = origToCenter.dot(r.direction());
	float c = origToCenter.dot(origToCenter) - m_radius * m_radius;
	float discrimnant = b*b - a*c;

	if (discrimnant > 0)
	{
		float t = (-b - sqrt(discrimnant)) / a;
		if (t < tMax && t > tMin)
		{
			intersectOut.t = t;
			intersectOut.p = r.pointAtParam(intersectOut.t);
			intersectOut.normal = (intersectOut.p - m_center) / m_radius;
			return true;
		}
	}
	return false;
}
