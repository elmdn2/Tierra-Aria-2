#pragma once
#include "Entidad.h"
class Chaos :
    public Entidad
{
public:
    Chaos(int x, int y);
    void moverTeclas(Graphics^ canvas, Movimiento movimiento);
    Movimiento getMovimiento();
};

