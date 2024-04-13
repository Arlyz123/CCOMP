#include <iostream>

void setDatos(int &op1, int &op2, int &modulo, char &operacion) {
    std::cout << "CALCULADORA MODULAR" << std::endl;
    std::cout << "Operacion ( + (suma) , - (resta) , * (multiplicacion), / (inverso)): " ; std::cin >> operacion;
    if (operacion == '/') {
        std::cout << "Operador: "; std::cin >> op1;
        std::cout << "Modulo: "; std::cin >>modulo;
    } else {
        std::cout << "Operador 1: "; std::cin >> op1;
        std::cout << "Operador 2: "; std::cin >> op2;
        std::cout << "Modulo: "; std::cin >>modulo;
    }
}

int inverso(int op1, int modulo) {
    int U0 = 0;
    int U1 = 1;
    int Un = 0;
    int num2 = op1;
    int num1 = modulo;
    int cociente_o_q = 0;
    int residuo;

    while (num1 > 1) {
        cociente_o_q = num1 / num2; // 6/2 = 3 __  2/0 = 
        residuo = num1 % num2; // 6%2 = 0
        num1 = num2; // 2
        num2 = residuo; // 0

        Un = U0 - cociente_o_q * U1;
        U0 = U1;
        U1 = Un;

        // verificar que la division no sea entre cero, lo de la linea 26 en la segunda vuelta
        if (num2 == 0) {
                break;
            }
    }

    if (num1 == 1) {
        if (U0 < 0) {
            U0 += modulo;
        }
        return U0;
    } else {
        std::cout << "No se puede calcular el inverso modular para " << op1 << " modulo " << modulo << std::endl;
        return -1; // no existe
    }
}

void calcular(int op1, int op2, int modulo, char operacion) {
    switch(operacion) {
        case '+': {
            int x = op1 + op2; // 4 + 5
            int y = x % modulo; // 9 % 6 = 3
            if (y <= 0) {
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
        case '/': {
        int inverso_mod = inverso(op1, modulo);
        if (inverso_mod != -1) {
            std::cout << "Respuesta: " << op1 << " modulo " << modulo << " = " << inverso_mod << std::endl;
        }
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

        std::cout << "\nContinuar? (s/n): " << std::endl; 
        std::cin >>continuar;
    } while (continuar == 's' || continuar == 'S');
}