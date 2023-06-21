// Alejandro Magarzo Gonzalo y Pablo González Corredor, Laboratorio 5, Grupo G15
#include "Listasudokus.h"

void creaListaVacia(tListaSudokus& lista) {
	lista.contador = 0;
	for (int i = 0; i < MAX_SUDOKUS; i++) {
		lista.tlista[i].puntuacion = 0;
	}
}

bool cargar(tListaSudokus& lista) {
	bool cargado = false;
	ifstream file;
	creaListaVacia(lista);

	file.open("listaSudokus.txt");
	if (file.is_open()) {
		cargado = true;
		lista.contador = 0;
		while (!file.eof()) {
			file >> lista.tlista[lista.contador].archivo;
			file >> lista.tlista[lista.contador].puntuacion;
			lista.contador++;
		}

		file.close();
	}
	return cargado;
}

void mostrar(const tListaSudokus& lista) {
	int i = 0;
	while (i < lista.contador) {
		cout << "El elemento " << i + 1 << " de la lista corresponde con el archivo " << lista.tlista[i].archivo
			<< " que proporciona " << lista.tlista[i].puntuacion << " puntos." << endl;
		i++;
	}
	cout << endl;
}

bool guardar(const tListaSudokus & lista) {
	bool guardado = false;
	ofstream file;
	file.open("listaSudokus.txt");
	int i = 0;
	while (i < lista.contador) {
		file << lista.tlista[i].archivo << " " << lista.tlista[i].puntuacion;
		if (i < lista.contador - 1) file << endl;
		i++;
	}
	cout << lista.contador;
	file.close();
	guardado = true;
	return guardado;
}

bool registrarSudoku(tListaSudokus & lista, tSudokus& sudoku) {
	bool registrado = false;
	string fich;
	cout << "Introduzca el nombre del fichero que desea anadir: ";
	cin >> fich;
	if ((buscarFichero(lista, fich) == false) && (lista.contador + 1 < MAX_SUDOKUS)) {
		sudoku.archivo = fich;
		cout << "Indique la puntuacion que proporciona " << sudoku.archivo << ": ";
		cin >> sudoku.puntuacion;
		int pos = buscarPos(lista, sudoku);
		cout << "La posicion donde se inserta es: " << pos + 1 << endl;
		for (int i = lista.contador; i > pos; i--) {
			lista.tlista[i] = lista.tlista[i - 1];
		}
		lista.tlista[pos].archivo = sudoku.archivo;
		lista.tlista[pos].puntuacion = sudoku.puntuacion;
		lista.contador++;
		registrado = true;
	}
	else if (lista.contador == MAX_SUDOKUS) cout << "La lista esta llena." << endl;
	else if (buscarFichero(lista, fich) == true) cout << "El archivo ya estaba registrado en la lista." << endl;
	return registrado;
}

bool buscarFichero(const tListaSudokus & lista, string nombreFich) {
	bool encontrado = false;
	int i = 0;
	while (i < lista.contador && !encontrado) {
		if (nombreFich == lista.tlista[i].archivo) encontrado = true;
		i++;
	}
	return encontrado;
}

int buscarPos(const tListaSudokus & lista, tSudokus& sudoku) {
	int mitad, ini = 0, fin = lista.contador - 1, posicion;
	while (ini <= fin) {
		mitad = (ini + fin) / 2;
		if (sudoku.puntuacion == lista.tlista[mitad].puntuacion) {
			if (sudoku.archivo > lista.tlista[mitad].archivo) {
				ini = mitad + 1;
				posicion = mitad + 1;
			}
			else if (sudoku.archivo < lista.tlista[mitad].archivo) {
				fin = mitad - 1;
				posicion = mitad;
			}
		}
		else if (sudoku.puntuacion < lista.tlista[mitad].puntuacion) {
			fin = mitad - 1;
			posicion = mitad;
		}
		else {
			ini = mitad + 1;
			posicion = fin + 1;
		}
	}
	return posicion;
}

