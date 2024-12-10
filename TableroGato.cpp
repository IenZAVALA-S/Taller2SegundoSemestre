#include "TableroGato.h"
#include <iostream>
using namespace std;

TableroGato::TableroGato() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = '-';
			boardcheck[i][j] = false;
		}
	}
}
void TableroGato::mostrarTablero() {
    cout << "Tablero actual:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool TableroGato::HacerMovimiento(int fil, int col, bool player) {
    if (!boardcheck[fil][col]) {
        board[fil][col] = player;
        boardcheck[fil][col] = true;
        return true; // Movimiento exitoso
    }
    else {
        return false; // Espacio ya ocupado
    }
}
bool TableroGato::checkGanador() {
    // Revisar filas y columnas
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return board[0][i];
        }
    }
    // Revisar diagonales
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return board[0][2];
    }
    return '-';
}

bool TableroGato::empate() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!boardcheck[i][j]) {
                return false;
            }
        }
    }
    return true;
}