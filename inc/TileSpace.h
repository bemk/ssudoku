
#ifndef TILE_SPACE_H
#define TILE_SPACE_H

#include <vector>
#include <tuple>
#include "Tile.h"
#include "Mesh.h"

class Mesh;
class Tile;

class TileSpace {
private:
	std::vector<Tile> options;
	bool selected = false;

	Mesh* mesh;
	std::tuple<size_t, size_t> location = {0,0};

	void markSelected();

public:
	TileSpace(const std::vector<Tile>& possibilities, Mesh* mesh);
	bool selectionMade();
	void applyRules();
	void print(std::stringstream& stream);
	void setLocation(size_t x, size_t y);
};

#endif
