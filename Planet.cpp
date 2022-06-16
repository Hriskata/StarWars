#include "Planet.h"

Planet::Planet()
{
	name = '\0';
	population = {};
}

Planet::Planet(std::string _name)
{
	name = _name;
	population = {};
}

std::string Planet::get_Name_of_planet() const
{
	return name;
}

void Planet::add_Jedi(const Jedi& j)
{
	for (int i = 0; i < population.size(); i++)
	{
		if (j.get_Name_of_jedi() == population[i].get_Name_of_jedi())
			throw std::exception("Already exist jedi with that name! ");
	}
	population.push_back(j);
}

void Planet::remove_Jedi(const Jedi& j)
{
	for (int i = 0; i < population.size(); i++)
	{
		if (j.get_Name_of_jedi() == population[i].get_Name_of_jedi())
			population.pop_back();
	}
}

void Planet::print_Planet_population(std::ostream& os) const
{
	os << "Planet's name : " << name << std::endl;
	for (int i = 0; i < population.size(); i++)
	{
		os << population[i] << std::endl;
	}
}
