#pragma once

#include "Planet.h"

class SolarSystem {
	std::vector<Planet> system;

public:
	// ���������� �� ������������
	SolarSystem();

	// ������� �� �������� �� �������
	void add_planet(const Planet& p);
	// ������� �� �������� �� ������
	void create_jedi(std::string planet_name, std::string jedi_name, int jedi_age, std::string jedi_saber, double jedi_strength);
	// ������� �� ���������� �� ������
	// 
	
};