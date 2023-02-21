
#ifndef MESH_H
#define MESH_H

#include <vector>
#include <cstddef>
#include <random>

#include "TileSpace.h"

class TileSpace;
class Tile;

class Mesh {
private:
	std::vector<std::vector<TileSpace>> mesh;
	const std::vector<Tile> spaceTemplate;
	const size_t x;
	const size_t y;
	std::mt19937& generator;

	void print();
	bool setTile(size_t x, size_t y, Tile& tile);
public:
	Mesh(const std::vector<Tile>& spaceTemplate, const int x, const int y, std::mt19937& generator);
	~Mesh();

	bool solve(bool verbose);
	bool step(bool verbose);

	std::vector<TileSpace> getRow(size_t x);
	std::vector<TileSpace> getColumn(size_t y);
	std::vector<std::vector<TileSpace>> getConnectEight(size_t x, size_t y);

	TileSpace getTile(size_t x, size_t y);
};

#endif
