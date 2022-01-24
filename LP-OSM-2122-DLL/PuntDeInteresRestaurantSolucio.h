#pragma once

#include "PuntDeInteresBase.h"
#include <string>

using namespace std;

class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase {
public:
	PuntDeInteresRestaurantSolucio() : m_cuisine(""), m_wheelchair(""), m_amenity("") { }
	~PuntDeInteresRestaurantSolucio() { }

	void setAmenity(const string amenity) { m_amenity = amenity; }
	void setCuisine(const string cuisine) { m_cuisine = cuisine; }
	void setWheelChair(const string wc) { m_wheelchair = wc; }
	unsigned int getColor();
private:
	string m_amenity;
	string m_cuisine;
	string m_wheelchair; //YES -> Facilita movilitat reduida; NO ->...
};