#pragma once

#include "Planet.h"
#include <iterator>

class SolarSystem {
	std::vector<Planet> system;

public:
	// коструктор по подразбиране
	SolarSystem();

	//1) функция за добавяне на планета								++
	void add_planet(std::string _name);
	//2) функция за добавяне на джедай								++
	void create_jedi(std::string _planet_name, std::string _jedi_name, jedi_rank _jedi_rank, int _jedi_age, std::string _jedi_saber, double _jedi_strength, std::ostream& os = std::cout);	
	//3) функция за премахване на джедай							++
	void remove_jedi(std::string _jedi_name, std::string _planet_name);
	//4) финкция за повишаване на джедай							++
	void promote_jedi(std::string _jedi_name, double _multiplier);
	//5) функция за понижаване на джедай							++
	void demote_jedi(std::string _jedi_name, double _multiplier);
	//6) функция за най - силния джедай								++
	void get_strongest_jedi(std::string _planet_name);		
	//7) функция за най - младия джедай								++
	void get_youngest_jedi(std::string _planet_name, jedi_rank _jedi_rank);
	//8) функция за най - разпространения цвят светлинен меч на дадена планета по даден ранг					++
	void get_most_used_saber_color(std::string _planet_name, jedi_rank _jedi_rank);
	//9) функция за най - разпространения цвят светлинен меч на дадена планета с поне един GRAND_MASTER

	//10) функция, която принтира цялата планета					++
	void print_planet(std::string _planet_name);		
	//11) функция, която принтира джедай							++
	void print_Jedi(std::string _jedi_name);
	//12) функция, която извежда информация за две планети			++
	void print_two_planets(std::string _planet_name, std::string _planet_name2);

	void Run();

};
