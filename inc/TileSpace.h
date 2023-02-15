
#ifndef TILE_SPACE_H
#define TILE_SPACE_H

#include <vector>
#include "Tile.h"

class TileSpace {
private:
	std::vector<Tile> options;
	bool selected = false;
	void markSelected();
public:
	TileSpace(std::vector<Tile>& possibilities);
	bool selectionMade();
	void applyRules();
};

#endif
