#include <iostream>
#include <fstream>
#include <complex>
#include "Graph.h"
#include "Edge.h"

typedef std::complex<float> type_t;

void calculate_diagonal(Graph<type_t>& g);

int main(int argc, char const* argv[])
{
	int matrix_size = 0;
	int edges = 0;
	int i = 0;
	int j = 0;
	type_t admitance;
	std::ifstream list("List.txt");

	std::cout << "INICIALIZACIÓN" << std::endl;
	std::cout << "==============" << std::endl;
	list >> matrix_size;
	list >> edges;
	Graph<type_t> original_graph(matrix_size);
	std::cout << "Cantidad máxima de vértices: " << matrix_size << std::endl;
	std::cout << "Cantidad de aristas a leer: " << edges << std::endl;
	std::cout << "Creando grafo vacío de tamaño " << matrix_size << "..." << std::endl;
	original_graph.print();

	std::cout << "LECTURA" << std::endl;
	std::cout << "=======" << std::endl;
	std::cout << "(Las admitancias se guardan con signos opuestos)" << std::endl;
	for (int k = 0; k < edges; k++)
	{
		list >> i;
		list >> j;
		list >> admitance;
		original_graph.add_edge(-admitance, i, j); // Se guardan con signo opuesto
		// DESCOMENTAR LA SIGUIENTE LINEA PARA DEBUGUEO FACIL
		// original_graph.add_edge(-std::complex<float>(i,j), i, j);
		std::cout << "Insertando arista " << i << " " << j << "..." << std::endl;
		std::cout << admitance << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Matriz de adyacencia resultante:" << std::endl;
	original_graph.print();

	std::cout << "BÚSQUEDA DE PUENTES" << std::endl;
	std::cout << "===================" << std::endl;
	// Se obtienen todas las aristas que son puentes
	std::cout << "Aplicando Tarjan..." << std::endl;
	std::vector<std::pair<int,int>> brigde_edges = original_graph.find_bridges();
	// Si no hay puentes, todo el análisis que sigue después no tendría sentido.
	// Por lo tanto, el programa termina
	if (brigde_edges.size() == 0)
	{
		std::cout << "El grafo no contiene puentes." << std::endl;
		exit(EXIT_SUCCESS);
	}
	// Si hay puentes en el grafo, sólo se usará el primero
	std::pair<int,int> first_edge = brigde_edges[0];
	// Se elimina el puente del grafo
	std::cout << "Eliminando arista " << first_edge.first << " " << first_edge.second << "..." << std::endl;
	original_graph.delete_edge(first_edge.first, first_edge.second);
	std::cout << "Matriz de adyacencia resultante:" << std::endl;
	original_graph.print();

	std::cout << "GENERACIÓN DE SUBGRAFOS" << std::endl;
	std::cout << "=======================" << std::endl;
	// Se genera el subgrafo que contiene a uno de los vértices que forma la arista puente
	std::cout << "Generando subgrafo que contiene al vértice " << first_edge.first << "..." << std::endl;
	Graph<type_t> subgraph_1 = original_graph.get_connected_component(first_edge.first);
	std::cout << "Subgrafo 1 resultante:" << std::endl;
	subgraph_1.print();
	// Se genera el subgrafo que contiene al otro vértice que forma la arista puente
	std::cout << "Generando subgrafo que contiene al vértice " << first_edge.second << "..." << std::endl;
	Graph<type_t> subgraph_2 = original_graph.get_connected_component(first_edge.second);
	std::cout << "Subgrafo 2 resultante:" << std::endl;
	subgraph_2.print();

	std::complex<float> suma;
	// Llena las admitancias de la diagonal de la submatriz 1

	std::cout << "CÁLCULO ADMITANCIAS DIAGONAL PRINCIPAL" << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "Calculando diagonal subgrafo 1..." << std::endl;
	// Llena las admitancias de la diagonal de la submatriz 1
	calculate_diagonal(subgraph_1);
	std::cout << "Matriz resultante:" << std::endl;
	subgraph_1.print();
	std::cout << "Calculando diagonal subgrafo 2..." << std::endl;
	// Llena las admitancias de la diagonal de la submatriz 2
	calculate_diagonal(subgraph_2);
	std::cout << "Matriz resultante:" << std::endl;
	subgraph_2.print();

	return 0;
}


void calculate_diagonal(Graph<type_t>& g)
{
	type_t suma;
	for (int i = 0; i < g.get_V(); i++)
	{
		suma = (type_t)0;
		std::vector<int> neighbours = g.get_neighbours(i);
		for (unsigned int j = 0; j < neighbours.size(); j++)
		{
			suma += g.get_edge(i, neighbours[j]);
		}
		if (neighbours.size() > 0)
		{
			std::cout << "suma admitancias fila " << i << ": " << suma << std::endl;
			g.add_edge(-suma, i, i); // La diagonal debe llevar signo opuesto
		}
	}
}
