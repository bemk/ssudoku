
#ifndef MESH_H
#define MESH_H

#include <vector>
#include <cstddef>

#include "TileSpace.h"

class TileSpace;
class Tile;

class Mesh {
private:
	std::vector<std::vector<TileSpace>> mesh;
	const std::vector<Tile> spaceTemplate;
	const size_t x;
	const size_t y;

	void print();
public:
	Mesh(const std::vector<Tile>& spaceTemplate, const int x, const int y);
	~Mesh();

	bool solve(bool verbose);
	bool step(bool verbose);
};

#endif
