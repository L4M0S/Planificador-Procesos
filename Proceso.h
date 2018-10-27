#ifndef proceso_h
#define proceso_h

#include <iostream>
#include <string>
using namespace std;

class Proceso {
protected:
	string id;
	int prioridad;
	int tiempo;
	int tiempoEjecucion;

public:
	Proceso(string, int, int);
	~Proceso();

	string getId();
	void setId(string);
	int getPrioridad();
	void setPrioridad(int);
	int getTiempo();
	void setTiempo(int);
	int getTiempoEjecucion();
	void setTiempoEjecucion(int);

	void estadoProceso();
};

#endif