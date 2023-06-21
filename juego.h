// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#ifndef juego_h
#define juego_h
#include "Listasudokus.h"
#include "tablero.h"
#include "conjunto.h"
#include <iostream>

using namespace std;

typedef struct {
	tSudokus sudoku;
	tTablero tablero;
	bool tablerolleno;
}tJuego;

void iniciaJuego(tJuego & juego);
bool cargarJuego(tJuego & juego, tListaSudokus& lista);
void mostrarJuego(const tJuego& juego);
int jugarUnSudoku(tJuego& juego, tListaSudokus& lista);
int menu();
int menujugar();

#endif
