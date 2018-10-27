#ifndef listaProcesos_h
#define listaProcesos_h

#include "Nodo.h"
#include <cstdlib>
#include <cstdio>
#include <string>
#include <ctime>

class ListaProcesos {
private:
	int longitud;
	int limite;
	Nodo *inicial;
	Nodo *ultimo;

	int calcQuantum();
	void sumaTiempo(int);
public:
	ListaProcesos(int);
	~ListaProcesos();

	bool listaVacia();
	bool listaLlena();
	void nuevoProceso(string, int, int);
	void ejecutarProceso();

	void imprime();
	void manual();
	void automatico();
	void fifo();
	void sjf();
	void roundRobin();
	void prioridad();
	int orden();
};

#endif
