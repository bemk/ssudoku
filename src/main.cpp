
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>

#include "Mesh.h"
#include "Rules/SudokuRules.h"
#include "Input/Parser.h"

static void printHelp(std::string program, int code)
{
	std::cout << program << " usage\n";
	std::cout << 
"\n\
 -h\tPrint this help\n\
 -s\tGenerate a sudoku\n\
 -v\tVerbose output\n\
 -g [seed]\tSeed for the random generator\n";

	exit(code);
}

int main(int argc, char** argv)
{
	bool verbose = false;
	bool sudoku = false;
	int opt = -1;
	uint32_t seed = 0;

	do  {
		opt = getopt(argc, argv, "svhg:");
		switch(opt) {
		case 's':
			sudoku = true;
			break;
		case 'v':
			verbose = true;
			break;
		case 'h':
			printHelp(std::string(argv[0]), 0);
			break;
		case 'g':
			seed = stoi(std::string(optarg));
			break;
		case -1:
			break;
		default:
			printHelp(std::string(argv[0]), -1);
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

	std::vector<std::string> script;
	script.push_back("c1 = 3");
	script.push_back("b1 = 9");
	script.push_back("b2 = 8");
	script.push_back("a3 = 7");
	script.push_back("e2 = 5");
	script.push_back("d3 = 8");
	script.push_back("i1 = 2");
	script.push_back("h3 = 4");
	script.push_back("i3 = 9");
	script.push_back("c5 = 6");
	script.push_back("a6 = 9");
	script.push_back("d6 = 5");
	script.push_back("f5 = 3");
	script.push_back("g4 = 1");
	script.push_back("h6 = 7");
	script.push_back("i6 = 8");
	script.push_back("c7 = 9");
	script.push_back("a9 = 1");
	script.push_back("e7 = 6");
	script.push_back("d8 = 4");
	script.push_back("h7 = 1");
	script.push_back("i7 = 4");
	script.push_back("g8 = 2");
	script.push_back("g9 = 5");

	if (verbose) {
		script.push_back("run verbose");
	} else {
		script.push_back("run");
	}
	Input::Parser parser (script);
	parser.run(mesh);

	for (Rules::TileRule* r : ruleTemplate) {
		delete r;
	}

	return EXIT_SUCCESS;
}
