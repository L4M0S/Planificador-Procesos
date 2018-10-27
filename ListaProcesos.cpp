#include "ListaProcesos.h"

int ListaProcesos::orden()
{
	Nodo *n;
	n=inicial;
	do
	{
		cout<<n->getId()<<"->";
		n=n->next();
	}while(n!=NULL);
	cout<<endl;
}

int ListaProcesos::calcQuantum() {
	int quantum = 0;
	Nodo *p = inicial;
	while (p) {
		quantum += p->getTiempo();
		p = p->next();
	}
	quantum /= longitud;
	return quantum;
}
void ListaProcesos::sumaTiempo(int tie) {
	Nodo *p;
	p = inicial;
	do{
		p->setTiempoEjecucion(tie);
		p = p->next();
	} while (p);
}

ListaProcesos::ListaProcesos(int _lim): limite(_lim) {
	longitud = 0;
	inicial = NULL;
	ultimo = NULL;
}
ListaProcesos::~ListaProcesos()
{}

bool ListaProcesos::listaVacia() {
	return longitud == 0;
}
bool ListaProcesos::listaLlena() {
	return longitud == limite;
}
void ListaProcesos::nuevoProceso(string id, int prioridad, int tiempo) {
	if (!listaLlena()) {
		Nodo *aux = new Nodo(id, prioridad, tiempo);
		if (listaVacia()) {
			inicial = aux;
			ultimo = aux;
		} else {
			ultimo->next(aux);
			ultimo = ultimo->next();
		}
		cout << "Insertado ";
		ultimo->estadoProceso();
		longitud++;
	} else {
		puts("Lista de procesos llena");
	}
}
void ListaProcesos::ejecutarProceso() {
	if (!listaVacia()) {
		sumaTiempo(inicial->getTiempo());
		Nodo *p;
		p = inicial;
		inicial = inicial->next();
		delete p;
		longitud--;
	} else {
		puts("No hay procesos para ejecutar");
	}
}
void ListaProcesos::imprime() {
	cout << "IMPRIMIENDO ORDEN DE LISTA" << endl;
	Nodo *p = inicial;
	while (p) {
		cout << p->getId() << "-> ";
		p = p->next();
	}
	cout << endl;
}
void ListaProcesos::manual() {
	string nom;
	int pri, tie;
	char seguir;
	do {
		cout << "Nombre de Proceso: >>";
		cin >> nom;
		cout << "Prioridad de proceso: >>";
		cin >> pri;
		cout << "Tiempo de proceso: >>";
		cin >> tie;
		nuevoProceso(nom, pri, tie);
		if (!listaLlena()) {
			cout << "Seguir insertando procesos? 'y' 'n'\n>>";
			cin >> seguir;
		}
	} while (!listaLlena() && seguir == 'y');
	if (!listaLlena()) {
		cout << "Continuar con la insercion de procesos de forma automatica? 'y' 'n'\n>>";
		cin >> seguir;
		if (seguir == 'y')
			automatico();
	}
		
}
void ListaProcesos::automatico() {
srand(time(NULL));
	int i = 0;
	int prioridad;
	int tiempo;
	while (!listaLlena()) {
		prioridad = rand() % 5 + 1;
		tiempo = rand() % 9 + 1;
		nuevoProceso("rand" + to_string(i), prioridad, tiempo);
		i++;
	}
}
void ListaProcesos::fifo() {
	do {
		orden();
		ejecutarProceso();
	} while (!listaVacia());
}
void ListaProcesos::sjf() {
	
	if (!listaVacia()) {
		Nodo *p, *q;
		for (int i = 0; i < longitud; i++) {
			//orden();
			p = inicial;
			q = inicial->next();
			for (int j = 1; j < longitud - i; j++) {
				if (p->getTiempo() > q->getTiempo())
					p = q;
				q = q->next();
			}
			if (p == inicial)
				inicial = inicial->next();
			else {
				q = inicial;
				while (q->next() != p)
					q = q->next();
				q->next(p->next());
			}
			ultimo->next(p);
			ultimo = p;
		}
		ultimo->next(NULL);
	}
	fifo();
}
void ListaProcesos::roundRobin() {
	
	int quantum = calcQuantum();
	int tiempo;
	cout << "Quantum = " << quantum << endl;
	do {orden();
		tiempo = inicial->getTiempo();
		if (quantum >= tiempo)
			ejecutarProceso();
		else {
			sumaTiempo(quantum);
			tiempo -= quantum;
			inicial->setTiempo(tiempo);
			ultimo->next(inicial);
			ultimo = ultimo->next();
			inicial = inicial->next();
			ultimo->next(NULL);
		}
	} while (!listaVacia());
}


void ListaProcesos::prioridad() {
	int quantum = calcQuantum();
	int tiempo;
	int prioridad;
	cout << "Quantum = " << quantum << endl;
	do {
	if (!listaVacia()) {
		Nodo *p, *q;
		for (int i = 0; i < longitud; i++) {
			p = inicial;
			q = inicial->next();
			for (int j = 1; j < longitud - i; j++) {
				if (p->getPrioridad() < q->getPrioridad())
					p = q;
				q = q->next();
			}
			if (p == inicial)
				inicial = inicial->next();
			else {
				q = inicial;
				while (q->next() != p)
					q = q->next();
				q->next(p->next());
			}
			ultimo->next(p);
			ultimo = p;
		}
		ultimo->next(NULL);
	}
	orden();
		tiempo = inicial->getTiempo();
		if (quantum >= tiempo)
			ejecutarProceso();
		else {
			sumaTiempo(quantum);
			tiempo -= quantum;
			if(inicial->getPrioridad()>1)
			{prioridad = inicial->getPrioridad() - 1;
			inicial->setPrioridad(prioridad);
		}
			inicial->setTiempo(tiempo);
			ultimo->next(inicial);
			ultimo = ultimo->next();
			inicial = inicial->next();
			ultimo->next(NULL);
		}
		if(longitud==1)
		ejecutarProceso();
	} while (!listaVacia());
	
}
