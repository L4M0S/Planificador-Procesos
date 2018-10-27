#include "ListaProcesos.h"

int main() {
	int capacidad;
	int insercion;
	int planificador;

	cout << "Inserta la cantidad maxima de procesos a contener en la lista\n>>";
	cin >> capacidad;
	ListaProcesos lista(capacidad);
	cout << "Elige una opcion para insertar procesos:\n1.- Manual\n2.- Automatico\n>>";
	cin >> insercion;
	if (insercion == 1)
		lista.manual();
	else lista.automatico();
	cout << "ELIGE UN PLANIFICADOR DE PROCESO\n1.- Fifo\n2.- Round Robin\n3.- Sjf\n4.- Prioridad\n>>";
	cin >> planificador;
	switch (planificador) {
	case 1:
		cout << "--------------------------FIFO--------------------------" << endl;
		lista.fifo();
		break;
	case 2:
		cout << "-----------------------RoundRobin-----------------------" << endl;
		lista.roundRobin();
		break;
	case 3:
		cout << "--------------------------SJF---------------------------" << endl;
		lista.sjf();
		break;
	case 4:
		cout << "-----------------------Prioridad------------------------" << endl;
		lista.prioridad();
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}