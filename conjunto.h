// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#ifndef conjunto_h
#define conjunto_h
#include <iostream>

using namespace std;

const int POSIBLES_VALORES = 9;
typedef int tConjunto[POSIBLES_VALORES];

void cjto_vacio(tConjunto & c); 
void cjto_lleno(tConjunto & c); 
bool pertenece(tConjunto & c, int e);
void annadeElemento(tConjunto & c, int e); 
void borraElemento(tConjunto & c, int e);
int numElems(const tConjunto & c); 
bool esUnitario(const tConjunto & c, int & e); 
void mostrar(const tConjunto & c);


#endif