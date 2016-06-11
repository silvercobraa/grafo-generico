#include <iostream>
#include "Graph.h"
#include "Edge.h"

int main(int argc, char const *argv[])
{
	// CASO DE PRUEBA CON INTS
	//Graph<int>* g = new Graph<int>(10);
	//g->print();
	//g->add_edge(3, 6, 8);
	//g->print();
	//std::cout << "grado de 6: " << g->degree(6) << std::endl;
	//g->delete_edge(6,8);
	//std::cout << "grado de 6: " << g->degree(6) << std::endl;

	// CASO DE PRUEBA CON STRINGS
	//Graph<std::string>* g = new Graph<std::string>(5);
	//g->print();
	//g->add_edge("hola", 2, 4);
	//g->print();
	//std::vector<int> v = g->get_neighbours(2);

	// CASO DE PRUEBA CON OBJETOS DE CLASE EDGE
	//Graph<Edge>* g = new Graph<Edge>(10);
	//g->print();
	//Edge e(1, 3);
	//g->add_edge(e, 4, 5);
	//g->print();
	//std::vector<int> v = g->get_neighbours(5);
	//std::cout << "size v:" << v.size() << std::endl;
	//for (unsigned int i = 0; i < v.size(); i++)
	//{
	//	std::cout << "v[" << i << "]: " << v[i] << std::endl;
	//}

	// CASO DE PRUEBA CON PUNTEROS A EDGE
	//Graph<Edge*>* g = new Graph<Edge*>(10);
	//g->print();
	//Edge* e = new Edge(1, 3);
	//g->add_edge(e, 4, 5);
	//g->add_edge(e, 4, 2);
	//g->print();
	//std::cout << "grado de vertice 4:" << g->degree(4) << std::endl;
	//std::cout << "grado de vertice 5:" << g->degree(5) << std::endl;
	//std::cout << "grado de vertice 2:" << g->degree(2) << std::endl;

	Graph<Edge*>* g = new Graph<Edge*>(10);
	g->print();
	Edge* e = new Edge(4, 3);
	g->add_edge(e, 4, 5);
	g->add_edge(e, 2, 1);
	g->add_edge(e, 2, 4);
	g->add_edge(e, 5, 2);
	g->add_edge(e, 8, 7);
	g->add_edge(e, 2, 2);
	g->print();
	std::vector<int> v = g->get_neighbours(5);
	std::cout << "size v:" << v.size() << std::endl;
	for (unsigned int i = 0; i < v.size(); i++)
	{
	std::cout << "v[" << i << "]: " << v[i] << std::endl;
	}

	Graph<Edge*> g2 = g->clone();
	g2.print();
	std::vector<int> connected_component_4 = BFS(&g2, 4);
	Graph<Edge*> g3 = g2.get_connected_component(4);
	g3.print();
	// CASO DE PRUEBA CON PUNTEROS A OBJETOS DE TIPO PAIR<INT, FLOAT>
	//Graph<std::pair<int, float>*>* g = new Graph<std::pair<int, float>*>(5);
	//g->print();
	//std::pair<int, float>* p = new std::pair<int, float>(3, 4.2);
	//g->add_edge(p, 2, 4);
	//g->print();
	//g->add_edge(NULL, 3, 1);
	//g->print();
	//g->add_edge(new std::pair<int, float>(12, 3.43), 2, 5);
	//g->print();

	return 0;
}
