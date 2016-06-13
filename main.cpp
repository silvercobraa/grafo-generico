#include <iostream>
#include "Graph.h"
#include "Edge.h"

typedef int tipo;

int main(int argc, char const *argv[])
{
	int matrix_size = 0;
	int edges = 0;
	int i = 0;
	int j = 0;

	std::cin >> matrix_size;
	std::cin >> edges;

	Graph<tipo> g(matrix_size);
	g.print();

	for (int k = 0; k < edges; k++) {
		std::cin >> i;
		std::cin >> j;
		g.add_edge(1, i, j);
		std::cout << "Insertando arista " << i << " " << j << "..." << std::endl;
	}
	g.print();
	//std::vector<int> v = g.get_neighbours(5);
	//std::cout << "size v:" << v.size() << std::endl;
	//for (unsigned int i = 0; i < v.size(); i++)
	//{
	//std::cout << "v[" << i << "]: " << v[i] << std::endl;
	//}
	g.find_bridges();
	//std::vector<int> aux;
	//aux.push_back(4);
	//aux.push_back(5);
	//aux.push_back(6);
	//Graph<tipo> g2 = g.subgraph(aux);
	//g2.print();
	return 0;
}
