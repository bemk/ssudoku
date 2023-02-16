
#include "Mesh.h"
#include <iostream>
#include <sstream>

Mesh::Mesh(const std::vector<Tile>& spaceTemplate, const int x, const int y) : 
	spaceTemplate(spaceTemplate),
	x(x), 
	y(y)
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
	if (verbose)
		std::cout << "Solving all in one go!\n";
	return step(verbose);
}

bool Mesh::step(bool verbose)
{
	if (verbose) 
		print();
	return true;
}
