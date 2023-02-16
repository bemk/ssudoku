
#ifndef TILE_H
#define TILE_H

#include <sstream>
#include <vector>
#include <tuple>

#include "TileRule.h"
#include "Mesh.h"

class Mesh;

class Tile {
private:
	std::string typeName;
	std::vector<TileRule> rules;
	std::tuple<size_t, size_t> location = {0,0};

	Mesh* mesh;
public:
	Tile(std::string typeName, std::vector<TileRule>& rules, Mesh* mesh);
	void toText(std::stringstream& stream);
	bool checkValidity();

	void setLocation(size_t x, size_t y);
};

#endif
