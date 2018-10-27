#include "Nodo.h"

Nodo::Nodo(string _id, int _pri, int _tie): Proceso(_id, _pri, _tie) {
	siguiente = NULL;
}
Nodo::~Nodo() 
{}

Nodo* Nodo::next() {
	return siguiente;
}
void Nodo::next(Nodo *_sig){
	siguiente = _sig;
}
