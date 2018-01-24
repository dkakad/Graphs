#pragma once
#include <stdio.h>

class Edge {
	//double weight;
	int adj;
public:
	Edge();
	int getAdj();
	void setAdj(int newAdj);
};