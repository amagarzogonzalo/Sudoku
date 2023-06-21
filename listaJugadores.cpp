// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#include "listaJugadores.h"

void puntuarJugador(tListaJugadores & listaJ, int puntos) {
	int pos;
	string jug;
	cout << "Introduzca el jugador que ha resuelto el sudoku y obtiene los puntos: ";
	cin >> jug;
	if (buscar(listaJ, jug, pos, 0, listaJ.cont - 1)) {
		modificarJugador(*(listaJ).jugadores[pos], puntos);
		cout << listaJ.jugadores[pos]->identificador << " obtiene " << puntos << "." << endl;
	}
	else {
		if (listaJ.cont == listaJ.capacidad) ampliar(listaJ);
			cout  << "Se introduce a un nuevo jugador porque la lista no esta llena. La posicion donde se inserta es: " << pos + 1 << endl;
			listaJ.jugadores[listaJ.cont] = new tJugador;
			for (int i = listaJ.cont; i > pos; i--) 
				*(listaJ).jugadores[i] = *(listaJ).jugadores[i - 1];
			listaJ.jugadores[pos]->identificador = jug;
			listaJ.jugadores[pos]->puntos = puntos;
			listaJ.cont++;
	} 
}

bool buscar(const tListaJugadores & listaJ, string id, int & pos, int ini, int fin) {
	bool encontrado = false;
	if (ini <= fin && !encontrado) {
		int mitad = (ini + fin) / 2;
		if (id == listaJ.jugadores[mitad]->identificador) {
			pos = mitad;
			encontrado = true;
		}
		else if (id < listaJ.jugadores[mitad]->identificador) {
			pos = mitad;
			encontrado = buscar(listaJ, id, pos, ini, mitad - 1);
		}
		else {
			pos = fin + 1;
			encontrado = buscar(listaJ, id, pos, mitad + 1, fin);
		}
	}
	return encontrado;
}

void creaListaVacia(tListaJugadores &listaJ){	
	listaJ.cont = 0;
	listaJ.capacidad = JUGADORES;
	listaJ.jugadores = new tJugadorPtr[listaJ.capacidad];
}

bool esVaciaLista(const tListaJugadores &listaJ){
	if(listaJ.cont == 0) return true;
	return false;
}

void mostrar(const tListaJugadores &listaJ) {
	if (esVaciaLista(listaJ))
		cout << "No hay jugadores registrados" << endl << endl;
	else{
		cout << "Se muestra la lista de jugadores: " << endl << endl;
		for (int i = 0; i < listaJ.cont; i++) 
			cout << "Jugador " << i + 1 << ": " << toString(*(listaJ).jugadores[i]) << endl;
		cout << endl << endl;
	}

}

bool cargar(tListaJugadores &listaJ) {
	creaListaVacia(listaJ);
	bool cargado = false;
	ifstream file;
	file.open(BD);
	if (file.is_open()) {
		cargado = true;
		while (!file.eof() && listaJ.cont < listaJ.capacidad) {
			listaJ.jugadores [listaJ.cont] = new tJugador;
			file >> listaJ.jugadores[listaJ.cont]->identificador;
			file >> listaJ.jugadores[listaJ.cont]->puntos;
			listaJ.cont++;
		}
		file.close();
	} 
	else cout << "No ha sido cargado correctamente." << endl;
	return cargado;
}

tListaJugadores ordenarPorRanking(const tListaJugadores & listaJ){
	tListaJugadores listaAux = copiaSemiProfundaCompartiendoJugadores(listaJ);
	tJugador j1, j2;
	tJugadorPtr tmp;
	for (int i = 0; i < listaJ.cont; i++) {
		for (int j = listaJ.cont - 1; j > i; j--) {
			j1 = *(listaAux).jugadores[j - 1];
			j2 = *(listaAux).jugadores[j];
			if (menor(j1,j2)){
				tmp = listaAux.jugadores[j];
				listaAux.jugadores[j] = listaAux.jugadores[j - 1];
				listaAux.jugadores[j - 1] = tmp;	
			}
		}
	}
	return listaAux;
}

void borrarListaJugadores(tListaJugadores & listaJ){
	for (int i = 0; i < listaJ.cont; i++) {
		delete listaJ.jugadores[i];
	}
	delete[] listaJ.jugadores;
	listaJ.cont = 0;

}

bool guardar(const tListaJugadores & listaJ) {
	bool guardado = false;
	ofstream file;
	file.open(BD);
	if (file.is_open()) {
		int i = 0;
		while (i < listaJ.cont) {
			file << listaJ.jugadores[i]->identificador << "  " << listaJ.jugadores[i]->puntos;
			if (i < listaJ.cont - 1) file << endl;
			i++;
		}
		guardado = true;
		file.close();
	}
	return guardado;
}

tListaJugadores copiaSemiProfundaCompartiendoJugadores(const tListaJugadores &listaJ) {
	tListaJugadores listaAux;
	listaAux.jugadores = new tJugadorPtr[listaJ.capacidad];
	listaAux.capacidad = listaJ.capacidad;
	listaAux.cont = listaJ.cont;
	for (int i = 0; i < listaJ.cont; i++)
		listaAux.jugadores[i] = listaJ.jugadores[i];
	return listaAux;
}

void liberarArray(tListaJugadores & listaJ) {
	delete[] listaJ.jugadores;
}

void ampliar(tListaJugadores & listaJ) {
	tListaJugadores listaAux = copiaSemiProfundaCompartiendoJugadores(listaJ);
	liberarArray(listaJ);
	listaJ.capacidad = listaJ.capacidad * 2;
	listaJ.jugadores = new tJugadorPtr[listaJ.capacidad];
	for (int i = 0; i < listaAux.cont; i++) {
		listaJ.jugadores[i] = listaAux.jugadores[i];
	}
	liberarArray(listaAux);
}