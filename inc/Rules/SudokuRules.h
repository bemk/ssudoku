
#ifndef RULES_SUDOKU_RULES_H
#define RULES_SUDOKU_RULES_H

#include "Rules/TileRule.h"

namespace Rules {
namespace Sudoku {

class UniqueInRow : public TileRule
{
public:
	bool apply(Tile& tile, Mesh& mesh, size_t x, size_t y) override;
};

class UniqueInColumn : public TileRule
{
public:
	bool apply(Tile& tile, Mesh& mesh, size_t x, size_t y) override;
};

class UniqueInSquare : public TileRule
{
public:
	bool apply(Tile& tile, Mesh& mesh, size_t x, size_t y) override;
};

}
}

#endif
