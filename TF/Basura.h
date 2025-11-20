#pragma once
#include "Entidad.h"
class Basura :public Entidad
{
public:
	Basura(int x, int y);
	void dibujarImagen(
		Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);
};

