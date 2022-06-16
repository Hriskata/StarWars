#pragma once

#include "Planet.h"

class SolarSystem {
	std::vector<Planet> system;

public:
	// коструктор по подразбиране
	SolarSystem();

	// функция за добавяне на планета
	void add_planet(const Planet& p);
	// функция за добавяне на джедай
	void create_jedi(std::string planet_name, std::string jedi_name, int jedi_age, std::string jedi_saber, double jedi_strength);
	// функция за премахване на джедай
	// 
	
};