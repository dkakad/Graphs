#pragma once

#include <stdio.h>

template <typename T>
class Node {
	T data;
	unsigned int no;
	bool visited;
public:
	Node<T>** nodes;
	Node();
	Node(T newData);
	T getData();
	void SetData(T newData);
	unsigned int getNo();
	void setNo(unsigned int newNo);
	void incrNo();
	bool getVisited();
	void setVisited(bool flag);
	void addNeighbour(T newData);
	void addNeighbour(Node<T>* newNode);
};

