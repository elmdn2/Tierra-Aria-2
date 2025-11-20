#include "Basura.h"

Basura::Basura(int x, int y) : Entidad(x, y, "Images/Trash.png", 1, 1)
{
	ancho = 60;
	alto = 90;
}

void Basura::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	canvas->DrawImage(sprite, x, y, ancho, alto);
}
