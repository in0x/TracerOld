#pragma once

#include "Material.h"
#include "MathUtil.h"

class Metal : public Material
{
public:
	Metal(const vec3& albedo, float fuzz) : albedo(albedo), fuzzy(fuzz < 1 ? fuzzy = fuzz : fuzzy = 1) {}

	vec3 albedo;
	// Fuzzyness parameter is used to randomly scatter reflections.
	// I think this may be the same as anisotropy (TODO: Research).
	float fuzzy;

	virtual bool scatter(const ray& r_in, const Intersection& record, vec3& attenuation, ray& scattered) const override;
};

// Reflect incoming ray of surface
bool Metal::scatter(const ray& r_in, const Intersection& record, vec3& attenuation, ray& scattered) const
{
	vec3 reflected = reflect(r_in.direction.unitVector(), record.normal);
	scattered = ray(record.p, reflected + fuzzy * Math::randInUnitSphere());
	attenuation = albedo;
	return scattered.direction.dot(record.normal) > 0;
}