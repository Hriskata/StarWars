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

jedi_rank Jedi::get_Rank(std::ostream& os) const
{
	/*
	switch (rank)
	{
	case YOUNGLING: std::cout << "YOUNGLING";    break;
	case INITIAT: os << "INITIAT"; break;
	case PADAWAN: os << "PADAWAN";  break;
	case KNIGHT_ASPIRANT: os << "KNIGHT_ASPIRANT";   break;
	case KNIGHT: os << "KNIGHT";   break;
	case MASTER: os << "MASTER";   break;
	case BATTLE_MASTER: os << "BATTLE_MASTER";   break;
	case GRAND_MASTER: os << "GRAND_MASTER";   break;
	}
	return rank;
	*/
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

void Jedi::set_Strenth(double x)
{
	strength = strength * x;
}

void Jedi::print(std::ostream& os) const
{
	os << "Jedi's name : " << name << std::endl
		<< "Jedi's rank : " << rank << std::endl
		<< "Jedi's age : " << age << std::endl
		<< "Jedi's saber color : " << saber_color << std::endl
		<< "Jedi's strength : " << strength << std::endl;
}

void Jedi::rank_up(Jedi& j)
{
	if (j.get_Rank() == 0)
		j.rank = jedi_rank::INITIAT;
	else if (j.get_Rank() == 1)
		j.rank = jedi_rank::PADAWAN;
	else if (j.get_Rank() == 2)
		j.rank = jedi_rank::KNIGHT_ASPIRANT;
	else if (j.get_Rank() == 3)
		j.rank = jedi_rank::KNIGHT;
	else if (j.get_Rank() == 4)
		j.rank = jedi_rank::MASTER;
	else if (j.get_Rank() == 5)
		j.rank = jedi_rank::BATTLE_MASTER;
	else if (j.get_Rank() == 6)
		j.rank = jedi_rank::GRAND_MASTER;
	else std::cout << "This Jedi is already the highest rank!"<<std::endl;

}

void Jedi::rank_down(Jedi& j)
{
	if (j.get_Rank() == 1)
		j.rank = jedi_rank::YOUNGLING;
	else if (j.get_Rank() == 2)
		j.rank = jedi_rank::INITIAT;
	else if (j.get_Rank() == 3)
		j.rank = jedi_rank::PADAWAN;
	else if (j.get_Rank() == 4)
		j.rank = jedi_rank::KNIGHT_ASPIRANT;
	else if (j.get_Rank() == 5)
		j.rank = jedi_rank::KNIGHT;
	else if (j.get_Rank() == 6)
		j.rank = jedi_rank::MASTER;
	else if (j.get_Rank() == 7)
		j.rank = jedi_rank::BATTLE_MASTER;
	else std::cout<<"This Jedi is already the lowest rank!"<<std::endl;
}

std::ostream& operator<<(std::ostream& out, const Jedi& jedi)
{
	return out << "Jedi's name : " << jedi.get_Name_of_jedi() << std::endl
		<< "Jedi's rank : " << jedi.get_Rank() << std::endl
		<< "Jedi's age : " << jedi.get_Age() << std::endl
		<< "Jedi's saber color : " << jedi.get_Saber_color() << std::endl
		<< "Jedi's strength : " << jedi.get_Strength() << std::endl << std::endl;
}
