#ifndef INVERSOMODULAR_H
#define INVERSOMODULAR_H

#include <iostream>
#include <fstream>
#include <string>

class InversoModular {
private:
    const int modulo = 256;;

public:
    InversoModular(int mod) : modulo(mod) {}

    int inverso(int a_invertir) {
        int U0 = 0;
        int U1 = 1;
        int Un = 0;
        int num2 = a_invertir;
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
            
            // verificar que la division no sea entre cero, lo de la linea 25 en la segunda vuelta
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
            std::cout << "No se puede calcular el inverso modular para " << a_invertir << " modulo " << modulo << std::endl;
            return -1; // no existe
        }
    }

    void cifrarTexto(const std::string& textoOriginal, int op1) {
        std::ofstream archivoCifrado("cifrado.txt");
        for (char c : textoOriginal) {   
            // std:: cout << c << std::endl; 
            // std:: cout << op1 << std::endl;
            // std:: cout << c + op1 << std::endl;
            char nuevo_caracter = (c + op1) % 256;
            archivoCifrado << nuevo_caracter;
        }
        archivoCifrado.close();
    }

    void descifrarTexto(int op1) {
        std::ifstream archivoCifrado("cifrado.txt");
        std::ofstream archivoDescifrado("descifrado.txt");

        char caracter;
        while (archivoCifrado.get(caracter)) {
            char original_caracter = caracter - op1;
            archivoDescifrado << original_caracter;
        }

        archivoCifrado.close();
        archivoDescifrado.close();
    }
};

#endif // INVERSOMODULAR_H