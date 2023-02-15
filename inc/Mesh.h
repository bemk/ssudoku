
#ifndef MESH_H
#define MESH_H

#include <vector>
#include <cstddef>

#include "TileSpace.h"

class Mesh {
private:
	std::vector<std::vector<TileSpace>> mesh;
	const std::vector<Tile> spaceTemplate;
	const size_t x;
	const size_t y;
public:
	Mesh(const std::vector<Tile>& spaceTemplate, const int x, const int y);
	~Mesh();
};

#endif
