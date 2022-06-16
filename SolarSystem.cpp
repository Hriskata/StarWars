#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	system = {};
}

void SolarSystem::add_planet(const Planet& p)
{
	for (int i = 0; i < system.size(); i++)
	{
		if (p.get_Name_of_planet() == system[i].get_Name_of_planet())
			throw std::exception("Already exist planet with that name!");
	}
	system.push_back(p);
}
