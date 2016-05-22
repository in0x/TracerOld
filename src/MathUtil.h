#pragma once

#include <random>
#include <cmath>

#include "Vec3f.h"
#include "ray.h"

namespace Math
{
	extern std::default_random_engine rng;
	extern std::uniform_real_distribution<double> distrib;

	// Pick a random point with -1 <= x,y,z < 1, reject it if 
	// magnitude > 1 (outside of unit sphere)
	vec3 randInUnitSphere();
	double getRandom();
};