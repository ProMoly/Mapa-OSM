#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include "CamiSolucio.h"
#include "CamiBase.h"
#include "Common.h"
#include "Util.h"
using namespace std;

class GrafSolucio
{
public:

	GrafSolucio();
	GrafSolucio(vector<CamiBase*> camins);
	//GrafSolucio(vector<Coordinate>& nodes, vector<list<pair<int, double>>> parellesNodes, vector<double> pesos);
	~GrafSolucio();

	void afegirAresta(int posNode1, int posNode2);
	void afegirNode(const Coordinate& node);

	int minDistance(vector<float>& dist, vector<bool>& visitat);
	float findVeiDist(int posVeiAct, int posVei);
	int cerca(const Coordinate cerca, const vector<Coordinate> nodes);
	void dijkstra(int node1, int node2, vector<float>& dist, vector<int>& anterior);
	void shortestPath(Coordinate node1, Coordinate node2, CamiBase* camiSolucio);



private:
	vector<Coordinate> m_nodes;
	vector<list<pair<int, double>>> m_veins;
	int m_numNodes;
	int m_numArestes;
	//void crearMatriu(vector<list<pair<int, double>>> parelles);
	const int DISTMAX = 2147483647;

};