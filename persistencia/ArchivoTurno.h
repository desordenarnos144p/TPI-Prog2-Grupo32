#pragma once

#include "../entidades/Turno.h"

class ArchivoTurno
{
private:
    char _nombreArchivo[20];

public:
    ArchivoTurno(const char* nombreArchivo = "Turnos.dat");

    int getNuevoId();
    int getCantidadRegistros();

    bool guardar(Turno reg);
    Turno leer(int posicion);
    int buscarPosicion(int id);
    bool modificar(Turno reg, int posicion);
    bool bajaLogica(int posicion);
};
