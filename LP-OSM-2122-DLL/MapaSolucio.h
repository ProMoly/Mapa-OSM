#pragma once

#include "MapaBase.h"
#include "CamiSolucio.h"
#include "BallTree.h"
#include "GrafSolucio.h"
#include "Util.h"

class MapaSolucio : public MapaBase, public CamiSolucio
{
public:
	void getPdis(std::vector<PuntDeInteresBase*>& pdis);
	void getCamins(std::vector<CamiBase*>& camins);
	void parsejaXmlElements(std::vector<XmlElement>& xmlElements);
	void construeixGraf() { if (!m_camins.empty()) grafSolucio = new GrafSolucio(m_camins); }
	CamiBase* buscaCamiMesCurt(PuntDeInteresBase* from, PuntDeInteresBase* to);
private:
	GrafSolucio* grafSolucio;
	vector<CamiBase*> m_camins;
	vector<PuntDeInteresBase*> m_pdis;

};