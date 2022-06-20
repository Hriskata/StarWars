#include "SolarSystem.h"

int main() {
	SolarSystem s;
	Jedi j("pesho", YOUNGLING, 15, "red", 15.5);
	Jedi j2("ivan", GRAND_MASTER, 20, "blue", 55.5);
	Jedi j3("gosho", GRAND_MASTER, 15, "green",155.5);
	//j.print();
	//j2.rank_up(j2);
	//j.print();
	Planet p("zemq");

	s.add_planet("mars");
	p.add_Jedi(j);
	p.add_Jedi(j2);
	p.add_Jedi(j3);
	//p.print_Planet_population();
	//p.remove_Jedi(j);
	//p.print_Planet_population();
	//p.stronger_Jedi();
	//p.youngest_Jedi();

	

	return 0;
}
