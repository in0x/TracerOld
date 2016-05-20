#ifndef INTERSECTABLE_LIST_H
#define INTERSECTABLE_LIST_H

#include <vector>

#include "Intersectable.h"

class IntersectableList : public Intersectable
{
public:
	
	virtual bool intersect(const ray& r, float tMin, float tMax, Intersection& intersectOut) override;
	void Add(Intersectable* pObject);

private:
	std::vector<Intersectable*> m_intersectables;
};


bool IntersectableList::intersect(const ray& r, float tMin, float tMax, Intersection& intersectOut)
{
	bool intersected = false;
	double closestSoFar = tMax;

	for (auto& intersectable : m_intersectables)
	{
		if (intersectable->intersect(r, tMin, closestSoFar, intersectOut))
		{
			intersected = true;
			closestSoFar = intersectOut.t;	
		}
	}
	return intersected;
}

void IntersectableList::Add(Intersectable* pObject)
{
	m_intersectables.push_back(pObject);
}

#endif // INTERSECTABLE_LIST_H