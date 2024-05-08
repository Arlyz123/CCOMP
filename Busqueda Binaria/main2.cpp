#include <iostream>

bool binary_Search(int* lista, int* final, int numeroHallar) {
    int fin = (final - lista);
    int ini = 0;
    int mitad = fin / 2;
    bool hallado = false;

    while (ini <= fin && !hallado) {
        if (numeroHallar > *(lista + mitad)) {
            ini = mitad + 1;
            mitad = (ini + fin) / 2;
        } else if (numeroHallar < *(lista + mitad)) {
            fin = mitad - 1;
            mitad = (ini + fin) / 2;
        } else {
            std::cout << "El numero " << numeroHallar << " esta en la posicion " << mitad << "\n";
            hallado = true;
        }
    }
    return hallado;
}

int main() {
    int lista[] = {1, 2, 7, 12, 24, 34, 44, 78, 95, 97};
    int numero_buscar;

    std::cout << "Numero a buscar: ";
    std::cin >> numero_buscar;

    bool encontrado = binary_Search(lista, (lista + std::size(lista)-1), numero_buscar);

    if (!encontrado) {
        std::cout << "El numero " << numero_buscar << " no esta en la lista\n";
    }

    return 0;
}
