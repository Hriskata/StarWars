#include "Planet.h"

int main() {
	Jedi j("gosho", YOUNGLING, 15, "red", 15.5);
	//j.print();
	Planet p("zemq");
	p.add_Jedi(j);
	p.print_Planet_population();
	p.remove_Jedi(j);
	p.print_Planet_population();
	return 0;
}