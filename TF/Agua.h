#pragma once
#include "Entidad.h"
class Agua :public Entidad
{
public:
	Agua(int x, int y);
	void dibujarImagen(
		Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);
};
