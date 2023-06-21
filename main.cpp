// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#include <iostream>
#include <fstream>
#include <string>
#include "tablero.h"
#include "Listasudokus.h"
#include "conjunto.h"
#include "juego.h"
#include "listaJugadores.h"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	tListaSudokus lista;
	tListaJugadores listaJ;
	tSudokus sudoku;
	tJuego juego;
	tConjunto c;
	int modo, puntuacion;
	if ((cargar(lista)) && (cargar(listaJ))) {
		mostrar(lista);
		do {
			modo = menu();
			switch (modo) {
			case 0:
				if (guardar(lista) && guardar(listaJ)) borrarListaJugadores(listaJ);
					return 0;
				break;
			case 1:
				puntuacion = jugarUnSudoku(juego, lista);
				if (puntuacion != 0) puntuarJugador(listaJ, puntuacion);
				break;
			case 2:
				mostrar(listaJ);
				break;
			case 3:
				cout << "Se ordena la lista por su puntuacion. ";
				tListaJugadores listaAux = ordenarPorRanking(listaJ);
				mostrar(listaAux);
				liberarArray(listaAux);
				break;
			case 4:
				if (registrarSudoku(lista, sudoku)) cout << "Sudoku anadido." << endl;
				else cout << "No se ha podido anadir con exito." << endl;
				break;
			}
		} while ((modo != 0) && (modo <= 4));
	}
	else cout << "La lista de sudokus no ha sido cargada exitosamente.";

	system("pause");
	return 0;
}