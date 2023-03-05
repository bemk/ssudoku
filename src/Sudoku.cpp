
#include "Sudoku.h"
#include "Rules/SudokuRules.h"
#include "Rules/TileRule.h"
#include "TileSpace.h"
#include <vector>

std::vector<Rules::TileRule*> sudokuRules()
{
	std::vector<Rules::TileRule*> ruleTemplate;
	ruleTemplate.push_back(new Rules::Sudoku::UniqueInColumn());
	ruleTemplate.push_back(new Rules::Sudoku::UniqueInRow());
	ruleTemplate.push_back(new Rules::Sudoku::UniqueInSquare());
	return ruleTemplate;

}
std::vector<Tile> sudokuTemplate(std::vector<Rules::TileRule*> ruleTemplate)
{
	std::vector<Tile> tileTemplate;

	tileTemplate.push_back(Tile("1", ruleTemplate));
	tileTemplate.push_back(Tile("2", ruleTemplate));
	tileTemplate.push_back(Tile("3", ruleTemplate));
	tileTemplate.push_back(Tile("4", ruleTemplate));
	tileTemplate.push_back(Tile("5", ruleTemplate));
	tileTemplate.push_back(Tile("6", ruleTemplate));
	tileTemplate.push_back(Tile("7", ruleTemplate));
	tileTemplate.push_back(Tile("8", ruleTemplate));
	tileTemplate.push_back(Tile("9", ruleTemplate));
	return tileTemplate;
}

std::vector<std::string> sudokuScript()
{
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
	return script;
}