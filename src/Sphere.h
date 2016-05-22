#pragma once

#include "Intersectable.h"
#include "Material.h"

class Sphere : public Intersectable
{
public:
	Sphere(vec3& center, float radius, const Material& rMaterial) : m_center(center), m_radius(radius), m_rMaterial(rMaterial) {}

	virtual bool intersect(const ray& r, float tMin, float tMax, Intersection& intersectOut) override;

private:
	vec3 m_center;
	float m_radius;
	const Material& m_rMaterial;
};

// Solve:
// t * t * dot( B, B ) + 2 * t * dot( B, A - C ) + dot( A-C, A-C ) - R * R = 0
bool Sphere::intersect(const ray& r, float tMin, float tMax, Intersection& intersectOut)
{
	vec3 direction = r.direction;
	vec3 origToCenter = r.origin - m_center;

	float a = direction.dot(direction);
	float b = origToCenter.dot(direction);
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
			intersectOut.pMaterial = &m_rMaterial;
			return true;
		}
	}
	return false;
}
