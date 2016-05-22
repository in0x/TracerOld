#include <ctime>

#include "MathUtil.h"

namespace Math
{
	std::default_random_engine rng(time(nullptr));
	std::uniform_real_distribution<double> distrib(0.0, 1.0);

	vec3 Math::randInUnitSphere()
	{
		vec3 point;
		vec3 one = vec3(1, 1, 1);
		do
		{
			point = 2.f * vec3(distrib(rng), distrib(rng), distrib(rng)) - one;
		} while (point.length2() >= 1.f);

		return point;
	}

	double Math::getRandom()
	{
		return distrib(rng);
	}
}