
#ifndef INPUT_RUN_H
#define INPUT_RUN_H

#include "Input/Expression.h"

namespace Input {

class Run : public Expression
{
public:
	virtual bool match(std::string& input) override;
	virtual Expression* left() override;
	virtual Expression* right() override;
	virtual bool apply(Mesh& mesh) override;
};

}

#endif
