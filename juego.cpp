// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#include "juego.h"

void iniciaJuego(tJuego & juego) {
	juego.tablerolleno = false;
	juego.sudoku.puntuacion = 0;
	iniciaTablero(juego.tablero);
}

bool cargarJuego(tJuego & juego, tListaSudokus& lista){
		do {
			cout << "Escriba el nombre del fichero que desee abrir: ";
			cin >> juego.sudoku.archivo;
			for (int i = 0; i < MAX_SUDOKUS; i++) {
				if (lista.tlista[i].archivo == juego.sudoku.archivo) juego.sudoku.puntuacion = lista.tlista[i].puntuacion;
			}
		} while (cargarTablero(juego.sudoku.archivo, juego.tablero) == false);
		return true;
} 

void mostrarJuego(const tJuego & juego) {
	cout << "El juego es con el " << juego.sudoku.archivo << " y se pueden obetener " << juego.sudoku.puntuacion
		<< " puntos." << endl << "Se muestra el tablero de este sudoku." << endl << endl;
	dibujarTablero(juego.tablero);
}

int jugarUnSudoku(tJuego & juego, tListaSudokus& lista) {
	int modojugar, puntos = 0, fila, columna;
	iniciaJuego(juego);
	if (cargarJuego(juego, lista) == true) mostrarJuego(juego);
		do {
			modojugar = menujugar();
			switch (modojugar) {
			case 0:
				modojugar = 0;
				break;
			case 1:
				cout << "Seleccione una casilla para saber sus posibles valores, conjunto." <<
					" Introduzca fila y columna respectivamente." << endl;
				do {
					cin >> fila;
					cin >> columna;
					if (fila > 9 || columna > 9) cout << "Casilla incorrecta, vuelva a introducir una fila y columna." << endl;
				} while (fila > 9 || columna > 9);
				mostrarPosibles(juego.tablero, fila, columna);
				break;
			case 2:
				int e;
				cout << "Elija una casilla para introducir un valor. Escriba fila y columna respectivamente." << endl;
				do {
					cin >> fila;
					cin >> columna;
					if (fila > 9 || columna > 9) cout << "Casilla incorrecta, vuelva a introducir una fila y columna." << endl;
				} while (fila > 9 || columna > 9);
				cout << "Ahora ponga un valor en dicha casilla, dentro del conjunto de valores posibles: ";
				cin >> e;
				if (ponerNum(juego.tablero, fila, columna, e) == true) {
					cout << "El tablero queda modificado." << endl;
					dibujarTablero(juego.tablero);
				}
				if (tableroLleno(juego.tablero) == true) {
					puntos = juego.sudoku.puntuacion;
					cout << "Sudoku completado, el jugador gana los puntos de este." << endl << endl;
					modojugar = 0;
				}
				break;
			case 3:
				cout << "Elija una casilla para eliminar su valor. Escriba fila y columna respectivamente." << endl;
				do {
					cin >> fila;
					cin >> columna;
					if (fila > 9 || columna > 9) cout << "Casilla incorrecta, vuelva a introducir una fila y columna." << endl;
				} while (fila > 9 || columna > 9);
				if (borrarNum(juego.tablero, fila, columna) == true) dibujarTablero(juego.tablero);
			
				break;
			case 4:
				cout << "Al seleccionar este modo se reinicia el tablero." << endl;
				reiniciarTablero(juego.tablero);
				dibujarTablero(juego.tablero);
				break;
			case 5:
				cout << "Se autocompletan las celdas simples con un unico posible valor." << endl;
				rellenarSimples(juego.tablero);
				dibujarTablero(juego.tablero);
				if (tableroLleno(juego.tablero) == true) {
					puntos = juego.sudoku.puntuacion;
					cout << "Sudoku completado, el jugador gana los puntos de este." << endl;
					modojugar = 0;
				}
				break;
			}
		} while (modojugar != 0);
	 return puntos;
}

int menu() {
	int opcion;
	do {
		cout << "Elija un modo:" << endl << "0 - Salir" << endl << "1 - Jugar" << endl << "2 - Ver jugadores ordenados por identificador" << endl << 
			"3 - Ver jugadores ordenados por puntos" << endl << "4 - Incorporar sudoku" << endl;
		cin >> opcion;
		if (opcion > 4) cout << "Opcion incorrecta. ";
	} while (opcion > 4);
	return opcion;
}

int menujugar() {
	int opcion;
	do {
		cout << "Elija un modo para jugar:" << endl << "0 - Abortar la resolucion y volver al menu principal" << endl <<
			"1 - Ver posibles valores de una casilla vacia" << endl << "2 - Colocar valor en una casilla" << endl <<
			"3 - Borrar valor de una casilla" << endl << "4 - Reiniciar el tablero" << endl << "5 - Autocompletar celdas simples" << endl;
		cin >> opcion;
		if (opcion > 5) cout << "Opcion incorrecta. ";
	} while (opcion > 5);
	return opcion;
}