
#include "Tile.h"

Tile::Tile(std::string typeName, std::vector<Rules::TileRule*>& rules, Mesh* mesh) : 
	typeName(typeName),
	rules(rules),
	mesh(mesh)
{
}

void Tile::toText(std::stringstream& stream) 
{
	stream << typeName;
}

bool Tile::checkValidity()
{
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

