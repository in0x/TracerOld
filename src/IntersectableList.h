#pragma once

#include <vector>
#include <memory>

#include "Intersectable.h"

class IntersectableList : public Intersectable
{
public:
	
	virtual bool intersect(const ray& r, float tMin, float tMax, Intersection& intersectOut) override;
	void Add(std::unique_ptr<Intersectable> pObject);

private:
	std::vector<std::unique_ptr<Intersectable>> m_intersectables;
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

void IntersectableList::Add(std::unique_ptr<Intersectable> pObject)
{
	m_intersectables.push_back(std::move(pObject));
}