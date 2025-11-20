#pragma once
#include "Entidad.h"
class Semilla :public Entidad
{
public:
	Semilla(int x, int y);
	void dibujarImagen(
		Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);
};
