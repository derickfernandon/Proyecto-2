#pragma once
#include "Comida.h"
class Serpiente
{
private:
	int cuerpo[200][2];
	int n;
	int tamanio;
public:
	int x;
	int y;
	int velocidad;
	Serpiente();
	bool Collision();
	void guardarPosicion();
	void Pintar();
	void Borrar();
	bool comida(Comida &obj);
	void gotoxy(int, int);
};

