
#include "TileSpace.h"

TileSpace::TileSpace(std::vector<Tile>& possibilities)
	: options(possibilities)
{
}

void TileSpace::applyRules()
{

}

bool TileSpace::selectionMade()
{
	return selected;
}

void TileSpace::markSelected()
{
	selected = true;
}
