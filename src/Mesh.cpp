
#include "Mesh.h"
#include <iostream>
#include <sstream>
#include <algorithm>

Mesh::Mesh(const std::vector<Tile>& spaceTemplate, const int x, const int y, std::mt19937& generator) : 
	spaceTemplate(spaceTemplate),
	x(x), 
	y(y),
	generator(generator)
{
	mesh = std::vector<std::vector<TileSpace>>(
		x,
		std::vector<TileSpace>(y, TileSpace(spaceTemplate)));

	size_t i = 0, j = 0;
	for (auto& row : mesh) {
		for (auto& column : row) {
			column.setLocation(i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

Mesh::~Mesh()
{
}

void Mesh::print()
{
	if (y > 26) {
		std::cout << "Horizontal axis too big for printing";
		return;
	}
	std::stringstream stream;
	stream << "   ";
	for (size_t i = 0; i < x; i++) {
		stream << "  " << (char)('a' + i) << " ";
	}
	stream << "\n   +";
	for (size_t i = 0; i < x; i++) {
		stream << "---+";
	}
	stream << "\n";
	for (size_t x = 0; x < this->x; x++) {
		stream << " " << x+1 << " " << "|";
		for (size_t y = 0; y < this->y; y++)  {
			mesh[x][y].print(stream);
			stream << "|";
		}
		stream << "\n   +";
		for (size_t i = 0; i < this->x; i++) {
			stream << "---+";
		}
		stream << "\n";
	}

	std::cout << stream.str();
}

bool Mesh::solve(bool verbose)
{
	bool solvable = true;
	bool ambiguous = false;
	bool tilesSolved = step(verbose, solvable, ambiguous);

	if (tilesSolved) {
		return solve(verbose);
	}

	if (!solvable) {
		return false;
	}

	if (ambiguous) {
		return iterateOptions(verbose);
	} 

	print();
	return true;
}

bool Mesh::iterateOptions(bool verbose)
{
	std::vector<TileSpace*> unsolved = getUnsolved();
	for (TileSpace* t : unsolved) {
		Mesh copy = *this;
		std::tuple<size_t, size_t> location = t->getLocation();

		TileSpace& attempt = copy.getTile(std::get<0>(location), std::get<1>(location));

		attempt.makeFirstSelection();
//		attempt.makeRandomSelection(generator);
		if (copy.solve(verbose)) {
			return true;
		}
	}
	return false;
}

std::vector<TileSpace*> Mesh::getUnsolved()
{
	std::vector<TileSpace*> unsolved;
	auto row = mesh.begin();
	while (row != mesh.end()) {
		auto column = row->begin();
		while (column != row->end()) {
			if (!column->selectionMade()) {
				unsolved.push_back(&(*column));
			}
			column++;
		}
		row++;
	}

	std::sort(
		unsolved.begin(), 
		unsolved.end(), 
		[](TileSpace* a, TileSpace* b) {
			return (a->optionSpace() < b->optionSpace());
		});

	return unsolved;
}

bool Mesh::step(bool verbose, bool& solvable, bool& ambigious)
{
	bool tilesEliminated = false;
	solvable = true;
	ambigious = false;
	for (auto& row : mesh) {
		for (TileSpace& t : row) {
			enum TileSolveState solved = t.applyRules(*this);
			switch(solved) {
			case UNSOLVABLE:
				solvable = false;
				break;
			case TILES_SOLVED:
				tilesEliminated = true;
				break;
			case ALL_SOLVED:
				break;
			case NOTHING_TO_SOLVE:
				ambigious = true;
				break;
			}
		}
	}

	if (verbose) {
		print();
	}

	if (!tilesEliminated) {
		std::vector<TileSpace*> unsolved = getUnsolved();
		if (unsolved.size() == 0) {
			return false;
		}
	}

	return tilesEliminated;
}

std::vector<TileSpace> Mesh::getRow(size_t x)
{
	std::vector<TileSpace> row;
	for (size_t i = 0; i < y; i++) {
		row.push_back(getTile(x, i));
	}
	return row;
}

std::vector<TileSpace> Mesh::getColumn(size_t y)
{
	std::vector<TileSpace> column;

	for (size_t i = 0; i < x; i++) {
		column.push_back(getTile(i, y));
	}

	return column;
}

std::vector<std::vector<TileSpace>> Mesh::getConnectEight(size_t x, size_t y)
{
	std::vector<std::vector<TileSpace>> returnVector;
	
	std::vector<TileSpace> vec1;
	std::vector<TileSpace> vec2;
	std::vector<TileSpace> vec3;

	if (x > 0) {
		if (y > 0) {
			vec1.push_back(getTile(x-1, y-1));
		}
		vec1.push_back(getTile(x-1, y));
		if (y < this->y) {
			vec1.push_back(getTile(x-1, y+1));
		}
		returnVector.push_back(vec1);
	}

	if (y > 0) {
		vec2.push_back(getTile(x, y-1));
	}
	vec2.push_back(getTile(x, y));
	if (y < this->y) {
		vec2.push_back(getTile(x, y+1));
	}
	returnVector.push_back(vec2);
	
	if (x < this->x) {
		if (y > 0) {
			vec3.push_back(getTile(x+1, y-1));
		}
		vec3.push_back(getTile(x+1, y));
		if (y < this->y) {
			vec3.push_back(getTile(x+1, y+1));
		}
		returnVector.push_back(vec3);
	}

	return returnVector;
}


TileSpace& Mesh::getTile(size_t x, size_t y)
{
	return mesh[x][y];
}

bool Mesh::setTile(size_t x, size_t y, Tile& tile)
{
	return mesh[x][y].makeSelection(tile);
}
