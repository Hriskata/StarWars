#pragma once
	
#include <iostream>
#include <string>
#include <cstring>

enum jedi_rank {YOUNGLING = 0, INITIAT = 1, PADAWAN = 2, KNIGHT_ASPIRANT = 3, KNIGHT = 4, MASTER = 5, BATTLE_MASTER = 6, GRAND_MASTER = 7};

class Jedi {
	std::string name;
	jedi_rank rank;
	int age;
	std::string saber_color;
	double strength;

public:
	// конструктор по подразбиране
	Jedi();
	// конструктор за създаване на джедай
	Jedi(std::string _name, jedi_rank _rank, int _age, std::string _saber_color, double _strength);

	// селектор за името на джедая
	std::string get_Name_of_jedi() const;
	// селектор за ранга на джедая
	jedi_rank get_Rank(std::ostream& os = std::cout) const;
	// селектор за възрастта на джедая
	int get_Age() const;
	// селектор за цвета на светлиния на джедая
	std::string get_Saber_color() const;
	// селектор за силата на джедая
	double get_Strength() const;

	// мутатор за силата на джедая
	void set_Strenth(double x);

	// функция за извеждане на информацията на джедая
	void print(std::ostream& os = std::cout) const;
	// функция за повишаване на ранга
	void rank_up(Jedi& j);
	// функция за понижаване на ранга
	void rank_down(Jedi& j);
	
};	
// оператор за извеждане
std::ostream& operator<<(std::ostream&, const Jedi&);
