#include <iostream>
#include <complex>
#include "Graph.h"
#include "Edge.h"

typedef int tipo;

int main(int argc, char const* argv[])
{
    int matrix_size = 0;
    int edges = 0;
    int i = 0;
    int j = 0;
	std::complex<float> admitance;

    std::cin >> matrix_size;
    std::cin >> edges;

	std::complex<float> admitance_matrix[matrix_size][matrix_size];
    Graph<tipo> original_graph(matrix_size);
    original_graph.print();

    for (int k = 0; k < edges; k++)
    {
        std::cin >> i;
        std::cin >> j;
		std::cin >> admitance;
        original_graph.add_edge(1, i, j);
        std::cout << "Insertando arista " << i << " " << j << "..." << std::endl;
		admitance_matrix[i][j] = admitance;
		admitance_matrix[j][i] = admitance;
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
    // Se genera el subgrafo que contiene a uno de los vértices que forma la arista puente
    //Graph<tipo> subgraph_1 = original_graph.get_connected_component(first_edge.first);
    //subgraph_1.print();
    // Se genera el subgrafo que contiene al otro vértice que forma la arista puente
    //Graph<tipo> subgraph_2 = original_graph.get_connected_component(first_edge.second);
    //subgraph_2.print();
	// obtengo todos los vértices del subrafo 1
	std::vector<int> v1 = DFS(&original_graph, first_edge.first);
	for (unsigned int i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << std::endl;
	}
	std::cout << std::endl;
	// obtengo todos los vértices del subrafo 2
	std::vector<int> v2 = DFS(&original_graph, first_edge.second);
	for (unsigned int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}
	std::cout << std::endl;

	std::complex<float> submatrix_1[v1.size()][v1.size()];
	std::complex<float> submatrix_2[v2.size()][v2.size()];
	// Llena las admitancias de la submatriz 1 e imprime
	for (unsigned int i = 0; i < v1.size(); i++)
	{
		for (unsigned int j = 0; j < v1.size(); j++)
		{

			submatrix_1[i][j] = -admitance_matrix[v1[i]][v1[j]];
			std::cout << submatrix_1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	// Llena las admitancias de la submatriz 2 e imprime
	for (unsigned int i = 0; i < v2.size(); i++)
	{
		for (unsigned int j = 0; j < v2.size(); j++)
		{
			submatrix_2[i][j] = -admitance_matrix[v2[i]][v2[j]];
			std::cout << submatrix_2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::complex<float> suma;
	// Llena las admitancias de la diagonal de la submatriz 1
	for (unsigned int i = 0; i < v1.size(); i++)
	{
		suma = 0.0 + 0.0i;
		for (unsigned int j = 0; j < v1.size(); j++)
		{
			suma += admitance_matrix[v1[i]][v1[j]];
		}
		submatrix_1[i][i] = suma;
	}
	// Llena las admitancias de la diagonal de la submatriz 2
	for (unsigned int i = 0; i < v2.size(); i++)
	{
		suma = 0.0 + 0.0i;
		for (unsigned int j = 0; j < v2.size(); j++)
		{
			suma += admitance_matrix[v2[i]][v2[j]];
		}
		submatrix_2[i][i] = suma;
	}
	// Imprime la submatriz 1
	for (unsigned int i = 0; i < v1.size(); i++)
	{
		for (unsigned int j = 0; j < v1.size(); j++)
		{
			std::cout << submatrix_1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	// Imprime la submatriz 2
	for (unsigned int i = 0; i < v2.size(); i++)
	{
		for (unsigned int j = 0; j < v2.size(); j++)
		{
			std::cout << submatrix_2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
    return 0;
}
