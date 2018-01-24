#include "Node.h"

template <typename T>
Node<T>::Node() {
	data = NULL;
	no = 0;
	nodes = nullptr;
	visited = false;
}

template <typename T>
Node<T>::Node(T newData) {
	data = newData;
	no = 0;
	nodes = nullptr;
	visited = false;
}

template <typename T>
T Node<T>::getData() {
	return data;
}

template <typename T>
void Node<T>::SetData(T newData) {
	data = newData;
}

template <typename T>
unsigned int Node<T>::getNo() {
	return no;
}

template <typename T>
void Node<T>::setNo(unsigned int newNo) {
	no = newNo;
}

template <typename T>
void Node<T>::incrNo() {
	no = no + 1;
}

template <typename T>
bool Node<T>::getVisited() {
	return visited;
}
template <typename T>
void Node<T>::setVisited(bool flag) {
	visited = flag;
}

template <typename T>
void Node<T>::addNeighbour(T newData) {
	Node<T>* newNode = new Node<T>(newData);
	if (nodes == nullptr) {
		nodes = new Node<T>*();
		nodes[0] = newNode;
		no = no + 1;
	}
	else {
		Node<T> **newNeigh = new Node<T>*[no + 1];
		for (int i = 0; i < no; i++) {
			newNeigh[i] = nodes[i];
		}
		newNeigh[no] = newNode;
		nodes = newNeigh;
		no = no + 1;
	}
}

template <typename T>
void Node<T>::addNeighbour(Node<T> * newNode) {
	if (nodes == nullptr) {
		nodes = new Node<T>*();
		nodes[0] = newNode;
		no = no + 1;
	}
	else {
		Node<T> **newNeigh = new Node<T>*[no + 1];
		for (int i = 0; i < no; i++) {
			newNeigh[i] = nodes[i];
		}
		newNeigh[no] = newNode;
		nodes = newNeigh;
		no = no + 1;
	}
}