#include "Ball.h"
#include "Util.h"
#include <vector>
#include <list>

using namespace std;

class BallTree {
public:
	BallTree() { root = nullptr; }
	BallTree(const vector<Coordinate>& datapoints) { construirArbre(datapoints); }
	~BallTree() {}
	void construirArbre(const vector<Coordinate>& datapoints);
	Ball* getArrel() { return root; }

	void inOrdre(vector<list<Coordinate>>& out);
	void inOrdreRec(Ball* root, vector<list<Coordinate>>& out);

	void postOrdre(vector<list<Coordinate>>& out);
	void postOrdreRec(Ball* root, vector<list<Coordinate>>& out);

	void preOrdre(vector<list<Coordinate>>& out);
	void preOrdreRec(Ball* root, vector<list<Coordinate>>& out);

	Coordinate nodeMesProper(Coordinate pdi, Coordinate& Q, Ball* bola_arrel);

private:
	Ball* root;
};