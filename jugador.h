// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#ifndef jugador_h
#define jugador_h
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef struct {
	string identificador;
	int puntos;	
} tJugador;

typedef tJugador* tJugadorPtr;

string toString(tJugador &jugador);
void modificarJugador(tJugador & jugador, int puntos);
bool menor(const tJugador & j1, const tJugador & j2);

#endif