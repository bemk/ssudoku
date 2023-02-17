
#ifndef TILE_RULE_H
#define TILE_RULE_H

#include "Mesh.h"

class Mesh;

namespace Rules {

class TileRule {
public:
	TileRule();

	virtual bool apply(size_t x, size_t y, Mesh* mesh) = 0;
};

}

#endif
