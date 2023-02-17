
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


std::vector<TileSpace> Mesh::getRow(size_t x)
{
	return mesh[x];
}

std::vector<TileSpace> Mesh::getColumn(size_t y)
{
	std::vector<TileSpace> returnVector;

	for (std::vector<TileSpace> i : mesh) {
		returnVector.push_back(i[y]);
	}

	return returnVector;
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

