#pragma once
#include "Entidad.h"
class Residuo :public Entidad
{
public:
	Residuo(int x, int y);
	void dibujarImagen(
		Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);
};
