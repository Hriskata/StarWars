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

size_t Planet::get_Population_size() const
{
	return population.size();
}

std::vector<Jedi> Planet::get_Vector() const
{
	return population;
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
			population.erase(population.begin() + i);
	}
}

void Planet::stronger_Jedi()
{
	double strongest_power = 0;
	for (int i = 0; i < population.size(); i++)
	{
		if (population[i].get_Strength() > strongest_power)
			strongest_power = population[i].get_Strength();
	}		
	for (int i = 0; i < population.size(); i++)
	{
		if (strongest_power == population[i].get_Strength())
			population[i].print();
	}
}

void Planet::youngest_Jedi()
{
	int youngest = INT_MAX;
	int counter = 0;
	for (int i = 0; i < population.size(); i++)
	{
		if (population[i].get_Age() <= youngest)
		{
			youngest = population[i].get_Age();
			counter++;
		}
	}
	if (counter == 0)
		throw std::exception("There is no population!");

	if (counter > 1)
	{
		for (int i = 0; i < population.size(); i++)
		{
			if (youngest == population[i].get_Age())
			{
				for (int j = i + 1; j < population.size(); j++)
				{
					if (youngest == population[j].get_Age() && (population[i].get_Name_of_jedi() > population[j].get_Name_of_jedi()))
					{
						std::swap(population[i], population[j]);
					}
				}
			}
		}
	}
	
	for (int i = 0; i < population.size(); i++)
	{
		if (youngest == population[i].get_Age())
			population[i].print();
	}
}

void Planet::print_Planet_name(std::ostream& os)
{
	os << "Planet's name : " << name << std::endl;
}

void Planet::print_Planet_population(std::ostream& os)
{
	os << "Planet's name : " << name << std::endl;
	for (int i = 0; i < population.size(); i++)
	{
		for (int j = i + 1; j < population.size(); j++)
		{
			if (population[i].get_Rank() > population[j].get_Rank())
			{
				std::swap(population[i], population[j]);
			}
			if (population[i].get_Rank() == population[j].get_Rank() && (population[i].get_Name_of_jedi() > population[j].get_Name_of_jedi()))
			{
				std::swap(population[i], population[j]);
			}
		}
	}

	for (int i = 0; i < population.size(); i++)
	{
		os << population[i] << std::endl;
	}
}
