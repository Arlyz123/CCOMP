#include <iostream>
#include <string>

void setDate(int &mm, int &aa) {
    std::cout << "Introduce el mes: ";
    std::cin >> mm;
    if (mm < 1 || mm > 12) {
        std::cout << "Introduce un mes entre 1 y 12: ";
        std::cin >> mm;
    }
    std::cout << "Introduce el año: ";
    std::cin >> aa;
    std::cout << "Fecha seleccionada: " << mm << "/" << aa << std::endl;
}

bool anioBisiesto(int aa) {
    if(aa % 400 == 0 || (aa % 100 != 0 && aa % 4 == 0)) 
        return true;
    else
        return false;
}

int diaSemana(int dd, int mm, int aa) {
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    aa -= mm < 3;
    return (aa + aa/4 - aa/100 + aa/400 + t[mm-1] + dd) % 7;
}

void imprimirCalendario(int diaInicio, int diasEnMes) {
    std::string diasSemana[7] = {"D", "L", "M", "M", "J", "V", "S"};
    int dia = 1;

    // Imprimir encabezado
    for(int i = 0; i < 7; i++) {
        std::cout << diasSemana[i] << "\t";
    }
    std::cout << std::endl;

    // Espacios para el día de inicio
    for (int i = 0; i < diaInicio; i++) {
        std::cout << "\t";
    }

    // Imprimir días del mes
    for(int i = 0; i < diasEnMes; i++) {
        std::cout << dia << "\t";
        dia++;
        diaInicio++;
        if (diaInicio % 7 == 0) {
            std::cout << std::endl;
        }
    }
}

int main() {
    int mes, anio;
    setDate(mes, anio);

    // Determinar el día de la semana del primer día del mes
    int diaInicio = diaSemana(1, mes, anio);

    // Determinar la cantidad de días en el mes
    int diasEnMes;
    if (mes == 2 && anioBisiesto(anio))
        diasEnMes = 29;
    else if (mes == 2)
        diasEnMes = 28;
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        diasEnMes = 30;
    else
        diasEnMes = 31;

    // Imprimir calendario
    imprimirCalendario(diaInicio, diasEnMes);

    return 0;
}
