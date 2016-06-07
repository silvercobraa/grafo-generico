#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <vector>
#include "Graph.h"

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
	// Los vértices están enumerados a partir del uno
	// adj[v1-1][v2-1] = e;
	// adj[v2-1][v1-1] = e;

	// Los vértices están enumerados a partir del cero
	adj[v1][v2] = e;
	adj[v2][v1] = e;
	E++;
}

/*template<class T>
std::vector<int> Graph<T>::get_neighbours(int v)
{
	std::vector<int> neighbours;
	for (int i = 0; i < V; i++)
	{
		if (adj[v -1][i] == 1)
		{
			neighbours.push_back(i+1);
		}
	}
	return neighbours;
}*/

/*template<class T>
int Graph<T>::degree(int v)
{
	int deg = 0;
	for (int i = 0; i < V; i++)
	{
		if (adj[v -1][i] == 1)
		{
			deg++;
		}
	}
	return deg;
}*/

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
T Graph<T>::adjacentes()
{

}

template<class T>
int Graph<T>::grado()
{

}


#endif /* end of include guard: GRAPH_CPP */
