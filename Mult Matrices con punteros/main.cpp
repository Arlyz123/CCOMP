//Multiplication de matrices no cuadradas
//Inprimir_Matriz, Crear_Matriz, Borrar_Matriz;

#include <iostream>

void funPrint(int** matriz, int fila, int columna) {
    for (int i{0}; i < fila; i++) {
        for (int j{0}; j < columna; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\t" << std::endl;
    }
}

int **funCrearMatriz(int fila, int columna){
  int **matriz = new int* [fila];
  for(int i{0}; i < fila; i++){
    matriz[i] = new int[columna];
  }
  return matriz;
}

int** funRellenarMatriz(int fila, int columna) {
	int **matriz = funCrearMatriz(fila, columna);
	
	int contador = 1;
	for (int**p = matriz; p < matriz+fila; p++) {
		for (int* q = *p; q < *p + columna; q++) {
			*q = contador;
			contador++;
		}
	}
	return matriz;
}

void funDeleteMatriz(int** matriz, int fila) {
    for (int i{0}; i < fila; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

int** funMultiplicarMatricez(int** matriz1, int** matriz2, int filaMatriz1, int columnaMatriz1, int filaMatriz2, int columnaMatriz2) {
	int **resultado = funCrearMatriz(filaMatriz1, columnaMatriz2);

	for (int i = 0; i < filaMatriz1; i++) {
		for (int j = 0; j < columnaMatriz2; j++) {
			resultado[i][j] = 0;
			for (int k = 0; k < columnaMatriz1; k++) {
				resultado[i][j] += matriz1[i][k] * matriz2[k][j];
			}
		}
	}
	return resultado;
}

int main() {
	int** matriz1, ** matriz2, **resultado, filaMatriz1, columnaMatriz1, filaMatriz2, columnaMatriz2, contador;

	do {
        std::cout << "Fila matriz 1: "; std::cin >> filaMatriz1;
        std::cout << "Columna matriz 1: "; std::cin >> columnaMatriz1;
        std::cout << "Fila matriz 2: "; std::cin >> filaMatriz2;
        std::cout << "Columna matriz 2: "; std::cin >> columnaMatriz2;

        if (columnaMatriz1 != filaMatriz2) {
            std::cout << "El número de columnas de la matriz 1 debe coincidir con el número de filas de la matriz 2. Intente de nuevo.\n";
        }
    } while (columnaMatriz1 != filaMatriz2);


	matriz1 = funRellenarMatriz(filaMatriz1, columnaMatriz1);
	matriz2 = funRellenarMatriz(filaMatriz2, columnaMatriz2);
	resultado = funMultiplicarMatricez(matriz1, matriz2, filaMatriz1, columnaMatriz1, filaMatriz2, columnaMatriz2);


    std::cout << "Matriz 1:" << std::endl;
    funPrint(matriz1, filaMatriz1, columnaMatriz1);

    std::cout << "\nMatriz 2:" << std::endl;
    funPrint(matriz2, filaMatriz2, columnaMatriz2);

    std::cout << "\nResultado de matriz1 x matriz2:" << std::endl;
    funPrint(resultado, filaMatriz1, columnaMatriz2);

    funDeleteMatriz(resultado, filaMatriz1);
    funDeleteMatriz(matriz1, filaMatriz1);
    funDeleteMatriz(matriz2, filaMatriz2);
}