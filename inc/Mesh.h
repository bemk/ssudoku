
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

	std::vector<TileSpace*> getUnsolved();

	bool iterateOptions(bool verbose);
	bool makeRandomSelection;

public:
	Mesh(
		const std::vector<Tile>& spaceTemplate,
		const bool makeRandomSelection,
		const int x, 
		const int y, 
		std::mt19937& generator);
	~Mesh();

	bool solve(bool verbose, bool stepped = false);
	bool step(bool verbose, bool& solvable, bool& ambiguous);

	void print();
	std::vector<std::string> csv();

	std::vector<TileSpace> getRow(size_t x);
	std::vector<TileSpace> getColumn(size_t y);
	std::vector<std::vector<TileSpace>> getConnectEight(size_t x, size_t y);

	bool setTile(size_t x, size_t y, Tile& tile);
	TileSpace& getTile(size_t x, size_t y);
};

#endif
