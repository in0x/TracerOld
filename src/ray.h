#pragma once

#include "Vec3f.h"

class ray
{
public:
	ray() {}
	ray( const vec3& origin, const vec3& direction ) : A( origin ), B( direction ) {}
	
	// Public member functions

	vec3 origin() const
	{
		return A;
	}

	vec3 direction() const
	{
		return B;
	}

	vec3 pointAtParam( float t ) const
	{
		return A + t * B;
	}

private:
	// Private members

	vec3 A;
	vec3 B;
};
