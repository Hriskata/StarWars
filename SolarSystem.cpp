#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	system = {};
}

void SolarSystem::add_planet(std::string _name)
{
	for (int i = 0; i < system.size(); i++)
	{
		if (_name == system[i].get_Name_of_planet())
			throw std::exception("Already exist planet with that name!");
	}
	Planet p(_name);
	system.push_back(p);
}

void SolarSystem::create_jedi(std::string _planet_name, std::string _jedi_name, jedi_rank _jedi_rank, int _jedi_age, std::string _jedi_saber, double _jedi_strength, std::ostream& os)
{
	// флаг за успешно добавен джедай : 0 - не е добавен, 1 - е добавен
	int flag = 0;
	for (int i = 0; i < system.size(); i++)
	{
		for (int j = 0; j < system[i].get_Population_size(); j++)
		{
			if (system[i].get_Vector()[j].get_Name_of_jedi() == _jedi_name)
			{
				throw std::exception("There is already a Jedi with that name!");
			}
		}
	}

	for (int i = 0; i < system.size(); i++)
	{
		if (_planet_name == system[i].get_Name_of_planet())
		{
			Jedi j(_jedi_name, _jedi_rank, _jedi_age, _jedi_saber, _jedi_strength);
			system[i].get_Vector().push_back(j);
			flag = 1;
			os << "Successfully created and added Jedi!";
		}
		
	}
	if (flag == 0)
		throw std::exception("There is no planet with that name");
}

void SolarSystem::remove_jedi(std::string _jedi_name, std::string _planet_name)
{
	// pyrvo proverqvam dali ima planeta s tova ime
	int flag_planet = 0;
	int flag_jedi = 0;
	for (int i = 0; i < system.size(); i++)
	{
		if (_planet_name == system[i].get_Name_of_planet())
		{
			flag_planet = 1;
			// posle proverqvame dali ima djedai s tova ime
			for (int j = 0; j < system[i].get_Population_size(); j++)
			{
				if (system[i].get_Vector()[j].get_Name_of_jedi() == _jedi_name)
				{
					system[i].get_Vector().erase(system[i].get_Vector().begin() + i);
					flag_jedi = 1;
					std::cout << "Successfully removed Jedi!";
				}
			}
		}
	}

	if(flag_planet == 0)
		throw std::exception("There is no planet with that name");
	else if(flag_jedi == 0)
			throw std::exception("There is no jedi with that name");
}

void SolarSystem::promote_jedi(std::string _jedi_name, double _multiplier)
{
	if (_multiplier <= 0)
		throw std::exception("Multiplier must be a positive number!");
	
	for (int i = 0; i < system.size(); i++)
	{
		for (int j = 0; j < system[i].get_Vector().size(); j++)
		{
			if (_jedi_name == system[i].get_Vector()[j].get_Name_of_jedi())
			{
				system[i].get_Vector()[j].rank_up(system[i].get_Vector()[j]);
				_multiplier += 1;
				system[i].get_Vector()[j].set_Strenth(_multiplier);
			}
		}
	}
}

void SolarSystem::demote_jedi(std::string _jedi_name, double _multiplier)
{
	if (_multiplier <= 0)
		throw std::exception("Multiplier must be a positive number!");
	for (int i = 0; i < system.size(); i++)
	{
		for (int j = 0; j < system[i].get_Vector().size(); j++)
		{
			if (_jedi_name == system[i].get_Vector()[j].get_Name_of_jedi())
			{
				system[i].get_Vector()[j].rank_up(system[i].get_Vector()[j]);
				_multiplier = 1 - _multiplier;
				system[i].get_Vector()[j].set_Strenth(_multiplier);
			}
		}
	}
}

void SolarSystem::get_strongest_jedi(std::string _planet_name)
{
	int flag_planet = 0;
	for (int i = 0; i < system.size(); i++)
	{
		if (_planet_name == system[i].get_Name_of_planet())
		{
			flag_planet = 1;
			for (int j = 0; j < system[i].get_Population_size(); j++)
			{
				system[i].stronger_Jedi();
			}
		}
	}
	if(flag_planet == 0)
		throw std::exception("There is no planet with that name");
}

void SolarSystem::get_youngest_jedi(std::string _planet_name, jedi_rank _jedi_rank)
{
	int counter_of_jedi = 0;
	int flag_planet = 0;
	for (int i = 0; i < system.size(); i++)
	{
		if (_planet_name == system[i].get_Name_of_planet())
		{
			flag_planet = 1;
			for (int j = 0; j < system[i].get_Population_size(); j++)
			{
				if (_jedi_rank == system[i].get_Vector()[j].get_Rank())
				{
					system[i].youngest_Jedi();
					counter_of_jedi++;
				}
			}
		}
	}
	if (flag_planet == 0)
		throw std::exception("There is no planet with that name!");
	else if (counter_of_jedi == 0)
		throw std::exception("There are no Jedi on this planet since this rank!");
}

