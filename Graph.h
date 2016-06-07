#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

/**
 * Clase que representa un grafo no dirigido con cantidad de nodos fija,
 * implementado con matriz de adyacencia.
 */
template <class T>
class Graph
{
private:

	/**
	 * Cantidad de vértices de este grafo.
	 */
	int V;

	/**
	 * Cantidad de aristas de este grafo.
	 */
	int E;

	/**
	 * Matriz de adyacencia.
	 */
	T** adj;

public:

	/**
	 * Crea un grafo de V nodos, inicialmente sin aristas.
	 */
	Graph(int V);

	/**
	 * Retorna la cantidad de vértices de este grafo.
	 */
	int get_V();

	/**
	 * Retorna la cantidad de aristas de este grafo.
	 */
	int get_E();

	/**
	 * Agrega una arista al grafo. Coloca el objeto e en la posicion [v1][v2] de
	 * la matriz de adyacencia. Si dicha arista ya existe, es reemplazada por
	 * la nueva.
	 */
	void add_edge(const T& e, int v1, int v2);
	// std::vector<int> get_neighbours(int v);

	/**
	 * Retorna la cantidad de aristas incidentes al nodo v.
	 */
	int degree(int v);
	void print();
	T adjacentes();
};

#include "Graph.cpp"

#endif /* end of include guard: GRAPH_H */
