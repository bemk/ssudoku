
#ifndef INPUT_TILE_VALUE_H
#define INPUT_TILE_VALUE_H

#include "Input/Expression.h"

namespace Input {

class TileValue : public Expression
{
public:
	virtual std::unique_ptr<Expression> match(std::string& input) override;
	virtual Expression* left() override;
	virtual Expression* right() override;
	virtual bool apply(Mesh& mesh) override;
};

}

#endif

