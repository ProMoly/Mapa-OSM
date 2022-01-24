#include "pch.h"
#include "GrafSolucio.h"
#include "CamiSolucio.h"
#include "MapaBase.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

void GrafSolucio::afegirAresta(int posNode1, int posNode2)
{
	if ((posNode1 < m_numNodes) && (posNode2 < m_numNodes) && (posNode1 >= 0) && (posNode2 >= 0))
	{
		double distancia = Util::DistanciaHaversine(m_nodes[posNode1], m_nodes[posNode2]);
		m_veins[posNode1].emplace_back(pair<int, double>(posNode2, distancia));
		m_veins[posNode2].emplace_back(pair<int, double>(posNode1, distancia));
		m_numArestes++;
	}

}

void GrafSolucio::afegirNode(const Coordinate& node)
{

	m_nodes.push_back(node);
	m_numNodes++;
	m_veins.resize(m_numNodes);
}

GrafSolucio::GrafSolucio()
{
	m_numNodes = 0;
	m_numArestes = 0;

}

int GrafSolucio::cerca(const Coordinate cerca, const vector<Coordinate> nodes) {
	int i = 0;
	bool trobat = false;
	while (i < nodes.size() && !trobat) {
		if (nodes[i].lat == cerca.lat && nodes[i].lon == cerca.lon)
			trobat = true;
		else
			i++;
	}
	if (trobat)
		return i;
	return 0;
}

GrafSolucio::GrafSolucio(vector<CamiBase*> camins)
{
	m_numNodes = 0;
	m_numArestes = 0;
	for (int i = 0; i < camins.size(); i++) {
		vector<Coordinate> cami = camins[i]->getCamiCoords();
		if (!Util::buscaCoordCami(m_nodes, cami[0]))
			afegirNode(cami[0]);
		for (int j = 1; j < cami.size(); j++) {
			int ant = j - 1;
			if (!Util::buscaCoordCami(m_nodes, cami[j])) {
				afegirNode(cami[j]);
				int pos1 = cerca(cami[ant], m_nodes);
				int pos2 = cerca(cami[j], m_nodes);
				afegirAresta(pos1, pos2);
			}
			else {
				int pos1 = cerca(cami[ant], m_nodes);
				int pos2 = cerca(cami[j], m_nodes);

				afegirAresta(pos1, pos2);
			}
		}
	}

}


int GrafSolucio::minDistance(vector<float>& dist, vector<bool>& visitat) {
	float min = abs(DISTMAX), pos = -1;
	for (int posVei = 0; posVei < m_numNodes; posVei++) {
		if (!visitat[posVei] && dist[posVei] < min) {
			min = dist[posVei];
			pos = posVei;
		}
	}
	return pos;
}

float GrafSolucio::findVeiDist(int posVeiAct, int posVei) {
	list<pair<int, double>> veins;
	for (auto it = m_veins[posVeiAct].begin(); it != m_veins[posVeiAct].end(); it++) {
		if ((*it).first == posVei) {
			return (*it).second;
		}
	}
	return 0;
}

void GrafSolucio::dijkstra(int node, int node2, vector<float>& dist, vector<int>& anterior) {
	vector<bool> visitat;
	dist.resize(m_numNodes, DISTMAX);
	anterior.resize(m_numNodes, -1);
	visitat.resize(m_numNodes, false);
	dist[node] = 0;
	anterior[node] = node;
	/*list<int> S;
	list<int> Q;
	for (int u = 0; u < m_numNodes - 1; u++) {
		Q.push_back(u);
	}
	while (!Q.empty()) {
		list<int>::iterator i = min_element(Q.begin(), Q.end());
		int u = *i;
		Q.remove(u);
		S.push_back(u);
		for (auto posVei = m_veins[u].begin(); posVei != m_veins[u].end(); posVei++) {
			if (dist[u] + (*posVei).second < dist[(*posVei).first]) {
				dist[(*posVei).first] = (dist[u] + (*posVei).second);
				anterior[(*posVei).first] = u;
			}
		}
	}*/
	for (int i = 0; i < m_numNodes - 1; i++) {
		int posVeiAct = minDistance(dist, visitat);
		visitat[posVeiAct] = true;
		if (posVeiAct == node2) return;
		for (auto posVei = m_veins[posVeiAct].begin(); posVei != m_veins[posVeiAct].end(); posVei++) {
			if (!visitat[posVei->first]) {
				if (dist[posVeiAct] + posVei->second < dist[posVei->first]) {
					dist[posVei->first] = dist[posVeiAct] + posVei->second;
					anterior[posVei->first] = posVeiAct;
				}
			}
		}
	}
}

void GrafSolucio::shortestPath(Coordinate node1, Coordinate node2, CamiBase* camiSolucio) {
	int pos1 = cerca(node1, m_nodes);
	int pos2 = cerca(node2, m_nodes);
	vector<int> anterior;
	vector<float> vDist;
	dijkstra(pos1, pos2, vDist, anterior);
	int it = pos2;
	camiSolucio->addCoord(m_nodes[pos2]);
	while (it != pos1) {
		camiSolucio->addCoord(m_nodes[anterior[it]]);
		it = anterior[it];
	}

}

GrafSolucio::~GrafSolucio()
{
}
