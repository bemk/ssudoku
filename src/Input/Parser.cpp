
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

bool Input::Parser::run(Mesh &mesh)
{
	for (std::string& s : script) {
		bool success = false;
		for (Input::Expression* e : expressions) {
			if (e->match(s)) {
				success = true;
				e->apply(s, mesh);
			}
		}
		if (!success) {
			std::cerr << "No expression matched [" << s << "]";
			return false;
		}
	}
	return true;
}
