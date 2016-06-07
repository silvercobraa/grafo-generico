#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

template <class T>
class Graph
{
private:
	int V;
	int E;
	T** adj;
public:
	Graph(int V);
	int get_V();
	int get_E();
	void add_edge(const T& e, int v1, int v2);
	// std::vector<int> get_neighbours(int v);
	int degree(int v);
	void print();
	T adjacentes();
};

#include "Graph.cpp"

#endif /* end of include guard: GRAPH_H */
