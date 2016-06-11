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

template <class T>
void DFS(Graph<T>* g, int v);

template <class T>
void BFS(Graph<T>* g, int v);

#include "Traversals.cpp"

#endif /* end of include guard: TRAVERSALS_H */
