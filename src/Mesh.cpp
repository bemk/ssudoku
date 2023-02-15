
#include "Mesh.h"
#include <iostream>

Mesh::Mesh(const std::vector<Tile>& spaceTemplate, const int x, const int y) : 
	spaceTemplate(spaceTemplate),
	x(x), 
	y(y)
{
}

Mesh::~Mesh()
{
}

void Mesh::solve(bool verbose)
{
	if (verbose)
		std::cout << "Solving all in one go!\n";
}

bool Mesh::step(bool verbose)
{
	if (verbose)
		std::cout << "Solving step by step\n";
	return true;
}
