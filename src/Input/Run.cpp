
#include "Input/Run.h"


bool Input::Run::match(std::string& input)
{
	return (input.compare("run") == 0);
}

Input::Expression* Input::Run::left() 
{
	return nullptr;
}

Input::Expression* Input::Run::right() 
{
	return nullptr;
}

bool Input::Run::apply(Mesh& mesh __attribute__((unused))) 
{
	return false;
}
