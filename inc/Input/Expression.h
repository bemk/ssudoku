
#ifndef INPUT_EXPRESSION_H
#define INPUT_EXPRESSION_H

#include <memory>
#include <string>
#include <vector>
#include "Mesh.h"

namespace Input {

class Expression 
{
public:
	virtual ~Expression() {}
	virtual std::unique_ptr<Expression> match(std::string& input) = 0;
	virtual std::shared_ptr<Expression> left() = 0;
	virtual std::shared_ptr<Expression> right() = 0;
	virtual bool apply(Mesh& mesh) = 0;
};

}

#endif
