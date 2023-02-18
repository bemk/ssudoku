
#include "Rules/SudokuRules.h"

namespace Rules {
namespace Sudoku {


bool UniqueInRow::apply(
	Tile& tile, 
	Mesh& mesh, 
	size_t x __attribute__((unused)),
	size_t y)
{
	std::vector<TileSpace> row = mesh.getRow(y);
	for (TileSpace s : row) {
		if (s.selectionMade()) {
			if (s.getTile().equals(tile)) {
				return false;
			}
		}
	}
	return true;
}

bool UniqueInColumn::apply(
	Tile& tile, 
	Mesh& mesh,
	size_t x, 
	size_t y __attribute__((unused)))
{
	std::vector<TileSpace> column = mesh.getColumn(x);
	for (TileSpace s : column) {
		if (s.selectionMade()) {
			if (s.getTile().equals(tile)) {
				return false;
			}
		}
	}
	return true;
}

bool UniqueInSquare::apply(Tile& tile, Mesh& mesh, size_t x, size_t y)
{
	const size_t squareX = x / 3;
	const size_t squareY = y / 3;

	const size_t squareCentreX = squareX * 3 + 1;
	const size_t squareCentreY = squareY * 3 + 1;

	auto square = mesh.getConnectEight(squareCentreX, squareCentreY);
	for (auto row : square) {
		for (TileSpace s : row) {
			if (s.getTile().equals(tile)) {
				return false;
			}
		}
	}

	return true;
}

}
}
