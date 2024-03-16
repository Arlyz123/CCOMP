#include <iostream>
#include <string>

void imprimirSimbolo(int cantidad, const std::string& simbolo) {
    for (int i = 0; i < cantidad; ++i) {
        std::cout << simbolo;
    }
    std::cout << std::endl;
}

void operaciones(int num) {
    int uni = num % 10;   // 62 % 10 = 2
    num /= 10; // 62 / 10 = 6
    int dec = num % 10;   // 6 % 10 = 6
    num /= 10; // 6 / 10 = 0 
    int cent = num % 10;  // 0 % 10 = 0 
    num /= 10; // 0 / 10 = 0 
    int mil = num;

    if (mil > 0)
        imprimirSimbolo(mil, "M");
    if (cent > 0)
        imprimirSimbolo(cent, "C");
    if (dec > 0)
        imprimirSimbolo(dec, "X");
    if (uni > 0)
        imprimirSimbolo(uni, "I");
}

int main() {
    int numero;

    std::cout << "Ingresar un numero del 1 al 9999: ";
    std::cin >> numero;

    operaciones(numero);
}



/* 
    1 = I
    5 = V
    10 = X
    50 = L
    100 = C
    500 = D
    1000 = M
*/