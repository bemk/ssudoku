
#include "Input/Expression.h"
#include "Input/SetTile.h"

#include "Rules/TileRule.h"
#include <cstddef>
#include <memory>
#include <regex>
#include <vector>
#include <iostream>

bool Input::SetTile::match(std::string& input) 
{
	return std::regex_match(input, definition);
}

bool Input::SetTile::apply(std::string& input, Mesh& mesh) 
{
	std::unique_ptr<Expression> result(new SetTile());
	std::match_results<std::string::const_iterator> results;

	std::regex_search(input, results, definition);
	std::string sx = results[2];
	std::string sy = results[1];
	std::string value = results[3];

	size_t x = sx.at(0) - '1';
	size_t y = sy.at(0)-'a';

	std::vector<Rules::TileRule*> rules;
	Tile tile (value, rules);
	bool success = mesh.setTile(x, y, tile);

	mesh.print();
	return success;

}
