
#ifndef TILE_SPACE_H
#define TILE_SPACE_H

#include <vector>
#include <tuple>
#include <random>
#include "Tile.h"

class Mesh;

enum TileSolveState {
	NOTHING_TO_SOLVE,
	TILES_SOLVED,
	ALL_SOLVED,
	UNSOLVABLE,
};

class TileSpace {
private:
	std::vector<Tile> options;
	bool selected = false;

	size_t x = 0;
	size_t y = 0;

	void markSelected();

public:
	TileSpace(const std::vector<Tile>& possibilities);
	bool selectionMade();
	enum TileSolveState applyRules(Mesh& mesh);
	void print(std::stringstream& stream);
	void printFull(std::stringstream& stream);
	std::tuple<size_t, size_t> getLocation();
	void setLocation(size_t x, size_t y);
	Tile getTile();
	Tile& eliminateTile(Tile& tile);
	bool makeSelection(Tile& tile);
	Tile& getFirstOption();
	Tile& makeFirstSelection();
	Tile& makeRandomSelection(std::mt19937& generator);
	size_t optionSpace();
};

#endif
