// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#ifndef listaJugadores_h
#define listaJugadores_h

#include "jugador.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int JUGADORES = 5;
const string BD = "listaJugadores.txt";

typedef struct {
	tJugadorPtr* jugadores;
	int cont;  
	int capacidad;
}	tListaJugadores;

void puntuarJugador(tListaJugadores & listaJ, int puntos);
bool buscar(const tListaJugadores & listaJ, string id, int & pos, int ini, int fin);
void creaListaVacia(tListaJugadores &listaJ);
bool esVaciaLista(const tListaJugadores &listaJ);
void mostrar(const tListaJugadores &listaJ);
bool cargar(tListaJugadores &listaJ);
bool guardar(const tListaJugadores & listaJ);
tListaJugadores ordenarPorRanking(const tListaJugadores &listaJ);
void borrarListaJugadores(tListaJugadores & listaJ);
tListaJugadores copiaSemiProfundaCompartiendoJugadores(const tListaJugadores &listaJ);
void liberarArray(tListaJugadores & listaJ);
void ampliar(tListaJugadores & listaJ);

#endif

