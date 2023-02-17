
#ifndef RULES_SUDOKU_RULES_H
#define RULES_SUDOKU_RULES_H

#include "Rules/TileRule.h"

namespace Rules {
namespace Sudoku {

class UniqueInRow : public TileRule
{
	bool apply(size_t x, size_t y, Mesh* mesh) override;
};

class UniqueInColumn : public TileRule
{
	bool apply(size_t x, size_t y, Mesh* mesh) override;
};

class UniqueInSquare : public TileRule
{
	bool apply(size_t x, size_t y, Mesh* mesh) override;
};

}
}

#endif
