#include "pch.h"
#include "PuntDeInteresBotigaSolucio.h"
#include <string>

using namespace std;

unsigned int PuntDeInteresBotigaSolucio::getColor() {
	if (m_shop == "bakery" && m_wheelchair == "yes")
		return 0x4CB944;
	else if (m_shop == "bakery")
		return 0xE85D75;
	if (m_shop == "supermarket")
		return 0xA5BE00;
	else if (m_shop == "tobacco")
		return 0xFFAD69;
	return 0xEFD6AC;
}
