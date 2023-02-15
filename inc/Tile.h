
#ifndef TILE_H
#define TILE_H

#include <sstream>
#include <vector>

#include "TileRule.h"

class Tile {
private:
	std::string typeName;
	std::vector<TileRule> rules;
public:
	Tile(std::string typeName, std::vector<TileRule>& rules);
	void toText(std::stringstream& stream);
	bool checkValidity();
};

#endif
