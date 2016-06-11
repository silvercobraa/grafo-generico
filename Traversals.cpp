#ifndef TRAVERSALS_CPP
#define TRAVERSALS_CPP

#include "Traversals.h"

template <class T>
void _visit_neighbours(Graph<T>* g, int v, bool* visited, std::vector<int>* visited_vertices)
{
	if (!visited[v])
	{
		visited_vertices->push_back(v);
	}
	visited[v] = true;
	std::cout << "visitando vértice " <<  v << std::endl;
	std::vector<int> neighbours = g->get_neighbours(v);
	for (int neighbour : neighbours)
	{
		if (!visited[neighbour])
		{
			_visit_neighbours(g, neighbour, visited, visited_vertices);
		}
	}
}


template <class T>
std::vector<int> DFS(Graph<T>* g, int v)
{
	std::cout << "DFS vertice " << v << ":" << std::endl;
	bool* visited = new bool[g->get_V()];
	std::vector<int> visited_vertices;
	for (int i = 0; i < g->get_V(); i++)
	{
		visited[i] = false;
	}
	_visit_neighbours(g, v, visited, &visited_vertices);
	std::cout << std::endl;
	delete visited;
	return visited_vertices;
}


template <class T>
std::vector<int> BFS(Graph<T>* g, int v)
{
	std::cout << "BFS vertice " << v << ":" << std::endl;
	bool* visited = new bool[g->get_V()];
	std::queue<int>* q = new std::queue<int>();
	std::vector<int> neighbours;
	std::vector<int> visited_vertices;
	for (int i = 0; i < g->get_V(); i++)
	{
		visited[i] = false;
	}
	q->push(v);
	//visited_vertices.push_back(v); // Esta de más porque visito el vertice al sacarlo de la cola
	while (!q->empty())
	{
		int pop = q->front();
		if (!visited[pop])
		{
			std::cout << "visitando vértice " << pop << std::endl;
			visited_vertices.push_back(pop);
		}
		q->pop();
		visited[pop] = true;
		neighbours = g->get_neighbours(pop);
		for (int neighbour : neighbours)
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
	return visited_vertices;
}

#endif /* end of include guard: TRAVERSALS_CPP */
