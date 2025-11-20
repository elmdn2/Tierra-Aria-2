#include "Agua.h"

Agua::Agua(int x, int y) :Entidad(x, y, "Images/Water.png", 1, 1)
{
	ancho = alto = 40;
}

void Agua::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	canvas->DrawImage(sprite, x, y, ancho, alto);
}
