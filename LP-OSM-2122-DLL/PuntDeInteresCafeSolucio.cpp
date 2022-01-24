#include "pch.h"
#include "PuntDeInteresCafeSolucio.h"
#include <string>

using namespace std;

unsigned int PuntDeInteresCafeSolucio::getColor() {
	if (m_cuisine == "sandwich" && m_amenity == "cafe")
		return 0xF5F2B8;
	return 0xFFA500;
}
