#include "Vec3f.h"
#include <cassert>

void Vec3Test()
{
	vec3 v1(1,1,1);

	assert(v1 == vec3(1,1,1));
	
	assert((v1 += vec3(1,2,1)) == vec3(2,3,2));

	v1 = vec3(1,1,1);

	assert((v1 + v1) == vec3(2,2,2));

	vec3 e1(1,0,0);
	vec3 e3(0,0,1);

	vec3 norm = e1.cross(e3);
	assert(norm == vec3(0,-1,0));

	vec3 large(10, 10, 0);
	vec3 unit = large.unitVector();
	float len = unit.length();
	assert(len <= 1);
}