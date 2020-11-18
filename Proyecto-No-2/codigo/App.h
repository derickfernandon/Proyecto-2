#pragma once
#include "Serpiente.h"
#include "Comida.h"
class App
{
private:
	Serpiente serpiente = Serpiente();
	Comida comida = Comida();
public:
	int punteo;
	App();
	void PintarMarco();
	void PintarEnd();
	int Controlls(int);
	int Principal();
	void Modificar(int);

};