void SolarSystem::get_most_used_saber_color(std::string _planet_name, jedi_rank _jedi_rank)
{
	// променлива, която ми помни най-често срещания цвят меч
	int index_most = 0;
	// променлива, която помни индекса на планета от вектора 
	int index_planet = 0;
	// променлива, която ми помни колко са на брой най-често срещания цвят меч 
	int counter_most = 0;
	// променлива за текущия цвят
	int counter_temp = 1;
	std::string temp_color;
	//цикъл за намиране на планетата
	for (int i = 0; i < system.size(); i++)
	{
		if (_planet_name == system[i].get_Name_of_planet() )
		{
			index_planet = i;
			// обхождане за най - често срещания
			for (int j = 0; j < system[i].get_Vector().size(); j++)
			{
				if (_jedi_rank == system[i].get_Vector()[j].get_Rank() )
				{
					counter_temp = 1;
					temp_color == system[i].get_Vector()[j].get_Saber_color();
					for (int k = j + 1; k < system[i].get_Vector().size(); k++)
					{
						if (temp_color == system[i].get_Vector()[k].get_Saber_color() )
						{
							counter_temp++;
						}
					}
					if (counter_most < counter_temp)
					{
						counter_most = counter_temp;
						index_most = j;
					}
				}
			}
		}
	}
	std::cout << system[index_planet].get_Vector()[index_most].get_Saber_color() << std::endl;
}

 void SolarSystem::print_planet(std::string _planet_name)
{
	 int flag_planet = 0;
	 for (int i = 0; i < system.size(); i++)
	 {
		 if (_planet_name == system[i].get_Name_of_planet())
		 {
			 system[i].print_Planet_population();
			 flag_planet = 1;
		 }
	 }
	 if (flag_planet == 0)
		 throw std::exception("There is no planet with that name!");
}

void SolarSystem::print_Jedi(std::string _jedi_name)
{
	int flag_jedi = 0;
	for (int i = 0; i < system.size(); i++)
	{
		for (int j = 0; j < system[i].get_Vector().size(); j++)
		{
			if (_jedi_name == system[i].get_Vector()[j].get_Name_of_jedi())
			{
				system[i].print_Planet_name();
				system[i].get_Vector()[j].print();
				flag_jedi = 1;
			}
		}
	}
	if (flag_jedi == 0)
		throw std::exception("There is no Jedi with that name!");
}

void SolarSystem::print_two_planets(std::string _planet_name1, std::string _planet_name2)
{
	int index1 = 0;
	int flag_planet1 = 0;
	int index2 = 0;
	int flag_planet2 = 0;
	for (int i = 0; i < system.size(); i++)
	{
		if (_planet_name1 == system[i].get_Name_of_planet())
		{
			index1 = i;
			flag_planet1 = 1;
		}
		if (_planet_name2 == system[i].get_Name_of_planet())
		{
			index2 = i;
			flag_planet2 = 1;
		}
	}

	if (flag_planet1 == 0)
		throw std::exception("There is no planet with that name!");
	if (flag_planet2 == 0)
		throw std::exception("There is no planet with that name!");

	for (int i = 0; i < system[index1].get_Vector().size(); i++)
	{
		for (int j = 0; j < system[index2].get_Vector().size(); j++)
		{
			if (system[index1].get_Vector()[i].get_Name_of_jedi() <
				system[index2].get_Vector()[j].get_Name_of_jedi())
			{
				system[index1].get_Vector()[i].print();
				break;
			}
			else system[index2].get_Vector()[j].print();
		}
	}
}

