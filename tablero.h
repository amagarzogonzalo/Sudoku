// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#ifndef tablero_h
#define tablero_h

#include "casilla.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

const int DIMENSION = 9;

typedef tCasilla tTablero[DIMENSION][DIMENSION];

void iniciaTablero(tTablero tablero); 
bool cargarTablero(string fichero, tTablero tablero); 
void dibujarTablero(const tTablero tablero); 
bool ponerNum(tTablero tablero, int fila, int col, int e);
bool borrarNum(tTablero tablero, int fila, int col);
bool tableroLleno(const tTablero tablero);
void mostrarPosibles(tTablero tablero, int fila, int col);
void cargarPosibles(tTablero tablero);
void reiniciarTablero(tTablero tablero);
void rellenarSimples(tTablero tablero);
int calcularRegion(int a);

#endif
