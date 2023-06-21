// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#include "tablero.h"

void iniciaTablero(tTablero tablero) {
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			iniciaCasilla(tablero[i][j]);
		}
	}
}


bool cargarTablero(string fichero, tTablero tablero) {
	char c;
	bool carga = false; 
	ifstream file;
	file.open(fichero);
	if (file.is_open()) {
		cout << "Archivo cargado correctamente." << endl << endl;
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				bool esfija = false;
				file.get(c);
				if (c >= '1') esfija = true;
				rellenaCasilla(tablero[i][j], c, esfija);
			}
			file.get(c);
		}
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				cargarPosibles(tablero);
			}
		}
		carga = true;
	}
	else cout << "Fichero inexistente." << endl;
	file.close();
	return carga;
}

void dibujarTablero(const tTablero tablero) {
	cout << "-------------------------------" << endl;
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if ((j == 0) || (j == 3 )|| (j == 6)) cout << "|";
			dibujaCasilla(tablero[i][j]);
			if (j == 8) cout << "|" << endl;
		}
		if ((i == 2) || (i == 5) || (i == 8)) cout << "-------------------------------" << endl; 
	}
	cout << endl;
}

bool ponerNum(tTablero tablero, int fila, int col, int e) {
	bool esposible = false;
	fila = fila - 1;
	col = col - 1;
	if ((tablero[fila][col].estado == VACIO) && (pertenece(tablero[fila][col].c, e) == true)) {
		tablero[fila][col].numero = e;
		tablero[fila][col].estado = RELLENO;
		cargarPosibles(tablero);
		esposible = true;
	}
	else cout << "No se ha podido llevar a cabo la operacion." << endl;
	return esposible;
}

bool borrarNum(tTablero tablero, int fila, int col) {
	bool esposibleborr = false;
	fila = fila - 1;
	col = col - 1;
	if (tablero[fila][col].estado == RELLENO) {
		for (int i = fila; i < DIMENSION; i++) if (tablero[i][col].estado == VACIO) annadeElemento(tablero[i][col].c, tablero[fila][col].numero);
		for (int j = col; j < DIMENSION; j++) if (tablero[fila][j].estado == VACIO) annadeElemento(tablero[fila][j].c, tablero[fila][col].numero);
		int sector = calcularRegion(fila), parte = calcularRegion(col);
		for (int i = sector - 1; i <= sector + 1; i++)
			for (int j = parte - 1; j <= parte + 1; j++)  if (tablero[i][j].estado == VACIO) annadeElemento(tablero[i][j].c, tablero[fila][col].numero);
		annadeElemento(tablero[fila][col].c, tablero[fila][col].numero);
		tablero[fila][col].numero = 0;
		tablero[fila][col].estado = VACIO;
		cout << "El sudoku se actualiza. " << endl;
		esposibleborr = true;
	}
	else cout << "No se ha podido borrar dicha casilla." << endl;
	return esposibleborr;
}

bool tableroLleno(const tTablero tablero) {
	bool tablerolleno = true;
	int i = 0;
	while (tablerolleno && i < DIMENSION) {
		for (int j = 0; j < DIMENSION; j++) {
			if ((tablero[i][j].estado == VACIO)) tablerolleno = false;
		}
		i++;
	}
	return tablerolleno;
}

void cargarPosibles(tTablero tablero) {
	int inif, inic, finf, finc, sector, parte;
	for (int fila = 0; fila < DIMENSION; fila++){
		for (int col = 0; col < DIMENSION; col++){
			if (tablero[fila][col].estado == VACIO) {

				for (int i = 0; i < DIMENSION; i++) if (tablero[i][col].numero > 0) borraElemento(tablero[fila][col].c, tablero[i][col].numero);

				for (int j = 0; j < DIMENSION; j++) if (tablero[fila][j].numero > 0) borraElemento(tablero[fila][col].c, tablero[fila][j].numero);

				sector = calcularRegion(fila);
				parte = calcularRegion(col);
				for (int i = sector - 1; i <= sector + 1; i++) 
					for (int j = parte - 1; j <= parte + 1; j++) if (tablero[i][j].numero > 0) borraElemento(tablero[fila][col].c, tablero[i][j].numero);
			}
		}
	}
}
void mostrarPosibles(tTablero tablero, int fila, int col) {
	if (tablero[fila-1][col-1].estado == VACIO) {
	cargarPosibles(tablero);
	mostrar(tablero[fila-1][col-1].c);
}
	else cout << "Esa casilla no esta vacia." << endl;
}

void rellenarSimples(tTablero tablero) {
	int e;
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			cargarPosibles(tablero);
			if (esUnitario(tablero[i][j].c, tablero[i][j].numero) && tablero[i][j].estado == VACIO) {
				for (int d = 0; d < POSIBLES_VALORES; d++) {
					if (tablero[i][j].c[d] != 0) e = tablero[i][j].c[d];
				}
				ponerNum(tablero,i+1,j+1,e);
			}
		}
	}
}

void reiniciarTablero(tTablero tablero) {
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if (tablero[i][j].estado == RELLENO) {
				tablero[i][j].estado = VACIO;	
				tablero[i][j].numero = 0;
				cjto_lleno(tablero[i][j].c);
			}
		}
	}
}

int calcularRegion(int a) {
	int region;
	if (a <= 2) region = 1;
	else if (a <= 5) region = 4;
	else region = 7;
	return region;
}