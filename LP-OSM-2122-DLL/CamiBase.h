#pragma once

#include "Common.h"
#include <vector>

class CamiBase {
public:
	virtual std::vector<Coordinate> getCamiCoords() = 0;
	virtual void addCoord(const Coordinate coord) = 0;

};

