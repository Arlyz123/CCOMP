#include <iostream>
#include <fstream>
#include <string>
#include "inverso.h"

int main() {
    int opcion;
    char continuar;
    bool salir = false;

    std::cout << "Bienvenido al sistema de encriptado y desencriptado\n";

    do {
        std::cout << "Seleccione una opcion:\n" << "1. Encriptar\n" << "2. Desencriptar\n";
        std::cin >> opcion;

        if (opcion == 1) {
            std::ifstream archivoEntrada("original.txt");
            if (!archivoEntrada) {
                std::cerr << "Error al abrir el archivo de entrada" << std::endl;
                return 1;
            }

            std::string textoOriginal;
            std::getline(archivoEntrada, textoOriginal);

            int modulo = 256;
            int clavePublica;
            std::cout << "Ingrese su clave publica: ";
            std::cin >> clavePublica;

            InversoModular calculadora(256);

            // inverso modular de la clave publica mod 256
            int inverso = calculadora.inverso(clavePublica);

            if (inverso == -1) {
                std::cout << "El numero " << clavePublica << " no tiene inverso modular respecto a " << modulo << ". Intente con otro numero" << std::endl;
            } else {
                std::cout << "El inverso modular de " << clavePublica << " respecto a " << modulo << " es: " << inverso << std::endl;

                // cifrar el texto original y guardar en archivo cifrado.txt
                calculadora.cifrarTexto(textoOriginal, inverso);
                std::cout << "Texto encriptado correctamente\n";
            }
            archivoEntrada.close();

        } else if (opcion == 2) {
            int clavePrivada; // desencriptar el archivo cifrado.txt
            std::cout << "Ingrese la clave privada (inverso modular) para desencriptar: ";
            std::cin >> clavePrivada;

            // crear instancia de la inverso modular con el modulo específico
            InversoModular calculadora(256);

            // descifrar el texto en cifrado.txt y guardar en archivo descifrado.txt
            calculadora.descifrarTexto(clavePrivada);
            std::cout << "Texto desencriptado correctamente\n";
        } else {
            std::cout << "Opcion no valida. Seleccione 1 o 2\n";
        }

        std::cout << "¿Desea continuar? (s/n): ";
        std::cin >> continuar;

        if (continuar == 'n' || continuar == 'N') {
            salir = true;
        }

    } while (!salir);

    std::cout << "Gracias por usar el sistema de encriptado y desencriptado\n";
}