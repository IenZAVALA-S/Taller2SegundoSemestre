#pragma once
class TableroGato
{
private:
	char board[3][3]; //Guarda textualmente X's y O's
	bool boardcheck[3][3];
public:
	TableroGato();
	bool HacerMovimiento(int col, int fila, bool player);
	void mostrarTablero();
	bool checkGanador();
	bool empate();
};

