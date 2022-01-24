#include "pch.h"
#include "PuntDeInteresBase.h"


PuntDeInteresBase::PuntDeInteresBase() {
	this->m_coord = Coordinate{ 0.0, 0.0 };
	this->m_name = "undefinit";
}

PuntDeInteresBase::PuntDeInteresBase(Coordinate coord, std::string name) {
	this->m_name = name;
	this->m_coord = coord;
}

Coordinate PuntDeInteresBase::getCoord() {
	return this->m_coord;
}

string PuntDeInteresBase::getName() {
	return this->m_name;
}

unsigned int PuntDeInteresBase::getColor() {
	return 0xFFA550;
}

void PuntDeInteresBase::setCoord(const Coordinate coord) {
	m_coord.lat = coord.lat;
	m_coord.lon = coord.lon;
}