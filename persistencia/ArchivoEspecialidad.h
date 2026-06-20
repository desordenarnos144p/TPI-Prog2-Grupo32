#pragma once
#include "Especialidad.h"
class ArchivoEspecialidad{
public:
    ArchivoEspecialidad(const char* nombreArchivo = "Especialidad.dat");

    bool guardar(Especialidad reg);
    Especialidad leer(int pos);
    int getCantidadRegistros();
    bool modificar(const Especialidad &reg, int pos);
    int getNuevoId();

    int buscarEspecialidad(const char* especialidad);
private:
    char _nombreArchivo[50];
};
