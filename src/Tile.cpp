
#include "Tile.h"

Tile::Tile(std::string typeName, std::vector<TileRule>& rules) : 
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
	return true;
}


