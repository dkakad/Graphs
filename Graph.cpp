#include "Graph.h"
#include <queue>
#include <stack>

template class Node<int>;
template class Graph<int>;

template <typename T>
Graph<T>::Graph() {
	no = 0;
	nodesList = nullptr;
	edges = nullptr;
}

template <typename T>
Graph<T>::Graph(Node<T> *root) {
	no = 1;
	nodesList = new Node<T>*();
	nodesList[0] = root;
	edges = new Edge*();
	edges[0] = new Edge();
}

template <typename T>
unsigned int Graph<T>::getNo() {
	return no;
}

template <typename T>
void Graph<T>::setNo(unsigned int newNo) {
	no = newNo;
}

template <typename T>
void Graph<T>::incrNo() {
	no = no + 1;
}

template <typename T>
void Graph<T>::addNode(Node<T> *newNode) {
	Node<T> **newNodeList = new Node<T>*[no + 1];
	for (int i = 0; i < no; i++) {
		newNodeList[i] = nodesList[i];
	}
	newNodeList[no] = newNode;
	no = no + 1;
	nodesList = newNodeList;
	Edge **newEdges = new Edge*[no];
	for (int i = 0; i < no; i++) {
		newEdges[i] = new Edge[no];
	}
	for (int i = 0; i < no - 1; i++) {
		for (int j = 0; j < no - 1; j++) {
			newEdges[i][j] = edges[i][j];
		}
	}
	edges = newEdges;
}

template <typename T>
void Graph<T>::addEdge(int from, int to) {
	if (from > (no-1) || to > (no-1) || from < 0 || to < 0) {
		printf("Invalid Nodes \n");
		return;
	}
	if (edges[from][to].getAdj() == 0) {
		edges[from][to].setAdj(1);
		nodesList[from]->addNeighbour(nodesList[to]);
	}
	else {
		printf("An edge already exists between Node %d and Node %d \n", from, to);
		return;
	}
}

template <typename T>
void Graph<T>::showAdjMat() {
	printf("\n");
	printf("Printing the Adjacency Matrix \n");
	printf("  ");
	for (int i = 0; i < no; i++) {
		printf("%d ", i);
}
	printf("\n");
	for (int i = 0; i < no; i++) {
		printf("%d ", i);
		for (int j = 0; j < no; j++) {
			printf("%d ", edges[i][j].getAdj());
		}
		printf("\n");
}
	printf("\n");
	// TODO Create a representation which handles 2 digits
}


/* 
 * Assumption -> We assume that src always exist in the graph. Otherwise we have to search through the graph 
 * for src which defeats the purpose of bfs.
 */
template <typename T>
bool Graph<T>::bfs(Node<T> *src, Node<T> *dest) {
	std::queue<Node<T>*> q;
	q.push(src);
	while (!q.empty()) {
		Node<T> *temp = q.front();
		q.pop();
		if (temp->getVisited() == false) {
			temp->setVisited(true);
		}
		/* For comparison by reference */
		/*
		if (temp == dest) {
			return true;
		}
		*/
		
		/* For comparison by value */
		if (temp->getData() == dest->getData()) {
			return true;
		}
		for (int i = 0; i < temp->getNo(); i++) {
			if (temp->nodes[i]->getVisited() == false) {
				q.push(temp->nodes[i]);
			}
		}
	}
	return false;
}

template <typename T>
void Graph<T>::dfs(bool &found, Node<T>* src, Node<T> *dest) {
	if (found == true) {
		return;
	}
	src->setVisited(true);
	Node<T> *desc;
	for (int i = 0; i < src->getNo(); i++) {
		if (src->nodes[i]->getVisited() == false) {
			desc = src->nodes[i];
			if (desc == dest) {
				found = true;
				desc->setVisited(true);
				return ;
			}
			dfs(found, desc, dest);
		}
	}
	return ;
}


