// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#ifndef casilla_h
#define casilla_h
#include "conjunto.h"
#include <windows.h> 

typedef enum { VACIO, FIJA, RELLENO } tEstadoCasilla;

typedef struct {
	int numero;
	tEstadoCasilla estado;
	tConjunto c;
}tCasilla;

const int NUM_COLORES = 3;
const int PALETA[NUM_COLORES] = { 0,1,4 }; 

void iniciaCasilla(tCasilla & casilla); 
void rellenaCasilla(tCasilla& casilla, char& c, bool& esfija);
void dibujaCasilla(const tCasilla & casilla);
void colorFondo(int color);
bool esSimple(const tCasilla & casilla, int & numero);


#endif