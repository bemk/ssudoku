
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
	size_t x = 0;
	size_t y = 0;

	void markSelected();

public:
	TileSpace(const std::vector<Tile>& possibilities, Mesh* mesh);
	bool selectionMade();
	bool applyRules();
	void print(std::stringstream& stream);
	void printFull(std::stringstream& stream);
	void setLocation(size_t x, size_t y);
	std::tuple<size_t, size_t> getLocation();
	Tile getTile();
	bool makeSelection(Tile& tile);
	bool makeFirstSelection();
	bool makeRandomSelection(std::mt19937& generator);
};

#endif
