#include "Graph.h"
#include <stdlib.h>
#include <time.h>

void randomGraph(Graph<int> *g, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		int c = rand() % n;
		Node<int> *n = new Node<int>(c);
		g->addNode(n);
	}
	for (int i = 0; i < 2 * n; i++) {
		int a = rand() % n;
		int b = rand() % n;
		g->addEdge(a, b);
	}
	g->showAdjMat();
}

void testGraph(Graph<int> *g, int n) {
	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		Node<int> *n = new Node<int>(i);
		g->addNode(n);
	}
	
	
	for (int i = 0; i < n; i++) {
		g->addEdge(i, i * 2 + 1);
		//g->addEdge(i, n - i * 2 + 1);
	}
	g->addEdge(0, 1);
	g->addEdge(1, 2);
	
	/*
	Node<int> *n1 = new Node<int>(0);
	Node<int> *n2 = new Node<int>(1);
	Node<int> *n3 = new Node<int>(2);
	g->addNode(n1);
	g->addNode(n2);
	g->addNode(n3);
	g->addEdge(0, 1);
	g->addEdge(0, 2);
	*/
	g->showAdjMat();
	//int n1 = rand() % n;
	//int n2 = rand() % n;

	int n1 = 0;
	int n2 = 3;

	Node<int> *a = g->nodesList[n1];
	Node<int> *b = g->nodesList[n2];

	printf("Running dfs for node %d and node %d \n", n1, n2);
	bool found = false;
	g->dfs(found, a, b);
	if (found) {
		printf("Found \n");
	}
	else {
		printf("Not Found \n");
	}
}

void TestDfs(Graph<int> *g, int n) {
	Node<int> *n0 = new Node<int>(0);
	Node<int> *n1 = new Node<int>(1);
	Node<int> *n2 = new Node<int>(2);
	Node<int> *n3 = new Node<int>(3);
	Node<int> *n4 = new Node<int>(4);
	Node<int> *n5 = new Node<int>(5);
	Node<int> *n6 = new Node<int>(6);
	Node<int> *n7 = new Node<int>(7);
	Node<int> *n8 = new Node<int>(8);
	Node<int> *n9 = new Node<int>(9);
	g->addNode(n0);
	g->addNode(n1);
	g->addNode(n2);
	g->addNode(n3);
	g->addNode(n4);
	g->addNode(n5);
	g->addNode(n6);
	g->addNode(n7);
	g->addNode(n8);
	g->addNode(n9);
	g->addEdge(0, 1);
	g->addEdge(0, 2);
	g->addEdge(1, 3);
	g->addEdge(1, 4);
	g->addEdge(2, 5);
	//g->addEdge(2, 6);
	g->addEdge(3, 7);
	g->addEdge(3, 8);
	g->addEdge(7, 9);
	g->showAdjMat();

	int x = 0;
	int y = 4;

	Node<int> *a = g->nodesList[x];
	Node<int> *b = g->nodesList[y];

	printf("Running dfs for node %d and node %d \n", x, y);
	bool found = false;
	g->dfs(found, a, b);
	if (found) {
		printf("Found \n");
	}
	else {
		printf("Not Found \n");
	}
}

int main() {
	/*
	Node<int> *n = new Node<int>(4);
	Graph<int> *g = new Graph<int>(n);
	Node<int> *n1 = new Node<int>(8);
	Node<int> *n2 = new Node<int>(16);
	g->addNode(n1);
	g->addNode(n2);
	g->addEdge(0, 1);
	g->addEdge(0, 2);
	g->addEdge(0, 2);
	g->showAdjMat();
	printf("Neighbours are %d \n", g->nodesList[0]->nodes[1]->getData());
	*/
	Graph<int> *g = new Graph<int>();
	//randomGraph(g, 10);
	TestDfs(g, 10);
	return 0;
}