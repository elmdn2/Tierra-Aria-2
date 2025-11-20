#include "Residuo.h"

Residuo::Residuo(int x, int y) :Entidad(x, y, "Images/Residuo.png", 1)
{
	ancho = alto = 40;
}

void Residuo::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	canvas->DrawImage(sprite, x, y, ancho, alto);
}
