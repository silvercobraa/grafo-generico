#ifndef TRAVERSALS_H
#define TRAVERSALS_H

#include <queue>
#include <vector>
#include "Graph.h"

/**
 * Función que visita recursivamente los vértices adjacentes al vértice v.
 * Es llamada por la función DFS y no debe ser llamada en otra parte.
 */
template <class T>
void _visit_neighbours(Graph<T>* g, int v, bool* visited);

/**
 * Aplica el algoritmo DFS al grafo g, comenzando en el vértice v. Retorna un
 * vector con los vértices visitados.
 */
template <class T>
std::vector<int> DFS(Graph<T>* g, int v);

/**
 * Aplica el algoritmo BFS al grafo g, comenzando en el vértice v. Retorna un
 * vector con los vértices visitados.
 */
template <class T>
std::vector<int> BFS(Graph<T>* g, int v);

#include "Traversals.cpp"

#endif /* end of include guard: TRAVERSALS_H */
