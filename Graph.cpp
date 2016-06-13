#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <vector>
#include "Graph.h"
#include "Traversals.h"

template<class T>
Graph<T>::Graph(int V)
{
	this->V = V;
	this->E = 0;
	adj = new T*[V];
	for (int i = 0; i < V; i++)
	{
		adj[i] = new T[V];
	}
}
template<class T>
int Graph<T>::get_V()
{
	return V;
}

template<class T>
int Graph<T>::get_E()
{
	return E;
}

template<class T>
void Graph<T>::add_edge(const T& e, int v1, int v2)
{
	_validate_index(v1);
	_validate_index(v2);
	adj[v1][v2] = e;
	adj[v2][v1] = e;
	E++;
}

template<class T>
int Graph<T>::degree(int v)
{
	_validate_index(v);
	int deg = 0;
	for (int i = 0; i < V; i++)
	{
		if (adj[v][i] != (T)NULL)
		{
			deg++;
		}
	}
	return deg;
}

template<class T>
T Graph<T>::get_edge(int v1, int v2)
{
	_validate_index(v1);
	_validate_index(v2);
	return adj[v1][v2];
}

template<class T>
void Graph<T>::delete_edge(int v1, int v2)
{
	if (adj[v1][v2] == (T)NULL)
	{
		std::cout << "no existe la arista " << v1 << "," << v2 << std::endl;
		throw MISSING_EDGE;
	}
	else
	{
		adj[v1][v2] = (T)NULL;
		E--;
	}
}

template<class T>
void Graph<T>::print()
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			std::cout << adj[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template<class T>
std::vector<int> Graph<T>::get_neighbours(int v)
{
	std::vector<int> neighbours;
	for (int i = 0; i < V; i++)
	{
		if (adj[v][i] != NULL_VALUE)
		{
			neighbours.push_back(i);
		}
	}
	return neighbours;
}

template<class T>
void Graph<T>::_validate_index(int index)
{
	if (index < 0 || index >= V )
	{
		std::cout << "índice " << index << " fuera de rango" << std::endl;
		throw INDEX_OUT_OF_RANGE;
	}
}

template<class T>
Graph<T> Graph<T>::clone()
{
	Graph<T> g(this->get_V());
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			g.add_edge(this->get_edge(i,j), i, j);
		}
	}
	return g;
}

template<class T>
Graph<T> Graph<T>::subgraph(std::vector<int> positions)
{
	Graph<T> g(positions.size());
	for (unsigned int i = 0; i < positions.size(); i++)
	{
		for (unsigned int j = 0; j < positions.size(); j++)
		{
			/**
			 * La siguiente linea no funcionaba porque estaba insertando las
			 *  aristas correpondientes a los índices del vector, cuando
			 * debían ser los elementos del vector asociados a esos índices
			 */
			// g.add_edge(this->get_edge(i,j), i, j);
			g.add_edge(this->get_edge(positions[i], positions[j]), i, j);
		}
	}
	return g;
}

template<class T>
 Graph<T> Graph<T>::get_connected_component(int v)
{
	//return subgraph(DFS(this, v));
	return subgraph(BFS(this, v));
}
#endif /* end of include guard: GRAPH_CPP */
