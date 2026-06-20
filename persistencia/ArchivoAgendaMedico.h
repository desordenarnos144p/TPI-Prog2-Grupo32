#pragma once

#include "../entidades/AgendaMedico.h"

class ArchivoAgendaMedico{
private:
    char _nombreArchivo[30];

public:

    ArchivoAgendaMedico(const char* nombreArchivo = "AgendaMedico.dat");

    bool guardar(AgendaMedico reg);

    AgendaMedico leer(int pos);

    bool modificar(AgendaMedico reg,int pos);

    int getCantidadRegistros();

    int getNuevoId();

    int buscarPorId(int idAgenda);
};
