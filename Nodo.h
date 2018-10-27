#ifndef nodo_h
#define nodo_h

#include "Proceso.h"

class Nodo :
	public Proceso {
private:
	Nodo *siguiente;

public:
	Nodo(string, int, int);
	~Nodo();

	Nodo* next();
	void next(Nodo*);
};

#endif