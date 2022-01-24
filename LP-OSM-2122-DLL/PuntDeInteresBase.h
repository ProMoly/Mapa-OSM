#pragma once

#include <string>
#include "Common.h"

using namespace std;

class PuntDeInteresBase {

	private:
		Coordinate m_coord;
		string m_name;

	public:		
		PuntDeInteresBase();
		PuntDeInteresBase(Coordinate coord, string name);

		void setCoord(const Coordinate coord);
		void setName(const string name) { m_name = name; }
		string getName();
		Coordinate getCoord();
		virtual unsigned int getColor();

};