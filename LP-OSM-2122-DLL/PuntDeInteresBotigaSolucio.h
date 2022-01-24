#pragma once

#include "PuntDeInteresBase.h"
#include <string>

using namespace std;

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase {
public:
	PuntDeInteresBotigaSolucio() : m_shop(""), m_wheelchair(""), m_opening_hours("") {}
	~PuntDeInteresBotigaSolucio() {}

	void setShop(const string shop) { m_shop = shop; }
	void setWheelChair(const string wheelchair) { m_wheelchair = wheelchair; }
	void setOpeningHours(const string opening_hours) { m_opening_hours = opening_hours; }
	unsigned int getColor();
private:
	string m_shop;
	string m_wheelchair;
	string m_opening_hours;
};