#include "Serpiente.h"
#include <iostream>
#include <Windows.h>
using namespace std;

Serpiente::Serpiente()
{
	this->n = 0;
	this->tamanio = 4;
	this->x = 10;
	this->y = 12;
    //this->cuerpo[0][0] = this->x;
    //this->cuerpo[0][1] = this->y;
	this->velocidad = 100;
}


void Serpiente::guardarPosicion()
{
    this->cuerpo[this->n][0] = this->x;
    this->cuerpo[this->n][1] = this->y;
    this->n++;
    if (this->n == this->tamanio) this->n = 0;
}

void Serpiente::Pintar()
{
    for (int i = 0; i < this->tamanio; i++)
    {
        gotoxy(this->cuerpo[i][0], this->cuerpo[i][1]);
        cout << "";
    }
}


void Serpiente::Borrar()
{
    //gotoxy(this->cuerpo[this->n][0], this->cuerpo[this->n][1]);
    //cout << " ";
    for (int i = 0; i < this->tamanio; i++)
    {
        gotoxy(this->cuerpo[i][0], this->cuerpo[i][1]);
        cout << " ";
    }
}




bool Serpiente::comida(Comida &obj)
{
    if (this->x == obj.x && this->y == obj.y)
    {
        gotoxy(obj.x, obj.y);
        cout << " ";
        obj.x = (rand() % 70 + 5);
        obj.y = (rand() % 19 + 5);
        if (obj.retornarFruta() == "M")
        {
            this->tamanio++;
        }
        else if (obj.retornarFruta() == "F")
        {
            this->tamanio += 2;
        }
        else if (obj.retornarFruta() == "B")
        {
            this->tamanio += 3;
        }
        else if (obj.retornarFruta() == "P")
        {
            this->tamanio -= 1;
        }
        else
        {
            this->tamanio--;
        }
        
        gotoxy(obj.x, obj.y);
        cout << obj.retornarFruta();
        return true;
    }
    else
    {
        return false;
    }
}


bool Serpiente::Collision()
{
    return(this->x == 2 || this->x == 77 || this->y == 6 || this->y == 27) ? true : false;
}



void Serpiente::gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}



