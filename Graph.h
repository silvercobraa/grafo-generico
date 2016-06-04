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
	Graph(int V)
	{
		this->V = V;
		this->E = 0;
		adj = new T*[V];
		for (int i = 0; i < V; i++)
		{
			adj[i] = new T[V];
		}
	}

	int get_V()
	{
		return V;
	}

	int get_E()
	{
		return E;
	}

	void add_edge(const T& e, int v1, int v2)
	{
		adj[v1-1][v2-1] = e;
		adj[v2-1][v1-1] = e;
		E++;
	}

	/*std::vector<int> get_neighbours(int v)
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

	/*int degree(int v)
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

	void print()
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

	T adjacentes();
	int grado();
};


#endif /* end of include guard: GRAPH_H */
