#include "Arbol.h"

Arbol::Arbol(int x, int y) :Entidad(x, y, "Images/Tree.png", 1, 1)
{
	ancho = alto = 200;
}

void Arbol::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	canvas->DrawImage(sprite, x, y, ancho, alto);
}
