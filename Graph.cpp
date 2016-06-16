#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <vector>
#include "Graph.h"
#include "Traversals.h"

template<typename T>
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


template<typename T>
int Graph<T>::get_V()
{
	return V;
}


template<typename T>
int Graph<T>::get_E()
{
	return E;
}


template<typename T>
void Graph<T>::add_edge(const T& e, int v1, int v2)
{
	_validate_index(v1);
	_validate_index(v2);
	adj[v1][v2] = e;
	adj[v2][v1] = e;
	E++;
}


template<typename T>
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


template<typename T>
T Graph<T>::get_edge(int v1, int v2)
{
	_validate_index(v1);
	_validate_index(v2);
	return adj[v1][v2];
}


template<typename T>
void Graph<T>::delete_edge(int v1, int v2)
{
	if (adj[v1][v2] == NULL_VALUE || adj[v2][v1] == NULL_VALUE)
	{
		std::cout << "no existe la arista " << v1 << "," << v2 << std::endl;
		throw MISSING_EDGE;
	}
	else
	{
		//adj[v1][v2] = (T)NULL;
		adj[v1][v2] = NULL_VALUE;
		adj[v2][v1] = NULL_VALUE;
		E--;
	}
}


template<typename T>
void Graph<T>::replace_edge(T new_edge, int v1, int v2)
{
	if (adj[v1][v2] == NULL_VALUE || adj[v2][v1] == NULL_VALUE)
	{
		std::cout << "no existe la arista " << v1 << "," << v2 << std::endl;
		throw MISSING_EDGE;
	}
	else if (new_edge == NULL_VALUE)
	{
		std::cout << "La arista no debe ser nula" << std::endl;
		throw -3; // TODO: buscar una manera más elegante de lanzar excepciones
	}
	else
	{
		adj[v1][v2] = new_edge;
		adj[v2][v1] = new_edge;
	}
}


template<typename T>
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


template<typename T>
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


template<typename T>
void Graph<T>::_validate_index(int index)
{
	if (index < 0 || index >= V)
	{
		std::cout << "índice " << index << " fuera de rango" << std::endl;
		throw INDEX_OUT_OF_RANGE;
	}
}


template<typename T>
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

template<typename T>
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

template<typename T>
Graph<T> Graph<T>::get_connected_component(int v)
{
	//return subgraph(DFS(this, v));
	return subgraph(BFS(this, v));
}

template<typename T>
T** Graph<T>::get_adjacency_matrix()
{
	return adj;
}


template<typename T>
std::vector<std::pair<int, int>> Graph<T>::find_bridges()
{
	int visited[get_V()];
	int low[get_V()];
	int t = 1;
	std::vector<std::pair<int, int>> bridges;

	for (int i = 0; i < get_V(); i++)
	{
		visited[i] = 0;
		low[i] = 0;
	}
	_dfs_2(0, 0, &t, &visited[0], &low[0], &bridges);
	return bridges;
}


// http://csengerg.github.io/2015/12/26/pre-order-travelsal-and-tarjans-algorithm.html
template<typename T>
void Graph<T>::_dfs_2(int v, int parent, int* id, int* pre, int* l, std::vector<std::pair<int, int>>* bridges)
{
	pre[v] = (*id)++;
	l[v] = pre[v];// in the beginning this is the lowest label what we reach from here
	std::vector<int> vec = get_neighbours(v);
	for (unsigned int i = 0; i < vec.size(); ++i)
	{
		int w = vec[i];
		if (pre[w] == 0)
		{
			_dfs_2(w,v, id, pre, l, bridges);

			// the lowest label for vertex v equals with the minimum label of it's children
			l[v] = l[v] < l[w] ? l[v] : l[w];

			if (l[w] == pre[w]) //for w our statement is true, so we found a bridge
			{
				std::cout << "La arista " << v << " " << w << " es un puente!" << std::endl;
				bridges->push_back(std::pair<int,int>(v, w));
			}
		}
		else if (w != parent)   // we check all reachable vertices, doesn't matter, that we explored them before or not
		{
			l[v] = l[v] < l[w] ? l[v] : l[w];
		}
	}
}

#endif /* end of include guard: GRAPH_CPP */
