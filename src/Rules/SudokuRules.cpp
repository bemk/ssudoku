
#include "Rules/SudokuRules.h"
#include "Mesh.h"

#include <iostream>
#include <sstream>

namespace Rules {
namespace Sudoku {

#ifdef ULTRAVERBOSE
void dumpSet(std::string ruleName, size_t x, size_t y, std::vector<std::vector<TileSpace>> set)
{
	std::stringstream output;
	output << "[" << ruleName << "] (" << (char)('a' + y) << x+1 << ")\n";
	int i = 0;
	for (std::vector<TileSpace> row : set) {
		output << "[" << ++i << "]: ";
		for (TileSpace t: row) {
			t.print(output);
		}
		output << "\n";
	}
	std::cout << output.str();
}
#endif

bool UniqueInRow::apply(
	Tile& tile, 
	Mesh& mesh, 
	size_t x,
	size_t y __attribute__((unused)))
{
	std::vector<TileSpace> row = mesh.getRow(x);

#ifdef ULTRAVERBOSE
	std::vector<std::vector<TileSpace>> set;
	set.push_back(row);
	dumpSet("UniqueInRow", x, y, set);
#endif

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
	size_t x __attribute__((unused)),
	size_t y)
{
	std::vector<TileSpace> column = mesh.getColumn(y);

#ifdef ULTRAVERBOSE
	std::vector<std::vector<TileSpace>> set;
	set.push_back(column);
	dumpSet("UniqueInColumn", x, y, set);
#endif

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
#ifdef ULTRAVERBOSE
	dumpSet("UniqueInSquare", x, y, square);
#endif

	for (auto row : square) {
		for (TileSpace s : row) {
			if (s.selectionMade() && s.getTile().equals(tile)) {
				return false;
			}
		}
	}

	return true;
}

}
}
