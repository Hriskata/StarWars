#pragma once

#include "Jedi.h"
#include <vector>

class Planet {
	std::string name;
	std::vector<Jedi> population;

public:
	// конструктор по подразбиране 
	Planet();
	// конструкто за създаване
	Planet(std::string _name);
	// селектор за името на планетата
	std::string get_Name_of_planet() const;
	// функция за добавяне на джедай на планетата
	void add_Jedi(const Jedi& j);
	// функция за премахване на джедай от планетата
	void remove_Jedi(const Jedi& j);
	// функция за извеждане на населението на планетата
	void print_Planet_population(std::ostream& os = std::cout) const;
};