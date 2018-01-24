#include "Edge.h"

Edge::Edge() {
	adj = 0;
}

int Edge::getAdj() {
	return adj;
}

void Edge::setAdj(int newAdj) {
	adj = newAdj;
}