
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>

#include "Mesh.h"
#include "Rules/SudokuRules.h"
#include "Input/Parser.h"
#include "Sudoku.h"

static void printHelp(std::string program, int code)
{
	std::cout << program << " usage\n";
	std::cout << 
"\n\
 -h\t\tPrint this help\n\
 -s\t\tPrepare sudoku tiles and rules\n\
 -i [file]\tUse a script to prepare the mesh\n\
 -m\t\tStart an interpreter (not yet implemented)\n\
 -v\t\tVerbose output\n\
 -r\t\tSelect a Random tile when multiple paths are available\n\
 \t\tThe default behaviour is to select the first available option and iterate\n\
 -g [seed]\tSeed for the random generator\n";

	exit(code);
}

int main(int argc, char** argv)
{
	bool verbose = false;
	bool sudoku = false;
	bool makeRandomSelection = false;
	std::string scriptName = "";
	int opt = -1;

	uint32_t seed = 0;

	do  {
		opt = getopt(argc, argv, "svhg:i:mr");
		switch(opt) {
		case 's':
			sudoku = true;
			break;
		case 'v':
			verbose = true;
			break;
		case 'i':
			scriptName = std::string(optarg);
			break;
		case 'h':
			printHelp(std::string(argv[0]), 0);
			break;
		case 'g':
			seed = stoi(std::string(optarg));
			break;
		case 'm':
			std::cout << "Argument not yet implemented!\n";
			printHelp(std::string(argv[0]), -1);
			break;
		case 'r':
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
		ruleTemplate = sudokuRules();
		tileTemplate = sudokuTemplate(ruleTemplate);
	}

	Mesh mesh(tileTemplate, makeRandomSelection, 9, 9, randomGenerator);

	std::vector<std::string> script;
	if (scriptName != "") {
		std::ifstream scriptFile(scriptName);

		std::string line = "";
		while (std::getline(scriptFile, line)) {
			script.push_back(line);
		}
	} else if (sudoku) {
		script = sudokuScript();
	}

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
