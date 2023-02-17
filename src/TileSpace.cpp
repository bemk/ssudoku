
#include "TileSpace.h"

TileSpace::TileSpace(const std::vector<Tile>& possibilities, Mesh* mesh) :
	options(possibilities),
	mesh(mesh)
{
}

void TileSpace::applyRules()
{
	std::vector<Tile> newSet;
	for (Tile t : options) {
		if (t.checkValidity()) {
			newSet.push_back(t);
		}
	}
	options = newSet;
	if (options.size() == 1) {
		markSelected();
	}
}

bool TileSpace::selectionMade()
{
	return selected;
}

void TileSpace::markSelected()
{
	selected = true;
}

void TileSpace::print(std::stringstream& stream)
{
	if (selectionMade()) {
		stream << " * ";
	} else {
		stream << (char)('a' + y);
		stream << " ";
		stream << x;
	}
}

void TileSpace::setLocation(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
	for (Tile& t : options) {
		t.setLocation(x, y);
	}
}

Tile TileSpace::getTile()
{
	return options[0];
}
