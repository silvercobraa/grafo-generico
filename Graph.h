#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <tuple>

/**
 * Valor que se lanza cuando se intenta acceder a un índice no válido en la
 * matriz de adyacencia.
 */
#define INDEX_OUT_OF_RANGE -1;

/**
 * Valor que se retorna cuando se intenta acceder a una arista que no existe.
 */
#define MISSING_EDGE -2;

/**
 * Valor usado como NULL de tipo T.
 */
#define NULL_VALUE ((T)0)


/**
 * Clase que representa un grafo no dirigido con cantidad de nodos fija,
 * implementado con matriz de adyacencia.
 */
template <typename T>
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
	 * Matriz de adyacencia de este grafo.
	 */
	T** adj;

	/**
	 * Lanza una excepción INDEX_OUT_OF_RANGE si index no está en el rango
	 * [0, V-1]
	 */
	void _validate_index(int index);

	/*
	 * Funcion dfs auxiliar
	 */
	//void _dfs(int v, int P, int* t, int* visited, int* low);
	void _dfs_2(int v, int P, int* t, int* visited, int* low, std::vector<std::pair<int, int>>* briges);

public:

	/**
	 * Crea un grafo de V nodos, inicialmente sin aristas.
	 * O(1)
	 */
	Graph(int V);

	/**
	 * Retorna la cantidad de vértices de este grafo.
	 * O(1)
	 */
	int get_V();

	/**
	 * Retorna la cantidad de aristas de este grafo.
	 * O(1)
	 */
	int get_E();

	/**
	 * Agrega una arista al grafo. Coloca el objeto e en la posicion [v1][v2] de
	 * la matriz de adyacencia. Si dicha arista ya existe, es reemplazada por
	 * la nueva.
	 * O(1)
	 */
	void add_edge(const T& e, int v1, int v2);

	/**
	 * Retorna la cantidad de aristas incidentes al nodo v.
	 * O(n)
	 */
	int degree(int v);

	/**
	 * Retorna la arista que conecta los vértices v1 y v2. Retorna valor nulo si
	 * dichos vértices no están conectados.
	 * O(1)
	 */
	T get_edge(int v1, int v2);

	/**
	 * Elimina la arista que conecta los vértices v1 y v2, si existe.
	 * O(1)
	 */
	void delete_edge(int v1, int v2);

	/**
	 * Reemplaza la arista que conecta los vértices v1 y v2, si existe.
	 * O(1)
	 */
	void replace_edge(T new_edge, int v1, int v2);

	/**
	 * Imprime los elementos de la matriz.
	 * O(n²)
	 */
	void print();

	/**
	 * Retorna un vector con los vértices adjacentes al vértice v.
	 * O(n)
	 */
	std::vector<int> get_neighbours(int v);

	/**
	 * Retorna una copia de este grafo. Si T es un puntero a un objeto, solo se
	 * copiará el puntero.
	 * O(n²)
	 */
	Graph<T> clone();

	/**
	 * Retorna un grafo que contiene sólo los vértices incluidos en el vector
	 * positions y sólo las aristas que conectan dichos vértices, si existen en
	 * el grafo original. Las aristas de este subgrafo son copias de las
	 * aristas originales.
	 * O(tamaño_vector²)
	 */
	Graph<T> subgraph(std::vector<int> positions);

	/**
	 * Retorna la componente conexa a la que pertence el vértice v.
	 * O(me_fui_a_la_mierda)
	 */
	Graph<T> get_connected_component(int v);

	/**
	 * Encuentra todas las aristas de este grafo que son puentes. Retorna un
	 * vector de pares de vértices.
	 */
	std::vector<std::pair<int, int>> find_bridges();

	/**
	 * Retorna la matriz de adjacencia asociada a este grafo.
	 * O(1)
	 */
	T** get_adjacency_matrix();

};

#include "Graph.cpp"

#endif /* end of include guard: GRAPH_H */
