
#include <iostream>
#include "Mesh.h"

Tile::Tile(std::string typeName, std::vector<Rules::TileRule*>& rules) : 
	typeName(typeName),
	rules(rules)
{
}

void Tile::toText(std::stringstream& stream) 
{
	stream << typeName;
}

bool Tile::checkValidity(Mesh& mesh)
{
	for (Rules::TileRule* rule : rules) {
		if (!rule->apply(*this, mesh, this->x, this->y)) {
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
