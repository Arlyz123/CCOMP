#include <iostream>

void setDatos(int &op1, int &op2, int &modulo, char &operacion) {
    std::cout << "CALCULADORA MODULAR" << std::endl;

    std::cout << "Operacion ( + , - , * ): " ; std::cin >> operacion;
    std::cout << "Operador 1: "; std::cin >> op1;
    std::cout << "Operador 2: "; std::cin >> op2;
    std::cout << "Modulo: "; std::cin >>modulo;
}

void calcular(int op1, int op2, int modulo, char operacion) {
    switch(operacion) {
        case '+': {
            int x = op1 + op2; // 4 + 5
            int y = x % modulo; // 9 % 6 = 3
            if (y < 0) {
                y += modulo;
            }
            std::cout << "Respuesta: " << y << " modulo " << modulo << " = " << y << std::endl;
            break;
        }
        case '-': {
            int x = op1 - op2; // 10 - 30
            int y = x % modulo; // -20 % 6 = -2
            if (y < 0) {
                y += modulo; // -2 + 6 = 4
            }
            std::cout << "Respuesta: " << y << " modulo " << modulo << " = " << y << std::endl;
            break;
        }
        case '*': {
            int x = op1 * op2; // -3 * 5 = -15
            int y = x % modulo; // -15 % 6 = -3
            if (y < 0) {
                y += modulo; // -3 + 6 = 3
            }
            std::cout << "Respuesta: " << y << " modulo " << modulo << " = " << y << std::endl;
            break;
        }
        default:
            std::cout << "Operacion no valida" << std::endl;
    }
}

int main() {
    char operacion, continuar;
    int operador1, operador2, modulo;

    do {
        setDatos(operador1, operador2, modulo, operacion);
        calcular(operador1, operador2, modulo, operacion);

        std::cout << "\nContinuar? (s/n): "; std::cin >>continuar;
    } while (continuar == 's' || continuar == 'S');
}