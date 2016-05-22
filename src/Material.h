#pragma once

#include "Intersectable.h"

class Material
{
public:
	virtual ~Material() = default;
	virtual bool scatter(const ray& r_in, const Intersection& record, vec3& attenuation, ray& scattered) const = 0;
};