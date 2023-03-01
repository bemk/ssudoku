
#include "Input/Run.h"
#include "Input/Expression.h"
#include <memory>
#include <string>
#include <regex>

bool Input::Run::match(std::string& input)
{
	return std::regex_match(input, definition);
}

bool Input::Run::apply(std::string& input, Mesh& mesh) 
{
	std::match_results<std::string::const_iterator> results;
	std::regex_search(input, results, definition);

	if (results[2].compare("") != 0) {
		return mesh.solve(true);
	} else {
		return mesh.solve(false);
	}
}
