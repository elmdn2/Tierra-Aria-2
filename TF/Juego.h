#pragma once
#include "Background.h"
#include "Chaos.h"
#include "Basura.h"
#include "Agua.h"
#include "Semilla.h"
#include "Arbol.h"
#include "Residuo.h"
#include "Vida.h"
#include <vector>
using namespace std;
class Juego
{
private:
	Background* background;
	Chaos* chaos;
	vector<Basura*> basura;
	vector<Agua*> agua;
	vector<Semilla*> semillas;
	vector<Arbol*> arbol;
	vector<Residuo*> residuos;
	vector<Vida*> vidas;
	int Nagua = 0;
	int Nsemilla = 0;
	int Nresiduo = 0;
	int Nbasura = 15;
	bool gameOver;
	bool Ganamos;
public:

	Juego(int width, int height);
	void mostrar(Graphics^ canvas);
	void mover(Graphics^ canvas);
	void agregarArbol();
	void moverTeclas(Graphics^ canvas, Movimiento movimiento);
	bool getGameOver();
	bool getGanamos();
};