void SolarSystem::Run()
{
	std::string command;
	std::cout << "Welcome!" << std::endl;
	do
	{

		std::cout << "please enter <help> to see possible commands" << std::endl;
		std::cin >> command;

		if (command == "help") {
			std::cout << "The following commands are supported : " << std::endl;
			std::cout << "open <file>								-> open <file> " << std::endl;
			std::cout << "close										-> closes currently opened file " << std::endl;
			std::cout << "save										-> saves the currently open file" << std::endl;
			std::cout << "save										-> saves the currently open file" << std::endl;
			std::cout << "saveas <file>								-> saves the currently open file in <file>" << std::endl;
			std::cout << "help										-> prints this information" << std::endl;
			std::cout << "exit										-> exists the program" << std::endl;
			std::cout << "add_planet <planet_name>					-> add new planet " << std::endl;
			std::cout << "create_jedi <planet_name> < jedi_name > <jedi_rank> <jedi_age> <saber_color> <jedi_strength> -> create a new Jedi " << std::endl;
			std::cout << "removeJedi <jedi_name> <planet_name>		-> removes Jedi by <rank> and <planet name> " << std::endl;
			std::cout << "promote_jedi <jedi_name> <multiplier>		-> promotes Jedi by <name> and increase strength " << std::endl;
			std::cout << "demote_jedi <jedi_name> <multiplier>		-> demotes Jedi by <name> and increase strength " << std::endl;
			std::cout << "get_strongest_jedi < planet_name>			-> return strongest Jedi by <planet> " << std::endl;
			std::cout << "get_youngest_jedi <planet_name><jedi_rank>-> return youngest Jedi by <planet> and <rank> " << std::endl;
			std::cout << "get_most_used_saber_color <planet_name> <jedi_rank> -> return most used saber color by <planet> and <rank> " << std::endl;
			std::cout << "get_most_used_saber_color <planet_name>	-> return most used saber color by <planet> and at least one GRAND_MASTER " << std::endl;
			std::cout << "print_planet <planet_name>				-> print information about <planet>" << std::endl;
			std::cout << "print_Jedi <jedi_name>					-> print information about <jedi>" << std::endl;
			std::cout << "print_two_planets <planet_name> < planet_name >	-> print sorted information about two <planets> " << std::endl;
		}
		else if (command == "open")
		{

		}
		else if (command == "save")
		{

		}
		else if (command == "saveas")
		{

		}
		else if (command == "open")
		{

		}
		else if (command == "exit")
		{
			break;
		}
		else if (command == "add_planet") //1
		{
			std::cout << "Please enter a name for the new planet: " << std::endl;
			std::string currName;
			std::cin >> currName;
			Planet currPlanet(currName);
			system.push_back(currPlanet);
		}
		else if (command == "create_jedi") //2
		{
			std::string currPlan;
			std::cin >> currPlan;
			std::string currName;
			std::cin >> currName;
			jedi_rank currRank = YOUNGLING;
			//std::cin >> currRank;
			int currAge;
			std::cin >> currAge;
			std::string currColor;
			std::cin >> currColor;
			double currStreangth;
			std::cin >> currStreangth;
			Jedi j(currName, currRank, currAge, currColor, currStreangth);
			for (int i = 0; i < system.size(); i++)
			{
				if (currPlan == system[i].get_Name_of_planet())
				{
					system[i].add_Jedi(j);
				}
			}
		}
		else if (command == "removejedi") //3
		{
			std::string currName;
			std::cin >> currName;
			std::string currPlan;
			std::cin >> currPlan;
			for (int i = 0; i < system.size(); i++) {
				if (currPlan == system[i].get_Name_of_planet())
				{
					for (int j = 0; j < system[i].get_Vector().size(); j++)
					{
						if (currName == system[i].get_Vector()[j].get_Name_of_jedi())
							system[i].remove_Jedi(system[i].get_Vector()[j]);
					}
				}
			}
		}
		else if (command == "promote_jedi") //4
		{
			std::string currName;
			std::cin >> currName;
			double currMulti;
			std::cin >> currMulti;
			for (int i = 0; i < system.size(); i++) 
			{
				for (int j = 0; j < system[i].get_Vector().size(); j++)
				{
					if (currName == system[i].get_Vector()[j].get_Name_of_jedi())
						promote_jedi(currName, currMulti);
				}
			}
		}
		else if (command == "demote_jedi") //5
		{
			std::string currName;
			std::cin >> currName;
			double currMulti;
			std::cin >> currMulti;
			for (int i = 0; i < system.size(); i++)
			{
				for (int j = 0; j < system[i].get_Vector().size(); j++)
				{
					if (currName == system[i].get_Vector()[j].get_Name_of_jedi())
						demote_jedi(currName, currMulti);
				}	
			}
		}
		else if (command == "get_strongest_jedi") //6
		{
			std::string currPlan;
			std::cin >> currPlan;
			for (int i = 0; i < system.size(); i++)
			{
				if (currPlan == system[i].get_Name_of_planet())
				{
					get_strongest_jedi(currPlan);
				}
			}
		}
		else if (command == "get_youngest_jedi") //7
		{
			break;
		}
		else if (command == "get_most_used_saber_color") //8
		{
			break;
		}
		else if (command == "print_planet") //10
		{
			std::string currPlan;
			std::cin >> currPlan;
			print_planet(currPlan);
		}
		else if (command == "print_Jedi") //11
		{
			std::string currName;
			std::cin >> currName;
			print_Jedi(currName);
		}
		else if (command == "print_two_planets") //12
		{
			std::string currPlan;
			std::cin >> currPlan;
			std::string currPlan2;
			std::cin >> currPlan2;
			print_two_planets(currPlan, currPlan2);
		}
		else std::cout << "please enter <help> to see possible commands" << std::endl;

	} while (command != "exit");
}
