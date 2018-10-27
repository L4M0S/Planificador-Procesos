#include "Proceso.h"

Proceso::Proceso(string _id, int _pri, int _tie): id(_id), prioridad(_pri), tiempo(_tie) {
	tiempoEjecucion = 0;
}
Proceso::~Proceso() { 
	cout << "Terminado Proceso " << id << ", tiempo ejecucion: " << tiempoEjecucion << endl;
}

string Proceso::getId() {
	return id;
}
void Proceso::setId(string _id) {
	id = _id;
}
int Proceso::getPrioridad() {
	return prioridad;
}
void Proceso::setPrioridad(int _pri) {
	prioridad = _pri;
}
int Proceso::getTiempo() {
	return tiempo;
}
void Proceso::setTiempo(int _tie) {
	tiempo = _tie;
}
int Proceso::getTiempoEjecucion() {
	return tiempoEjecucion;
}
void Proceso::setTiempoEjecucion(int _tie) {
	tiempoEjecucion += _tie;
}
void Proceso::estadoProceso() {
	cout << "Proceso " << id << ", Prioridad: " << prioridad << ", Tiempo Requerido: " << tiempo << endl;
}