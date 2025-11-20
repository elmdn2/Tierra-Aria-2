#include "Semilla.h"

Semilla::Semilla(int x, int y) :Entidad(x, y, "Images/Seed.png", 1, 1)
{
	ancho = 30;
	alto = 40;
}

void Semilla::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	canvas->DrawImage(sprite, x, y, ancho, alto);
}
