#pragma once

#include "Jedi.h"
#include <vector>

class Planet {
	std::string name;
	std::vector<Jedi> population;

public:
	// ����������� �� ������������ 
	Planet();
	// ���������� �� ���������
	Planet(std::string _name);
	// �������� �� ����� �� ���������
	std::string get_Name_of_planet() const;
	// ������� �� �������� �� ������ �� ���������
	void add_Jedi(const Jedi& j);
	// ������� �� ���������� �� ������ �� ���������
	void remove_Jedi(const Jedi& j);
	// ������� �� ��������� �� ����������� �� ���������
	void print_Planet_population(std::ostream& os = std::cout) const;
};