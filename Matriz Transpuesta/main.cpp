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

void funDeleteMatriz(int** matriz, int fila) {
    for (int i{0}; i < fila; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

int **funMatrizTranspuesta(int fila, int columna, int **matriz){
  int **matrizTranspuesta = new int* [columna];
  for(int i{0}; i < columna; i++){
    matrizTranspuesta[i] = new int[fila];
    for(int j{0}; j < fila; j++){
      matrizTranspuesta[i][j] = matriz[j][i];
    }
  }
  return matrizTranspuesta;
}

int main(){
  
  int **matriz, **transpuesta, fila{4}, columna{5}, contador{0};
  
  matriz = funCrearMatriz(fila, columna);
  transpuesta = funMatrizTranspuesta(fila, columna, matriz);
  
  //valores
  for(int i{0}; i < fila; i++){
    for(int j{0}; j < columna; j++){
      matriz[i][j] = contador;
      contador++;
    }
  }
  
  std::cout << "matriz original: " << std::endl;
  funPrint(matriz, fila, columna);

  std::cout << "\nmatriz transpuesta: " << std::endl;
  funPrint(transpuesta, columna, fila);
  
  funDeleteMatriz(matriz, fila);
  funDeleteMatriz(transpuesta, columna);
}