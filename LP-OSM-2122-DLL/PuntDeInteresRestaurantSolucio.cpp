#include "pch.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include <string>

using namespace std;

unsigned int PuntDeInteresRestaurantSolucio::getColor() {
	if (m_cuisine == "pizza" && m_wheelchair == "yes")
		return 0x03FCBA;
	else if (m_cuisine == "chinese")
		return 0xFFAD69;
	else if (m_wheelchair == "yes")
		return 0x251351;
	return 0xFFA550;
}
