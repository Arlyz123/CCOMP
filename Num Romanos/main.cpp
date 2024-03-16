#include <iostream>

std::string convertir(int num) {
    const int valores[13] =         {1000, 900, 500,  400, 100,   90,  50,   40,  10,    9,   5,     4,   1};
    const std::string romanos[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    std::string resultado;

    for(int i{0}; i<13; i++) {
        while (num >= valores[i]) {
            resultado += romanos[i];
            num -= valores[i];
        }       
    }
    return resultado;
}


int main() {
    int numero;
    std::cout << "Ingresar un numero del 1 al 9999: "; std::cin >> numero;

    do {
        std::cout << "El numero " << numero << " en romanos es " << convertir(numero);
    } while(numero > 9999);
}

/* 
    2024 = MMXXIV

    1 = I
    5 = V
    10 = X
    50 = L
    100 = C
    500 = D
    1000 = M
*/