#include "Comida.h"
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;



Comida::Comida()
{
    this->pos = 1;
	this->x = 30;
	this->y = 20;
    this->fruits = "MFBPI";
	this->self_f = "M";
}


string Comida::retornarFruta()
{
    return this->self_f;
}

void Comida::PintarComida()
{
	gotoxy(this->x, this->y); cout << this->self_f << endl;
    if (this->pos < this->fruits.length())
    {
        this->pos++;
        this->self_f = this->fruits[this->pos];
    }
    else
    {
        if (pos >= 0)
        {
            this->pos--;
            this->self_f = this->fruits[this->pos];
        }
    }
}

void Comida::gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

