#include "App.h"
#include "Controls.h"
#include <conio.h>
#include <iostream>
using namespace std;


App::App()
{
    this->punteo = 0;
}

void App::PintarMarco()
{
    for (int i = 6; i < 27; i++)
    {
        gotoxy(2, i); cout << char(186);
        gotoxy(77, i); cout << char(186);
    }
    for (int i = 2; i < 78; i++)
    {
        gotoxy(i, 6); cout << char(205);
        gotoxy(i, 27); cout << char(205);
    }

    gotoxy(2, 6); cout << char(201);
    gotoxy(2, 27); cout << char(200);
    gotoxy(77, 6); cout << char(187);
    gotoxy(77, 27); cout << char(188);
}


void App::PintarEnd()
{
    this->PintarMarco();
    system("color 0A");
    gotoxy(80, 20);
    cout << "GAME OVER";
}


int App::Controlls(int dir)
{
    if (_kbhit())
    {
        char tecla = _getch();
        if (tecla == 72)//up
        {
            if (dir != 2)
            {
                dir = 1;
            }
        }
        else if (tecla == 80)//down
        {
            if (dir != 1)
            {
                dir = 2;
            }

        }
        else if (tecla == 77)//right
        {
            if (dir != 4)
            {
                dir = 3;
            }

        }
        else if (tecla == 75)
        {
            if (dir != 3)
            {
                dir = 4;
            }

        }
    }
    return dir;
}


int App::Principal()
{
    int dir = 3;
    hidecursor();
    this->PintarMarco();
    gotoxy(this->comida.x, this->comida.y); cout << "o";
    while (!this->serpiente.Collision())
    {
        
        this->PintarMarco();
        gotoxy(2, 2); cout << "Punteo: " << this->punteo;
        this->serpiente.Borrar();
        this->serpiente.guardarPosicion();
        gotoxy(this->comida.x, this->comida.y); cout << "o";
        this->serpiente.Pintar();
        if (this->serpiente.comida(this->comida))this->punteo++;
        dir = this->Controlls(dir);
        if (dir == 1)this->serpiente.y--;
        if (dir == 2)this->serpiente.y++;
        if (dir == 3)this->serpiente.x++;
        if (dir == 4)this->serpiente.x--;
        Sleep(this->serpiente.velocidad-10);
        //system("cls");

    }
    gotoxy(2, 2); cout << "Punteo: " << this->punteo;
    this->serpiente.Pintar();
    this->PintarEnd();
    _getch();
    return this->punteo;
}

void App::Modificar(int op)
{
    if (op == 1)
    {
        serpiente.velocidad = 100;
    }
    else if (op == 2)
    {
        this->serpiente.velocidad = 110;
    }
    else if (op == 3)
    {
        this->serpiente.velocidad = 115;
    }
    else if(op == 4)
    {
        this->serpiente.velocidad = 120;
    }
}