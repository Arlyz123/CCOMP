#include <iostream>
#include <string>

std::string nombresDiasSemana[7] = { "D", "L", "M", "M", "J", "V", "S" };
int diasPorMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int calcularPrimerDiaEnero(int anio) {
    int primerDia1900 = 1; // lunes _ el 1 de enero de 1900 cae lunes y segun la lista el indice es el 1
    int diferencia = anio - 1900;
    int primerDiaAnio = (primerDia1900 + diferencia) % 7;

    if (diferencia > 0) {
        // calcula la cantidad de años bisiestos hasta el año anterior
        int bisiestos = 0;
        for (int i = 1900; i < anio; ++i) {
            if (esBisiesto(i)) {
                ++bisiestos;
            }
        }
        primerDiaAnio += bisiestos; // suma los años bisiestos encontrados
    }

    if (primerDiaAnio < 0) {
        primerDiaAnio += 7;
    }
    return primerDiaAnio;
}

int calcularDiasDesdeInicioAnio(int dia, int mes, int anio) {
    int primerDiaEnero = calcularPrimerDiaEnero(anio);
    int diasDesdeInicioAnio = 0;

    for (int i = 1; i < mes; i++) {
        diasDesdeInicioAnio += diasPorMes[i - 1];
        if (i == 2 && esBisiesto(anio)) {
            diasDesdeInicioAnio++;
        }
    }
    diasDesdeInicioAnio += dia - 1;
    diasDesdeInicioAnio %= 7;

    return diasDesdeInicioAnio;
}

void imprimirCalendarioMes(int dia, int mes, int anio) {
    int primerDiaEnero = calcularPrimerDiaEnero(anio);
    int diasDesdeInicioAnio = calcularDiasDesdeInicioAnio(1, mes, anio);
    int primerDiaMes = (primerDiaEnero + diasDesdeInicioAnio) % 7;

    // imprime los nombres de los dias de la semana
    for (int i = 0; i < 7; i++) {
        std::cout << nombresDiasSemana[i] << "\t";
    }
    std::cout << std::endl;

    // Imprime espacios hasta llegar al dia de la semana en que comienza el mes
    for (int i = 0; i < primerDiaMes; i++) {
        std::cout << "\t";
    }

    // imprime los dias del mes
    int diasEnMes = diasPorMes[mes - 1];
    if (mes == 2 && esBisiesto(anio)) {
        diasEnMes = 29;
    }

    int diaActual = 1;
    for (int i = 0; i < diasEnMes; i++) {
        std::cout << diaActual++ << "\t";
        if ((i + primerDiaMes + 1) % 7 == 0) {
            std::cout << std::endl;
        }
    }
}

int main() {
    int dia, mes, anio;
    std::cout << "Ingrese el día, mes y año (dia mes año): ";
    std::cin >> dia >> mes >> anio;

    imprimirCalendarioMes(dia, mes, anio);

}