#pragma once
#include "Entidad.h"
class Arbol :public Entidad
{
public:
	Arbol(int x, int y);
	void dibujarImagen(
		Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);
};
