#pragma once
	
#include <iostream>
#include <string>
#include <cstring>

enum jedi_rank  {YOUNGLING = 0, INITIAT = 1, PADAWAN = 2, KNIGHT_ASPIRANT = 3, KNIGHT = 4, MASTER = 5, BATTLE_MASTER = 6, GRAND_MASTER = 7};
/*
		switch (rank)
	{
	case YOUNGLING: os << "YOUNGLING";    break;
	case INITIAT: os << "INITIAT"; break;
	case PADAWAN: os << "PADAWAN";  break;
	case KNIGHT_ASPIRANT: os << "KNIGHT_ASPIRANT";   break;
	case KNIGHT: os << "KNIGHT";   break;
	case MASTER: os << "MASTER";   break;
	case BATTLE_MASTER: os << "BATTLE_MASTER";   break;
	case GRAND_MASTER: os << "GRAND_MASTER";   break;
	}
	return os;
}
*/
class Jedi {
	std::string name;
	jedi_rank rank;
	int age;
	std::string saber_color;
	double strength;

public:
	// ����������� �� ������������
	Jedi();
	// ����������� �� ��������� �� ������
	Jedi(std::string _name, jedi_rank _rank, int _age, std::string _saber_color, double _strength);

	// �������� �� ����� �� ������
	std::string get_Name_of_jedi() const;
	// �������� �� ����� �� ������
	jedi_rank get_Rank() const;
	// �������� �� ��������� �� ������
	int get_Age() const;
	// �������� �� ����� �� ��������� �� ������
	std::string get_Saber_color() const;
	// �������� �� ������ �� ������
	double get_Strength() const;

	// ������� �� ��������� �� ������������ �� ������
	void print(std::ostream& os = std::cout) const;
	// ������� �� ���������� �� �����
	void rank_up(Jedi& j);

};	
// �������� �� ���������
std::ostream& operator<<(std::ostream&, const Jedi&);