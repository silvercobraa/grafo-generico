#include <iostream>
#include <complex>
#include "Graph.h"
#include "Edge.h"

typedef std::complex<float> tipo_t;

int main(int argc, char const* argv[])
{
	int matrix_size = 0;
	int edges = 0;
	int i = 0;
	int j = 0;
	tipo_t admitance;

	std::cin >> matrix_size;
	std::cin >> edges;

	Graph<tipo_t> original_graph(matrix_size);
	original_graph.print();

	for (int k = 0; k < edges; k++)
	{
		std::cin >> i;
		std::cin >> j;
		std::cin >> admitance;
		original_graph.add_edge(-admitance, i, j); // Se guardan con signo opuesto
		// DESCOMENTAR LA SIGUIENTE LINEA PARA DEBUGUEO FACIL
		// original_graph.add_edge(-std::complex<float>(i,j), i, j);
		std::cout << "Insertando arista " << i << " " << j << "..." << std::endl;
		std::cout << admitance << std::endl;
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
	// Se elimina el puente del grafo
	original_graph.delete_edge(first_edge.first, first_edge.second);
	original_graph.print();
	// Se genera el subgrafo que contiene a uno de los vértices que forma la arista puente
	Graph<tipo_t> subgraph_1 = original_graph.get_connected_component(first_edge.first);
	subgraph_1.print();
	// Se genera el subgrafo que contiene al otro vértice que forma la arista puente
	Graph<tipo_t> subgraph_2 = original_graph.get_connected_component(first_edge.second);
	subgraph_2.print();

	std::complex<float> suma;
	// Llena las admitancias de la diagonal de la submatriz 1
	for (int i = 0; i < subgraph_1.get_V(); i++)
	{
		suma = 0.0 + 0.0i;
		std::vector<int> neighbours = subgraph_1.get_neighbours(i);
		for (unsigned int j = 0; j < neighbours.size(); j++)
		{
			suma += subgraph_1.get_edge(i, neighbours[j]);
		}
		if (neighbours.size() > 0)
		{
			subgraph_1.add_edge(-suma, i, i); // La diagonal debe llevar signo opuesto
		}
	}
	// Llena las admitancias de la diagonal de la submatriz 1
	for (int i = 0; i < subgraph_2.get_V(); i++)
	{
		suma = 0.0 + 0.0i;
		std::vector<int> neighbours = subgraph_2.get_neighbours(i);
		for (unsigned int j = 0; j < neighbours.size(); j++)
		{
			suma += subgraph_2.get_edge(i, neighbours[j]);
		}
		if (neighbours.size() > 0)
		{
			subgraph_2.add_edge(-suma, i, i); // La diagonal debe llevar signo opuesto
		}
	}

	subgraph_1.print();
	subgraph_2.print();
	return 0;
}
