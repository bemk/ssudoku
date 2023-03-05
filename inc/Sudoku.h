
#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
#include <vector>
#include "Rules/TileRule.h"
#include "Tile.h"

std::vector<Rules::TileRule*> sudokuRules();
std::vector<Tile> sudokuTemplate(std::vector<Rules::TileRule*> ruleTemplate);
std::vector<std::string> sudokuScript();

#endif
