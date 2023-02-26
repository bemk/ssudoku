
#ifndef INPUT_SET_TILE_H
#define INPUT_SET_TILE_H

#include "Input/Expression.h"
#include <regex>

namespace Input {

class SetTile : public Expression
{
private:
	std::regex definition = std::regex("([a-i][0-9])([ *]=[ *])([0-9])");
public:
	virtual std::unique_ptr<Expression> match(std::string& input) override;
	virtual Expression* left() override;
	virtual Expression* right() override;
	virtual bool apply(Mesh& mesh) override;
};

}

#endif