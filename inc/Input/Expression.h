
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
	virtual bool match(std::string& input) = 0;
	virtual bool apply(std::string& line, Mesh& mesh) = 0;
};

}

#endif
