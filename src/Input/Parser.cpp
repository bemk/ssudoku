
#include "Input/Parser.h"
#include "Input/Expression.h"
#include "Input/Run.h"
#include "Input/SetTile.h"

#include <iostream>

Input::Parser::Parser(std::vector<std::string>& script)
	: script(script)
{
	expressions.push_back(new Input::Run());
	expressions.push_back(new Input::SetTile());
}

Input::Parser::~Parser()
{
	for (Input::Expression* e : expressions) {
		delete e;
	}
}

bool Input::Parser::run(Mesh &mesh __attribute__((unused)))
{
	for (std::string& s : script) {
		bool success = false;
		for (Input::Expression* e __attribute__((unused)) : expressions) {
			
		}
		if (!success) {
			std::cerr << "No expression matched [" << s << "]";
			return false;
		}
	}
	return true;
}
