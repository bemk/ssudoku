
#include "TileSpace.h"
#include "random"
#include <iostream>

TileSpace::TileSpace(const std::vector<Tile>& possibilities) :
	options(possibilities)
{
}

enum TileSolveState TileSpace::applyRules(Mesh& mesh)
{
	if (selectionMade()) {
		return ALL_SOLVED;
	}
	std::vector<Tile> newSet;

	enum TileSolveState solved = NOTHING_TO_SOLVE;

	for (Tile t : options) {
		if (t.checkValidity(mesh)) {
			newSet.push_back(t);
		}
	}

	if (newSet.size() < options.size()) {
		solved = TILES_SOLVED;
	}

	if (newSet.size() == 1) {
		markSelected();
		solved = ALL_SOLVED;
	} else if (newSet.size() == 0) {
		std::cerr << "Grid unsolvable!\n";
		std::cerr << "[" << (char)('a'+y) << x+1 << "]\n";
		mesh.print();
		return UNSOLVABLE;
	}

	options = newSet;
	return solved;
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
		stream << " ";
		options[0].toText(stream);
		stream << " ";
	} else {
		/*
		stream << (char)('a' + y);
		stream << " ";
		stream << x+1;
		*/
		stream << "   ";
	}
}

void TileSpace::printFull(std::stringstream& stream)
{
	stream << (char)('a' + y) << x+1 << ":\t";
	for (Tile t : options)
	{
		t.toText(stream);
		stream << "\t";
	}
	stream << "\n";
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

bool TileSpace::makeSelection(Tile& tile)
{
	std::vector<Tile> selection;
	for (Tile t : options) {
		if (t.equals(tile)) {
			selection.push_back(t);
			options = selection;
			markSelected();
			return true;
		}
	}
	return false;
}

bool TileSpace::makeFirstSelection()
{
	return makeSelection(options[0]);
}

bool TileSpace::makeRandomSelection(std::mt19937& generator)
{
	const size_t optionSize = options.size() -1;
	std::uniform_int_distribution<> distribution(0, optionSize);
	const size_t index = distribution(generator);
	Tile& tile = options[index];
	return makeSelection(tile);
}

std::tuple<size_t, size_t> TileSpace::getLocation()
{
	return {x, y};
}
