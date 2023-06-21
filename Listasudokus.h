// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#ifndef Listasudokus_h
#define Listasudokus_h
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

const int MAX_SUDOKUS = 20;

typedef struct {
	string archivo;
	int puntuacion;
}tSudokus;

typedef tSudokus tArray [MAX_SUDOKUS];

typedef struct {
	tArray tlista;
	int contador;
}tListaSudokus;

void creaListaVacia(tListaSudokus & lista); 
bool cargar(tListaSudokus & lista); 
void mostrar(const tListaSudokus & lista);
bool guardar(const tListaSudokus & lista);
bool registrarSudoku(tListaSudokus & lista, tSudokus& sudoku);
bool buscarFichero(const tListaSudokus & lista, string nombreFich);
int buscarPos(const tListaSudokus & lista, tSudokus& sudoku);
#endif