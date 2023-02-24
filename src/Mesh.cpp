
#include "Mesh.h"
#include <iostream>
#include <sstream>

Mesh::Mesh(const std::vector<Tile>& spaceTemplate, const int x, const int y, std::mt19937& generator) : 
	spaceTemplate(spaceTemplate),
	x(x), 
	y(y),
	generator(generator)
{
	mesh = std::vector<std::vector<TileSpace>>(
		x, 
		std::vector<TileSpace>(
			y, 
			TileSpace(spaceTemplate, this)));

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
	bool unsolved = step(verbose);
	
	/*
	std::stringstream stream;
	for (auto row : mesh) {
		for (TileSpace s : row) {
			s.printFull(stream);
		}
	}
	std::cout << stream.str();
	*/
	if (unsolved) {
		return solve(verbose);
	}
	return true;
}

bool Mesh::step(bool verbose)
{
	bool tilesEliminated = false;
	for (auto& row : mesh) {
		for (TileSpace& t : row) {
			if (t.selectionMade()) {
				continue;
			}
			if (t.applyRules()) {
				tilesEliminated = true;
			}
		}
	}

	if (!tilesEliminated) {
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

		if (unsolved.size() == 0) {
			if (verbose) {
				print();
			}
			return false;
		}
		std::uniform_int_distribution<> tileSelector(0, unsolved.size());
		const size_t selectedTileIndex = tileSelector(generator);
		TileSpace* selectedTile = unsolved[selectedTileIndex];

		std::tuple<size_t, size_t> tileLocation = selectedTile->getLocation();
		std::cout << "Randomly setting position ";
		std::cout << (char)('a' + std::get<1>(tileLocation));
		std::cout << ",";
		std::cout << std::get<0>(tileLocation) + 1;
		std::cout << "\n";

		selectedTile->makeRandomSelection(generator);
	}

	if (verbose) {
		print();
	}
	return true;
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


TileSpace Mesh::getTile(size_t x, size_t y)
{
	return mesh[x][y];
}

bool Mesh::setTile(size_t x, size_t y, Tile& tile)
{
	return mesh[x][y].makeSelection(tile);
}
