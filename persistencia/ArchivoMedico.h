#pragma once
#include "Medico.h"
class MedicoArchivo{
public:
    MedicoArchivo(const char* nombreArchivo = "Medicos.dat");
    bool guardar(const Medico &reg);
    Medico leer(int pos);
    int getCantidadRegistros();
    bool modificar(const Medico &reg, int pos);
    int getNuevoId();

    //AYUDANTES
    int buscarMedico(const char* matricula);

    private:
    char _nombreArchivo[50];
};
