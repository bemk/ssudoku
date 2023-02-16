
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
	size_t x = 0;
	size_t y = 0;

	Mesh* mesh;
public:
	Tile(std::string typeName, std::vector<TileRule>& rules, Mesh* mesh);
	void toText(std::stringstream& stream);
	bool checkValidity();

	void setLocation(size_t x, size_t y);
};

#endif
