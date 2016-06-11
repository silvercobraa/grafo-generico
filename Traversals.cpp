#ifndef TRAVERSALS_CPP
#define TRAVERSALS_CPP

#include "Traversals.h"

template <class T>
void _visit_neighbours(Graph<T>* g, int v, bool* visited)
{
	visited[v] = true;
	std::cout << "visitando vértice " <<  v << std::endl;
	std::vector<int> neighbours = g->get_neighbours(v);
	for (unsigned int neighbour = 0;  neighbour < neighbours.size(); neighbour++)
	{
		if (!visited[neighbour])
		{
			_visit_neighbours(g, neighbour, visited);
		}
	}
}


template <class T>
void DFS(Graph<T>* g, int v)
{
	std::cout << "DFS vertice " << v << ":" << std::endl;
	bool* visited = new bool[g->get_V()];
	for (int i = 0; i < g->get_V(); i++)
	{
		visited[i] = false;
	}
	_visit_neighbours(g, v, visited);
	std::cout << std::endl;
	delete visited;
}


template <class T>
void BFS(Graph<T>* g, int v)
{
	std::cout << "BFS vertice " << v << ":" << std::endl;
	bool* visited = new bool[g->get_V()];
	std::queue<int>* q = new std::queue<int>();
	std::vector<int> neighbours;
	for (int i = 0; i < g->get_V(); i++)
	{
		visited[i] = false;
	}
	q->push(v);
	while (!q->empty())
	{
		int pop = q->front();
		if (!visited[pop])
		{
			std::cout << "visitando vértice " << pop << std::endl;
		}
		q->pop();
		visited[pop] = true;
		neighbours = g->get_neighbours(pop);
		for (unsigned int neighbour; neighbour < neighbours.size(); neighbour++)
		{
			if (!visited[neighbour])
			{
				q->push(neighbour);
			}
		}
	}
	std::cout << std::endl;
	delete visited;
	delete q;
}

#endif /* end of include guard: TRAVERSALS_CPP */
