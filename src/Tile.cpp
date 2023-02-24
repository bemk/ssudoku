
#include "Tile.h"
#include <iostream>

Tile::Tile(std::string typeName, std::vector<Rules::TileRule*>& rules) : 
	typeName(typeName),
	rules(rules)
{
}

void Tile::toText(std::stringstream& stream) 
{
	stream << typeName;
}

bool Tile::checkValidity()
{
	if (mesh == nullptr) {
		std::cerr << "Null pointer at " << __FILE__ << ":" << __LINE__ << "\n";
		exit(-1);
	}
	for (Rules::TileRule* rule : rules) {
		if (!rule->apply(*this, *mesh, this->x, this->y)) {
			return false;
		}
	}
	return true;
}

void Tile::setLocation(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
}

bool Tile::equals(Tile& tile)
{
	return (typeName.compare(tile.typeName) == 0);
}

void Tile::setMesh(Mesh* mesh)
{
	this->mesh = mesh;
}
