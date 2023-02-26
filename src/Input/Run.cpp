
#include "Input/Run.h"
#include "Input/Expression.h"
#include <memory>


std::unique_ptr<Input::Expression> Input::Run::match(std::string& input)
{
	if (input.compare("run") == 0) {
		return std::unique_ptr<Run>();
	}
	return nullptr;
}

std::shared_ptr<Input::Expression> Input::Run::left() 
{
	return nullptr;
}

std::shared_ptr<Input::Expression> Input::Run::right() 
{
	return nullptr;
}

bool Input::Run::apply(Mesh& mesh __attribute__((unused))) 
{
	return false;
}
