
#include "TileSpace.h"
#include "random"
#include <iostream>

TileSpace::TileSpace(const std::vector<Tile>& possibilities, Mesh* mesh) :
	options(possibilities),
	mesh(mesh)
{
	for (Tile& t : options)
	{
		t.setMesh(mesh);
	}
}

bool TileSpace::applyRules()
{
	if (selectionMade()) {
		return true;
	}
	bool success = false;
	std::vector<Tile> newSet;

	for (Tile t : options) {
		if (t.checkValidity()) {
			newSet.push_back(t);
		}
	}

	if (newSet.size() < options.size()) {
		success = true;
	}

	options = newSet;
	if (options.size() == 1) {
		markSelected();
	} else if (options.size() == 0) {
		std::cerr << "Grid unsolvable!\n";
		exit(-1);
	}
	return success;
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
