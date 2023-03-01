
#ifndef INPUT_SET_TILE_H
#define INPUT_SET_TILE_H

#include "Input/Expression.h"
#include <memory>
#include <regex>

namespace Input {

class SetTile : public Expression
{
private:
	std::regex definition = std::regex("([a-i])([1-9])[ ]*=[ ]*([1-9])");
public:
	virtual bool match(std::string& input) override;
	virtual bool apply(std::string& line, Mesh& mesh) override;
};

}

#endif
