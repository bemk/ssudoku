
#include "Input/Parser.h"

Input::Parser::Parser(std::vector<std::string>& script)
    : script(script)
{
}

bool Input::Parser::run(Mesh &mesh __attribute__((unused)))
{
    return false;
}
