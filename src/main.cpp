
#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "Mesh.h"
#include "Rules/SudokuRules.h"

int main(int argc, char** argv)
{
	bool verbose = false;
	bool stepped = false;
	bool configured = false;
	bool interactive __attribute__((unused)) = false;
	bool sudoku = false;
	int opt = -1;
	uint32_t seed = 0;

	do  {
		opt = getopt(argc, argv, "osvchig:");
		switch(opt) {
		case 'c':
			configured = true;
			break;
		case 'o':
			stepped = true;
			break;
		case 's':
			sudoku = true;
			break;
		case 'v':
			verbose = true;
			break;
		case 'h':
			break;
		case 'i':
			interactive = true;
			break;
		case 'g':
			seed = stoi(std::string(optarg));
		default:
			break;
		}
	} while (opt != -1);

	std::mt19937 randomGenerator (seed);
	std::vector<Rules::TileRule*> ruleTemplate;
	std::vector<Tile> tileTemplate;
	if (sudoku) {
		ruleTemplate.push_back(new Rules::Sudoku::UniqueInColumn());
		ruleTemplate.push_back(new Rules::Sudoku::UniqueInRow());
		ruleTemplate.push_back(new Rules::Sudoku::UniqueInSquare());

		tileTemplate.push_back(Tile("1", ruleTemplate));
		tileTemplate.push_back(Tile("2", ruleTemplate));
		tileTemplate.push_back(Tile("3", ruleTemplate));
		tileTemplate.push_back(Tile("4", ruleTemplate));
		tileTemplate.push_back(Tile("5", ruleTemplate));
		tileTemplate.push_back(Tile("6", ruleTemplate));
		tileTemplate.push_back(Tile("7", ruleTemplate));
		tileTemplate.push_back(Tile("8", ruleTemplate));
		tileTemplate.push_back(Tile("9", ruleTemplate));
	}
	Mesh mesh(tileTemplate, 9, 9, randomGenerator);

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
