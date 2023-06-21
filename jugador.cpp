// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15#
#include "jugador.h"

string toString(tJugador &jugador) { 
	string punt, jug;
	punt = to_string(jugador.puntos);
	jug = jugador.identificador + " " + punt;
	return jug;
}

void modificarJugador(tJugador & jugador, int puntos) {
	jugador.puntos = jugador.puntos + puntos;
}

bool menor(const tJugador & j1, const tJugador & j2) {
	if ((j1.puntos < j2.puntos) || ((j1.puntos == j2.puntos) && (j1.identificador > j2.identificador))) return true;
	else return false;
}