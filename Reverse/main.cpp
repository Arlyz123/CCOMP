#include <iostream>
using namespace std;

const int tamArr = 8;
const char casilla_vacia = '-';
const char ficha1 = '*';
const char ficha2 = 'O';


void imprimirTablero(char** board) {
    cout << "  1 2 3 4 5 6 7 8" << endl;
    for (int i = 0; i < tamArr; i++) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < tamArr; j++) {
            cout << *(*(board + i) + j) << " ";
        }
        cout << endl;
    }
}

void iniTablero(char** board) {
    for (int i = 0; i < tamArr; i++) {
        for (int j = 0; j < tamArr; j++) {
            *(*(board + i) + j) = casilla_vacia;
        }
    }
    *(*(board + tamArr / 2 - 1) + tamArr / 2 - 1) = ficha2;
    *(*(board + tamArr / 2 - 1) + tamArr / 2) = ficha1;
    *(*(board + tamArr / 2) + tamArr / 2 - 1) = ficha1;
    *(*(board + tamArr / 2) + tamArr / 2) = ficha2;
}

// Función para realizar un movimiento en el tablero
void makeMove(char** board, int fila, int columna, char jugador) {
    // Colocar la ficha del jugador en la posición especificada
    *(*(board + fila) + columna) = jugador;

    int mov_izq_der[] = { 0, 0, 1, -1 };
    int mov_arr_aba[] = { 1, -1, 0, 0 };

    // si hay fichas del oponente para voltear
    for (int i = 0; i < 4; i++) {
        int x = fila + mov_izq_der[i];
        int y = columna + mov_arr_aba[i];
        bool encontrar_oponente = false;
        while (x >= 0 && x < tamArr && y >= 0 && y < tamArr && *(*(board + x) + y) != casilla_vacia) {
            if (*(*(board + x) + y) != jugador) {
                encontrar_oponente = true;
            }
            else if (encontrar_oponente) {
                // Voltear fichas del oponente entre la posición actual y la ficha del jugador
                int voltear_fila = fila + mov_izq_der[i];
                int voltear_columna = columna + mov_arr_aba[i];
                while (voltear_fila != x || voltear_columna != y) {
                    *(*(board + voltear_fila) + voltear_columna) = jugador;
                    voltear_fila += mov_izq_der[i];
                    voltear_columna += mov_arr_aba[i];
                }
                break;
            }
            else {
                break;
            }
            x += mov_izq_der[i];
            y += mov_arr_aba[i];
        }
    }
}

// Función para verificar la validez de un movimiento
bool ValidezdeMovimiento(char** board, int fila, int columna, char jugador) {
    // Verificar si la posición especificada está vacía
    if (*(*(board + fila) + columna) != casilla_vacia) {
        return false;
    }
    // Definir las direcciones de movimiento (arriba, abajo, izquierda, derecha)
    int mov_iz_der[] = { 0, 0, 1, -1 };
    int mov_arr_aba[] = { 1, -1, 0, 0 };

    for (int i = 0; i < 4; i++) {
        int x = fila + mov_iz_der[i];
        int y = columna + mov_arr_aba[i];
        bool foundOpponent = false;
        // Mientras estemos dentro del tablero y encontremos fichas del oponente
        while (x >= 0 && x < tamArr && y >= 0 && y < tamArr && *(*(board + x) + y) != casilla_vacia) {
            if (*(*(board + x) + y) != jugador) {
                foundOpponent = true;
            }
            else if (foundOpponent) {
                return true; // Movimiento válido si encontramos al menos una ficha del oponente
            }
            else {
                break;
            }
            x += mov_iz_der[i];
            y += mov_arr_aba[i];
        }
    }

    return false; // Movimiento inválido si no se encontró ninguna ficha del oponente a capturar
}

// Función para verificar si el tablero está lleno
bool tableroLleno(char** board) {
    for (int i = 0; i < tamArr; i++) {
        for (int j = 0; j < tamArr; j++) {
            if (*(*(board + i) + j) == casilla_vacia) {
                return false; // El tablero no está lleno si hay al menos una posición vacía
            }
        }
    }
    return true; // El tablero está lleno si todas las posiciones están ocupadas
}

// Función para contar las piezas de cada jugador en el tablero
void contadorPiezas(char** board, int& contador1, int& contador2) {
    contador1 = 0;
    contador2 = 0;
    for (int i = 0; i < tamArr; i++) {
        for (int j = 0; j < tamArr; j++) {
            if (*(*(board + i) + j) == ficha1) {
                contador1++;
            }
            else if (*(*(board + i) + j) == ficha2) {
                contador2++;
            }
        }
    }
}

// Función principal del programa
int main() {
    char** board = new char* [tamArr];
    for (int i = 0; i < tamArr; i++) {
        board[i] = new char[tamArr];
    }

    // Inicializar el tablero y mostrarlo en la consola
    iniTablero(board);
    imprimirTablero(board);

    char actual_turn = ficha1;

    // Bucle principal del juego
    while (!tableroLleno(board)) {
        // Mostrar el turno del jugador actual
        cout << "Jugador " << actual_turn << " juega" << endl;
        char fila;
        int columna;
        // Solicitar al jugador que ingrese la fila y columna para realizar el movimiento
        cout << "Ingrese fila (A-H): ";
        cin >> fila;
        fila = toupper(fila) - 'A';
        cout << "Ingrese columna (1-8): ";
        cin >> columna;
        columna -= 1;

        // Verificar si el movimiento es válido y realizarlo si es así
        if (fila >= 0 && fila < tamArr && columna >= 0 && columna < tamArr && ValidezdeMovimiento(board, fila, columna, actual_turn)) {
            makeMove(board, fila, columna, actual_turn);
            imprimirTablero(board);
            // Contar las piezas de cada jugador y mostrar el resultado
            int contador1, contador2;
            contadorPiezas(board, contador1, contador2);
            cout << "*: " << contador1 << endl;
            cout << "O: " << contador2 << endl;
            actual_turn = (actual_turn == ficha1) ? ficha2 : ficha1; // Cambiar al turno del otro jugador
        }
        else {
            cout << "Movimiento invalido" << endl;
        }
    }

    // Contar las piezas de cada jugador al final del juego y mostrar el resultado
    int contador1, contador2;
    contadorPiezas(board, contador1, contador2);

    cout << "FIN DEL JUEGO" << endl;
    cout << "-*-: " << contador1 << endl;
    cout << "-O-: " << contador2 << endl;
    // Determinar el ganador o si hay empate
    if (contador1 > contador2) {
        cout << "* Gana" << endl;
    }
    else if (contador2 > contador1) {
        cout << "O Gana" << endl;
    }
    else {
        cout << "ES EMPATE!!!" << endl;
    }

    // Liberar memoria asignada para el tablero
    for (int i = 0; i < tamArr; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
} 