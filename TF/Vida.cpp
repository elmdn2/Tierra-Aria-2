#include "Vida.h"

Vida::Vida(int x, int y) :Entidad(x, y, "Images/Heart.png", 1, 1)
{
	ancho = 44;
	alto = 48;
}

void Vida::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	canvas->DrawImage(sprite, x, y, ancho, alto);
}
