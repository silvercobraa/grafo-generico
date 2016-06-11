#ifndef EDGE_H
#define EDGE_H

/**
 * Clase de prueba, para testear la clase Graph<T>
 */
class Edge
{
private:
	int value;
	bool visited;
public:
	Edge()
	{
		value = -1;
	}

	Edge (int v1, int v2)
	{
		value = v1 + v2;
		std::cout << "value: " << value << std::endl;
	}
	bool is_visited()
	{
		return visited;
	}
	int get_value() const
	{
		return value;
	}
	// Aparentemente, esto no es necesario
	// friend std::ostream& operator<<(std::ostream& os, const Edge& dt);
};

// No funca si le coloco const a Edge&
std::ostream& operator << (std::ostream& stream, const Edge& e)
{
	//std::cout << "Edge&:" << std::endl;
	//std::cout << "e.get_value(): " << e.get_value() << std::endl;
	return stream << e.get_value();
}

// No funca si coloco objeto en vez de referencia
/*std::ostream& operator << (std::ostream& stream, Edge e)
{
	std::cout << "Edge:" << std::endl;
	return stream << e.get_value();
}*/

std::ostream& operator << (std::ostream& stream, const Edge* e)
{
	//std::cout << "edge*" << " ";
	if (e != NULL)
	{
		//std::cout << "e->get_value(): " << e->get_value() << std::endl;
		//return stream << e->get_value();
		stream << e->get_value();
		return stream;
	}
	else
	{
		//return stream << "NULO";
		stream << "0";
		return stream;
	}
}

bool operator != (Edge e1, Edge e2)
{
	//std::cout << "Operador != sobrecargado" << std::endl;
	return e1.get_value() != e2.get_value();
}

#endif /* end of include guard: EDGE_H */
