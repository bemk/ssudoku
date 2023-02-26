
#include "Input/Location.h"
#include "Input/SetTile.h"
#include "Input/TileValue.h"
#include <regex>

bool Input::SetTile::match(std::string& input __attribute__((unused))) 
{
	return false;
}

Input::Expression* Input::SetTile::left() 
{
	return nullptr;
}

Input::Expression* Input::SetTile::right() 
{
	return nullptr;
}

bool Input::SetTile::apply(Mesh& mesh __attribute__((unused))) 
{
	return false;
}
