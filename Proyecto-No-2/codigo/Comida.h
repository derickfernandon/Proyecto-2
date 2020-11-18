#pragma once
using namespace std;
#include <string>
class Comida
{
private:
	int pos;
	string self_f;
	string fruits;
public:
	string retornarFruta();
	int x;
	int y;
	Comida();
	void PintarComida();
	void gotoxy(int, int);
};

