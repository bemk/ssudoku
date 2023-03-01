
#ifndef INPUT_RUN_H
#define INPUT_RUN_H

#include "Input/Expression.h"
#include <memory>
#include <string>
#include <regex>

namespace Input {

class Run : public Expression
{
private:
	std::regex definition = std::regex("run( v(erbose)?)?");
public:
	virtual bool match(std::string& input) override;
	virtual bool apply(std::string& input, Mesh& mesh) override;
};

}

#endif
