#include <iostream>
#include <conio.h>
#include <ctime>
#include <locale.h>
#include <stdio.h>
#include "App.h"
using namespace std;



class Nodo
{
private:
    int punteo;
    string descripcion;
public:
    Nodo* siguiente;
    Nodo()
    {
        this->punteo = 0;
        this->descripcion = "";
        this->siguiente = NULL;
    }

    void Insertar(int n, string d)
    {
        this->punteo = n;
        this->descripcion = d;
    }

    int retornarPunteo()
    {
        return this->punteo;
    }

    string retornarDes()
    {
        return this->descripcion;
    }
};


class Lista
{
private:
    Nodo* frente;
    Nodo* final;
    int tamanio;
public:

    Lista()
    {
        this->frente = NULL;
        this->final = NULL;
    }

    void InsertarVacia(int n, string d)
    {
        Nodo* nuevo = new Nodo();
        nuevo->Insertar(n, d);
        this->frente = nuevo;
        this->final = nuevo;
    }

    bool EstaVacia()
    {
        return(this->frente == NULL) ? true : false;
    }

    void InsertarFrente(int n, string d)
    {
        if (this->EstaVacia())
        {
            this->InsertarVacia(n, d);
        }
        else
        {
            Nodo* nuevo = new Nodo();
            nuevo->Insertar(n, d);
            nuevo->siguiente = this->frente;
            this->frente = nuevo;
        }
        this->tamanio++;
    }

    void Mostrar()
    {
        if (this->EstaVacia())
        {
            cout << "No se ha jugado ninguna pardita por el momento" << endl;
        }
        else
        {
            int cont = 1;
            Nodo* aux = this->frente;
            while (aux != NULL)
            {
                cout << "Partida #" << cont << "Nivel: " << aux->retornarDes() << " Punteo: " << aux->retornarPunteo() << endl;
                aux = aux->siguiente;
                cont++;
            }
        }
        
    }
};




int main()
{
    Lista lis = Lista();
    int opcion;
    App app;
    do
    {
        system("color 0F");
        system("cls");
        cout << "(1) Facil \n";
        cout << "(2) Intermedio \n";
        cout << "(3) Dificil \n";
        cout << "(4) Dinamico \n";
        cout << "(5) Historial de partidas \n";
        cout << "(6) Salir \n";
        cout << "opcion: ";
        cin >> opcion;
        system("cls");
        if (opcion == 6)
        {
            exit(3);
        }
        else if (opcion == 5)
        {
            system("cls");
            cout << "| HISTORIAL |" << endl;
            lis.Mostrar();
            system("pause");
        }
        app = App();
        app.Modificar(opcion);
        int aux = app.Principal();
        if (opcion == 1)
        {
            lis.InsertarFrente(aux, "Nivel Facil");
        }
        else if (opcion == 2)
        {
            lis.InsertarFrente(aux, "Nivel Intermedio");
        }
        else if (opcion == 3)
        {
            lis.InsertarFrente(aux, "Nivel Dificil");
        }


    } while (opcion != 6);
    
    
}
