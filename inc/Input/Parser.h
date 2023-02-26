
#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include "Input/Expression.h"
#include <vector>

namespace Input {

class Parser 
{
    std::vector<std::string>& script;
    std::vector<Expression*> expressions;

public:
    Parser(std::vector<std::string>& script);
    bool run(Mesh& mesh);
};

}

#endif
