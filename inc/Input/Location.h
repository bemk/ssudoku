
#ifndef INPUT_LOCATION_H
#define INPUT_LOCATION_H

#include "Input/Expression.h"
#include <memory>

namespace Input {

class Location : public Expression
{
public:
	virtual std::unique_ptr<Expression> match(std::string& input) override;
	virtual std::shared_ptr<Expression> left() override;
	virtual std::shared_ptr<Expression> right() override;
	virtual bool apply(Mesh& mesh) override;
};

}

#endif

