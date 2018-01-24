#pragma once
#include "Node.h"
#include "Node.cpp"
#include "Edge.h"

template <typename T>
class Graph {
	unsigned int no;
public:
	Node<T> **nodesList;
	Edge **edges;
	Graph();
	Graph(Node<T> *root);
	unsigned int getNo();
	void setNo(unsigned int newNo);
	void incrNo();
	void addNode(Node<T> *newNode);
	//void deleteNode(Node<T> *delNode);
	void addEdge(int a, int b);
	void showAdjMat();
	bool bfs(Node<T> *src, Node<T> *dest);
	void dfs(bool &found, Node<T> *src, Node<T> *dest);
	void Search(Node<T> *n);
};