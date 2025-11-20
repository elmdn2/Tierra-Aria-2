#include "Chaos.h"

Chaos::Chaos(int x, int y)
	:Entidad(x, y, "Images/Chaos.png", 3, 2)
{
	vidas = 3;
	dx = dy = 10;
	movimiento = Abajo;
	indiceAlto = 1;
}

void Chaos::moverTeclas(Graphics^ canvas,
	Movimiento movimiento)
{
	this->movimiento = movimiento;
	switch (movimiento)
	{
	case Arriba:
		y -= dy;
		break;
	case Abajo:
		y += dy;
		break;
	case Derecha:
		x += dx;
		indiceAlto = 1;
		break;
	case Izquierda:
		x -= dx;
		indiceAlto = 0;
		break;
	}
	if (x < 0) {
		x = 0;
	}
	if (y < 0) {
		y = 0;
	}
	if (x + ancho > canvas->VisibleClipBounds.Width) {
		x = canvas->VisibleClipBounds.Width - ancho;
	}
	if (y + alto > canvas->VisibleClipBounds.Height) {
		y = canvas->VisibleClipBounds.Height - alto;
	}
	indiceAncho++;
	if (indiceAncho > 2) {
		indiceAncho = 0;
	}
}

Movimiento Chaos::getMovimiento()
{
	return movimiento;
}
