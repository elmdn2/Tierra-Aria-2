#include "Juego.h"

Juego::Juego(int width, int height)
{
	background = new Background;
	chaos = new Chaos(10, height / 2 + 50);
	Random r;
	gameOver = false;
	Ganamos = false;
	for (int i = 0; i < 15; i++)
	{
		int posicionX = r.Next(130, width - 60 - 65);
		int posicionY = r.Next(80, height - 90 - 25);
		basura.push_back(new Basura(posicionX, posicionY));
	}
	for (int i = 0; i < 10; i++)
	{
		int posicionX = r.Next(130, width - 60 - 65);
		int posicionY = r.Next(80, height - 90 - 25);
		agua.push_back(new Agua(posicionX, posicionY));
	}
	for (int i = 0; i < 10; i++)
	{
		int posicionX = r.Next(130, width - 60 - 65);
		int posicionY = r.Next(80, height - 90 - 25);
		semillas.push_back(new Semilla(posicionX, posicionY));
	}
	for (int i = 0; i < 10; i++)
	{
		int posicionX = r.Next(130, width - 60 - 65);
		int posicionY = r.Next(80, height - 90 - 25);
		residuos.push_back(new Residuo(posicionX, posicionY));
	}
	for (int i = 0; i < chaos->getVidas(); i++)
	{
		Vida* vida = new Vida(0, 0);
		vida->setX(vida->getAncho() * i);
		vida->setY(5);
		vidas.push_back(vida);
	}
}

void Juego::mostrar(Graphics^ canvas)
{
	background->mostrar(canvas);
	chaos->mostrar(canvas);
	for (int i = 0; i < arbol.size(); i++)
	{
		arbol[i]->mostrar(canvas);
	}
	for (int i = 0; i < basura.size(); i++)
	{
		basura[i]->mostrar(canvas);
	}
	for (int i = 0; i < agua.size(); i++)
	{
		agua[i]->mostrar(canvas);
	}
	for (int i = 0; i < semillas.size(); i++)
	{
		semillas[i]->mostrar(canvas);
	}
	for (int i = 0; i < residuos.size(); i++)
	{
		residuos[i]->mostrar(canvas);
	}
	for (int i = 0; i < vidas.size(); i++)
	{
		vidas[i]->mostrar(canvas);
	}
}

void Juego::mover(Graphics^ canvas)
{
	if (gameOver) {
		return;
	}
	if (Ganamos) {
		return;
	}
	int Tbasura = basura.size();
	for (int i = 0; i < Tbasura; i++)
	{
		if (chaos->hayColision(basura[i])) {
			delete basura[i];
			basura.erase(basura.begin() + i);
			Tbasura--;
			Nbasura--;
			chaos->setVidas(chaos->getVidas() - 1);
			if (vidas.size() == 1) {
				gameOver = true;
			}
			if (vidas.size() > 0) {
				vidas.erase(vidas.begin() + vidas.size() - 1);
			}


		}

	}
	if (Nbasura <= 0) {
		Ganamos = true;
	}
	for (int i = 0; i < arbol.size(); i++)
	{
		for (int j = 0; j < Tbasura; j++)
		{
			if (arbol[i]->hayColision(basura[j])) {
				delete basura[j];
				basura.erase(basura.begin() + j);
				Tbasura--;
				Nbasura--;
			}
		}
	}

	int Tagua = agua.size();
	for (int i = 0; i < Tagua; i++)
	{
		if (chaos->hayColision(agua[i])) {
			delete agua[i];
			agua.erase(agua.begin() + i);
			Tagua--;
			Nagua++;
		}
	}
	int Tsemilla = semillas.size();
	for (int i = 0; i < Tsemilla; i++)
	{
		if (chaos->hayColision(semillas[i])) {
			delete semillas[i];
			semillas.erase(semillas.begin() + i);
			Tsemilla--;
			Nsemilla++;
		}
	}
	int Tresiduo = residuos.size();
	for (int i = 0; i < Tresiduo; i++)
	{
		if (chaos->hayColision(residuos[i])) {
			delete residuos[i];
			residuos.erase(residuos.begin() + i);
			Tresiduo--;
			Nresiduo++;
		}
	}

}

void Juego::agregarArbol()
{
	if (Nagua > 0 && Nsemilla > 0) {
		arbol.push_back(new Arbol(chaos->getX() - 80, chaos->getY() - 80));
		Nsemilla--;
		Nagua--;
	}

}


void Juego::moverTeclas(Graphics^ canvas, Movimiento movimiento)
{
	chaos->moverTeclas(canvas, movimiento);
}

bool Juego::getGameOver()
{
	return gameOver;
}

bool Juego::getGanamos()
{
	return Ganamos;
}