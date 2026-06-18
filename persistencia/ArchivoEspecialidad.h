#pragma once
#include "Especialidad.h"
class EspecialidadArchivo{
public:
    EspecialidadArchivo();

    bool guardar(Especialidad reg);
    Especialidad leer(int pos);
    int getCantidadRegistros();
    bool modificar(const Especialidad &reg, int pos);
    int getNuevoId();

    int buscarEspecialidad(const char* especialidad);
private:
    char _nombreArchivo[50];
};
