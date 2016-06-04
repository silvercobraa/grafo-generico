#include <iostream>
#include "Graph.h"
#include "Edge.h"

int main(int argc, char const *argv[])
{
	// CASO DE PRUEBA CON INTS
	Graph<int>* g = new Graph<int>(10);
	g->print();
	g->add_edge(3, 6, 8);
	g->print();

	// CASO DE PRUEBA CON STRINGS
	//Graph<std::string>* g = new Graph<std::string>(5);
	//g->print();
	//g->add_edge("hola", 2, 4);
	//g->print();

	// CASO DE PRUEBA CON OBJETOS DE CLASE EDGE
	//Graph<Edge>* g = new Graph<Edge>(10);
	//g->print();
	//Edge e(1, 3);
	//g->add_edge(e, 4, 5);
	//g->print();

	// CASO DE PRUEBA CON PUNTEROS A EDGE
	//Graph<Edge*>* g = new Graph<Edge*>(10);
	//g->print();
	//Edge* e = new Edge(1, 3);
	//g->add_edge(e, 4, 5);
	//g->print();

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
