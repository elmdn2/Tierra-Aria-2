#pragma once
#include "Entidad.h"
class Vida :public Entidad
{
public:
	Vida(int x, int y);
	void dibujarImagen(
		Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);
};

