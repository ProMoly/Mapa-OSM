#include "pch.h"
#include "BallTree.h"

using namespace std;

void BallTree::construirArbre(const vector<Coordinate>& datapoints) {
	root = new Ball(datapoints);
}

void BallTree::inOrdre(vector<list<Coordinate>>& out) {
	if (root == nullptr) {
		return;
	}
	else {
		inOrdreRec(root, out);
	}
}

void BallTree::inOrdreRec(Ball* root, vector<list<Coordinate>>& out) {
	if (root == nullptr) {
		return;
	}
	else {
		inOrdreRec(root->getEsquerre(), out);
		list<Coordinate> nodes;
		for (auto it = root->getCoordenades().begin(); it != root->getCoordenades().end(); it++)
			nodes.push_back(*it);
		out.push_back(nodes);
		nodes.clear();
		inOrdreRec(root->getDreta(), out);
	}
}

void BallTree::postOrdre(vector<list<Coordinate>>& out) {
	if (root == nullptr) {
		return;
	}
	else {
		postOrdreRec(root, out);
	}
}
void BallTree::postOrdreRec(Ball* root, vector<list<Coordinate>>& out) {
	if (root == nullptr) {
		return;
	}
	else {
		postOrdreRec(root->getEsquerre(), out);
		postOrdreRec(root->getDreta(), out);

		list<Coordinate> nodes;
		for (auto it = root->getCoordenades().begin(); it != root->getCoordenades().end(); it++)
			nodes.push_back(*it);
		out.push_back(nodes);
		nodes.clear();
	}
}

void BallTree::preOrdre(vector<list<Coordinate>>& out) {
	if (root == nullptr) {
		return;
	}
	else {
		preOrdreRec(root, out);
	}
}
void BallTree::preOrdreRec(Ball* root, vector<list<Coordinate>>& out) {
	if (root == nullptr) {
		return;
	}
	else {
		list<Coordinate> nodes;
		for (auto it = root->getCoordenades().begin(); it != root->getCoordenades().end(); it++)
			nodes.push_back(*it);
		out.push_back(nodes);
		nodes.clear();
		preOrdreRec(root->getEsquerre(), out);
		preOrdreRec(root->getDreta(), out);


	}
}


Coordinate BallTree::nodeMesProper(Coordinate pdi, Coordinate& Q, Ball* bola_arrel) {
	double D1 = Util::DistanciaHaversine(pdi, bola_arrel->getPivot());
	double D2 = Util::DistanciaHaversine(Q, bola_arrel->getPivot());

	if (D1 - bola_arrel->getRadi() >= D2) {
		return Q;
	}
	else {
		if (bola_arrel->getDreta() == nullptr && bola_arrel->getEsquerre() == nullptr) {
			double distanciaActual = Util::DistanciaHaversine(pdi, Q);
			double distancia = Util::DistanciaHaversine(pdi, bola_arrel->getCoordenades()[0]);
			if (distancia < distanciaActual) {
				Q = bola_arrel->getCoordenades()[0];
			}
			return Q;


		}
		else {
			double Da = Util::DistanciaHaversine(pdi, bola_arrel->getDreta()->getPivot());
			double Db = Util::DistanciaHaversine(pdi, bola_arrel->getEsquerre()->getPivot());
			if (Da < Db) {
				nodeMesProper(pdi, Q, bola_arrel->getEsquerre());
				nodeMesProper(pdi, Q, bola_arrel->getDreta());
			}
			else if (Da >= Db) {
				nodeMesProper(pdi, Q, bola_arrel->getDreta());
				nodeMesProper(pdi, Q, bola_arrel->getEsquerre());
			}
		}
		return Q;
	}
}
