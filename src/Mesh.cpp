
#include "Mesh.h"

Mesh::Mesh(const std::vector<Tile>& spaceTemplate, const int x, const int y) : 
	spaceTemplate(spaceTemplate),
	x(x), 
	y(y)
{
}

Mesh::~Mesh()
{
}
