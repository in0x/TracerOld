#pragma once

#include "Material.h"
#include "MathUtil.h"

class Lambertian : public Material
{
public:
	Lambertian(const vec3& albedo) : albedo(albedo) {}

	vec3 albedo;

	virtual bool scatter(const ray& r_in, const Intersection& record, vec3& attenuation, ray& scattered) const override;
};

// Scatter incoming ray and adjust by albedo
bool Lambertian::scatter(const ray& r_in, const Intersection& record, vec3& attenuation, ray& scattered) const
{
	vec3 target = record.p + record.normal + Math::randInUnitSphere();
	scattered = ray(record.p, target - record.p);
	attenuation = albedo;
	return true;
}