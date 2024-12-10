// TALLER2_2DOSEMESTRE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "TableroGato.h"
#include <iostream>
using namespace std;

int main()
{
    TableroGato board;
    bool playerTurnCheck = true; // true = player 1 (X), false = player 2 (O)
    int fila, columna;

    while (true) {
        board.mostrarTablero();

        // Mostrar el jugador actual
        cout << "Turno de " << (playerTurnCheck ? "Player 1 (X)" : "Player 2 (O)") << endl;

        // Ciclo hasta que haya un movimiento valido
        bool movimientoValido = false;
        while (!movimientoValido) {
            cout << "Ingrese fila (0-2): ";
            cin >> fila;
            cout << "Ingrese columna (0-2): ";
            cin >> columna;

            // Chequeo si coordenadas están dentro del tablreo
            if (fila < 0 || fila >= 3 || columna < 0 || columna >= 3) {
                cout << "ERROR: Fuera de rango. Intente de nuevo.\n";
                continue;
            }

            // Intentar realizar el movimiento
            char jugador = playerTurnCheck ? 'X' : 'O';
            movimientoValido = board.HacerMovimiento(fila, columna, jugador);
            if (!movimientoValido) {
                cout << "ERROR: Espacio ocupado. Intente de nuevo.\n";
            }
        }

        // Verificar si hay un ganador
        char ganador = board.checkGanador();
        if (ganador != '-') {
            board.mostrarTablero();
            cout << "¡" << (ganador == 'X' ? "Player 1" : "Player 2") << " gana!\n";
            break;
        }

        // Verificar empate
        if (board.empate()) {
            board.mostrarTablero();
            cout << "¡Es un empate!\n";
            break;
        }

        // Alternar turno
        playerTurnCheck = !playerTurnCheck;
    }

    return 0;
}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
