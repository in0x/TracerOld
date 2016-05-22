#pragma once

#include "Vec3f.h"

class ray
{
public:
	ray() {}
	ray( const vec3& origin, const vec3& direction ) : origin( origin ), direction( direction ) {}
	
	vec3 origin;
	vec3 direction;

	vec3 pointAtParam( float t ) const
	{
		return origin + t * direction;
	}
};
