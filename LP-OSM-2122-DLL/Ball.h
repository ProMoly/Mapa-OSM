#pragma once


#include "Util.h"
#include <vector>

using namespace std;

class Ball {

public:
	Ball() {
		m_left = nullptr;
		m_right = nullptr;
		m_radi = 0.001;
		m_pivot = Coordinate{ 0.0, 0.0 };
	}

	Ball(const vector<Coordinate>& datapoints) {
		if (datapoints.size() == 1) {
			m_radi = 0;
			m_coordenades = datapoints;
			m_pivot = m_coordenades[0];
			return;
		}
		else {
			m_coordenades = datapoints;
			vector<double> distancies;
			m_pivot = Util::calcularPuntCentral(m_coordenades);
			calculaDistanciesC(distancies);
			Coordinate PuntA = m_coordenades[puntMesLlunya(distancies)];
			distancies.clear();
			calculaDistanciesA(distancies, PuntA);
			m_radi = distancies[puntMesLlunya(distancies)];
			Coordinate PuntB = m_coordenades[puntMesLlunya(distancies)];
			vector<Coordinate> datapointsL;
			vector<Coordinate> datapointsR;
			for (auto it = m_coordenades.begin(); it != m_coordenades.end(); it++) {
				double D1 = Util::DistanciaHaversine(PuntA, (*it));
				double D2 = Util::DistanciaHaversine(PuntB, (*it));
				if (D1 >= D2) {
					datapointsL.push_back(*it);
				}
				else if (D1 < D2) {
					datapointsR.push_back(*it);
				}
			}
			m_left = new Ball(datapointsL);
			m_right = new Ball(datapointsR);
		}
	}
	~Ball() {}

	void puntC() {
		m_pivot = Util::calcularPuntCentral(m_coordenades);
	}

	void calculaDistanciesC(vector<double>& distancies) {
		for (auto it = m_coordenades.begin(); it != m_coordenades.end(); it++) {
			distancies.push_back(Util::DistanciaHaversine(m_pivot, (*it)));
		}
	}

	int puntMesLlunya(const vector<double> distancies) {
		double max = distancies[0];
		int pos = 0;
		for (auto it = distancies.begin(); it != distancies.end(); it++) {
			if ((*it) > max) {
				max = (*it);
				pos = distance(distancies.begin(), it);
			}
		}
		return pos;
	}

	void calculaDistanciesA(vector<double>& distancies, const Coordinate& puntA) {

		for (auto it = m_coordenades.begin(); it != m_coordenades.end(); it++) {
			distancies.push_back(Util::DistanciaHaversine(puntA, (*it)));
		}
	}

	Coordinate getPivot() {
		return m_pivot;
	}

	double getRadi() {
		return m_radi;
	}

	Ball* getEsquerre() {
		return m_right;
	}

	Ball* getDreta() {
		return m_left;
	}

	std::vector<Coordinate>& getCoordenades() {
		return m_coordenades;
	}

	void setPivot(Coordinate pivot) {
		m_pivot = pivot;
	}

	void setRadius(double radi) {
		m_radi = radi;
	}

	void setEsquerre(Ball* right) {
		m_right = right;
	}

	void setDreta(Ball* left) {
		m_left = left;
	}

	void setCoordenades(std::vector<Coordinate>& coordenades) {
		m_coordenades = coordenades;
	}


private:
	Ball* m_left = nullptr;
	Ball* m_right = nullptr;
	double m_radi;
	Coordinate m_pivot;
	std::vector<Coordinate> m_coordenades;

};

