// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#include "casilla.h"

void iniciaCasilla(tCasilla & casilla) {
	cjto_lleno(casilla.c);
	casilla.estado = VACIO;
	casilla.numero = 0;
}

void rellenaCasilla(tCasilla& casilla, char& c, bool& esfija) {
	if (esfija == true) {
		casilla.numero = (c - '0');
		casilla.estado = FIJA;
		cjto_vacio(casilla.c);
	}
	else if (esfija == false) casilla.estado = VACIO;
}

void dibujaCasilla(const tCasilla & casilla) {
	int color;
	if (casilla.estado == VACIO) {
		color = 0;
		colorFondo(color);
		cout << "   ";
	}
	if (casilla.estado == FIJA) {
		color = 1;
		colorFondo(color);
		cout << " " << casilla.numero << " ";
	}
	if (casilla.estado == RELLENO) {
		color = 4;
		colorFondo(color);
		cout << " " << casilla.numero << " ";
	}
	color = 0;
	colorFondo(color);
}

bool esSimple(const tCasilla & casilla, int & numero) {
	bool unicovalor = false;
	numero = 0;
	tConjunto c;
	if ((esUnitario(c, numero) == true) && (casilla.estado == VACIO)) unicovalor = true;
	return unicovalor;
}

void colorFondo(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}
