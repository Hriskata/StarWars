#include "Jedi.h"

Jedi::Jedi()
{
	name = '\0';
	rank = jedi_rank::YOUNGLING;
	age = 0;
	saber_color = '\0';
	strength = 0.0;
}

Jedi::Jedi(std::string _name, jedi_rank _rank, int _age, std::string _saber_color, double _strength)
{
	name = _name;
	rank = _rank;
	age = _age;
	saber_color = _saber_color;
	strength = _strength;
}

std::string Jedi::get_Name_of_jedi() const
{
	return name;
}

jedi_rank Jedi::get_Rank() const
{
	return rank;
}

int Jedi::get_Age() const
{
	return age;
}

std::string Jedi::get_Saber_color() const
{
	return saber_color;
}

double Jedi::get_Strength() const
{
	return strength;
}

void Jedi::print(std::ostream& os) const
{
	os << "Jedi's name : " << name << std::endl
		<< "Jedi's rank : " << rank << std::endl
		<< "Jedi's age : " << age << std::endl
		<< "Jedi's saber color : " << saber_color << std::endl
		<< "Jedi's strength : " << strength << std::endl;
}
/*
void Jedi::rank_up(Jedi& j)
{
	j.rank = j.get_Rank() + 1;
}
*/
std::ostream& operator<<(std::ostream& out, const Jedi& jedi)
{
	return out << "Jedi's name : " << jedi.get_Name_of_jedi() << std::endl
		<< "Jedi's rank : " << jedi.get_Rank() << std::endl
		<< "Jedi's age : " << jedi.get_Age() << std::endl
		<< "Jedi's saber color : " << jedi.get_Saber_color() << std::endl
		<< "Jedi's strength : " << jedi.get_Strength() << std::endl;
}
