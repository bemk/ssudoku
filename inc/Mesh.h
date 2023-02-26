
#ifndef MESH_H
#define MESH_H

#include <vector>
#include <cstddef>
#include <random>

#include "TileSpace.h"

class Mesh {
private:
	std::vector<std::vector<TileSpace>> mesh;
	const std::vector<Tile> spaceTemplate;
	const size_t x;
	const size_t y;
	std::mt19937& generator;

	bool setTile(size_t x, size_t y, Tile& tile);
	std::vector<TileSpace*> getUnsolved();

	bool iterateOptions(bool verbose);
public:
	Mesh(const std::vector<Tile>& spaceTemplate, const int x, const int y, std::mt19937& generator);
	~Mesh();

	bool solve(bool verbose, bool stepped = false);
	bool step(bool verbose, bool& solvable, bool& ambiguous);

	void print();

	std::vector<TileSpace> getRow(size_t x);
	std::vector<TileSpace> getColumn(size_t y);
	std::vector<std::vector<TileSpace>> getConnectEight(size_t x, size_t y);

	TileSpace& getTile(size_t x, size_t y);
};

#endif
