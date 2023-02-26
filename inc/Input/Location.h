
#ifndef INPUT_LOCATION_H
#define INPUT_LOCATION_H

#include "Input/Expression.h"

namespace Input {

class Location : public Expression
{
public:
	virtual bool match(std::string& input) override;
	virtual Expression* left() override;
	virtual Expression* right() override;
	virtual bool apply(Mesh& mesh) override;
};

}

#endif

