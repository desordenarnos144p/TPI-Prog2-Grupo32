#pragma once

#include "../entidades/Pago.h"

class ArchivoPago{
private:
    char _nombreArchivo[20];

public:
    ArchivoPago(const char* nombreArchivo = "Pagos.dat");

    int getNuevoId();
    int getCantidadRegistros();

    bool guardar(Pago reg);
    Pago leer(int posicion);
    int buscarPosicion(int id);
    bool modificar(Pago reg, int posicion);
    bool bajaLogica(int posicion);
};
