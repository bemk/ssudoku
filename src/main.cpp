
#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "Mesh.h"

int main(int argc __attribute__((unused)), char** argv __attribute__((unused)))
{
	bool verbose = false;
	bool stepped = false;
	bool configured = false;
	int opt = -1;

	do  {
		opt = getopt(argc, argv, "svch");
		switch(opt) {
		case 'c':
			configured = true;
			break;
		case 's':
			stepped = true;
			break;
		case 'v':
			verbose = true;
			break;
		case 'h':
			break;
		default:
			break;
		}
	} while (opt != -1);

	std::vector<Tile> tileTemplate;
	Mesh mesh(tileTemplate, 9, 9);

	if (configured) {
		std::cout << "Ask for data here\n";
	}

	if (stepped) {
		while (!mesh.step(verbose));
	} else {
		mesh.solve(verbose);
	}

	return EXIT_SUCCESS;
}
