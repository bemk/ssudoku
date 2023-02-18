
#ifndef TILE_RULE_H
#define TILE_RULE_H

#include "Mesh.h"
#include "Tile.h"

class Mesh;
class Tile;

namespace Rules {

class TileRule {
public:
	TileRule();

	virtual bool apply(Tile& tile, Mesh& mesh, size_t x, size_t y) = 0;
};

}

#endif
