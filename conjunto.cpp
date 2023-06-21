// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#include "conjunto.h"

void cjto_vacio(tConjunto & c){
	for (int i = 0; i < POSIBLES_VALORES; i++) {
		c[i] = 0;
	}
}

void cjto_lleno(tConjunto & c){
	for (int i = 0; i < POSIBLES_VALORES; i++) {
		c[i] = i + 1;
	}
}

bool pertenece(tConjunto & c, int e){
	bool encontrado = false;
	int i = 0;
	while(encontrado == false && i < POSIBLES_VALORES) {
		if (e == c[i]) encontrado = true;
		i++;
	}
	return encontrado;
}

void annadeElemento(tConjunto & c, int e){
	c[e - 1] = e;
}

void borraElemento(tConjunto & c, int e) {
	c[e - 1] = 0;
}

int numElems(const tConjunto & c){
	int nume = 0;
	for (int i = 0; i < POSIBLES_VALORES; i++) {
		if (c[i] != 0) nume = nume + 1;
	}
	return nume;
}

bool esUnitario(const tConjunto & c, int & e){
	bool unitario = false;
	int nume;
	nume = numElems(c);
	if (nume == 1) unitario = true;
	return unitario;
}

void mostrar(const tConjunto & c){
	cout << "Los elementos que forman el conjunto de posibles valores en la casilla son: ";
	for (int i = 0; i < POSIBLES_VALORES; i++) {
		if (c[i] != 0) cout << c[i] << " ";
	}
	cout << endl;
}
