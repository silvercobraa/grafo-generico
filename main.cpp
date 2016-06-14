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

	Graph<tipo> original_graph(matrix_size);
	original_graph.print();

	for (int k = 0; k < edges; k++) {
		std::cin >> i;
		std::cin >> j;
		original_graph.add_edge(1, i, j);
		std::cout << "Insertando arista " << i << " " << j << "..." << std::endl;
	}
	original_graph.print();
	// Se obtienen todas las aristas que son puentes
	std::vector<std::pair<int,int>> brigde_edges = original_graph.find_bridges();
	// Si no hay puentes, todo el análisis que sigue después no tendría sentido.
	// Por lo tanto, el programa termina
	if (brigde_edges.size() == 0)
	{
		exit(EXIT_SUCCESS);
	}
	// Si hay puentes en el grafo, sólo se usará el primero
	std::pair<int,int> first_edge = brigde_edges[0];
	std::cout << "first: " << first_edge.first << std::endl;
	std::cout << "second: " << first_edge.second << std::endl;
	// Se elimina el puente del grafo
	original_graph.delete_edge(first_edge.first, first_edge.second);
	// Se genera el subgrafo que contiene a uno de los vértices que forma la arista puente
	Graph<tipo> subgraph_1 = original_graph.get_connected_component(first_edge.first);
	subgraph_1.print();
	// Se genera el subgrafo que contiene al otro vértice que forma la arista puente
	Graph<tipo> subgraph_2 = original_graph.get_connected_component(first_edge.second);
	subgraph_2.print();
	return 0;
}
