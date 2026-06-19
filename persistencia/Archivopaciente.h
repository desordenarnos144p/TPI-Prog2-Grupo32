#pragma once

#include "../entidades/Paciente.h"

class ArchivoPaciente{
    private:
        char _nombreArchivo[20]; //CAMBIAR A 50, TODOS SON DE 50
    public:
        //CONSTRUCTOR.
            ArchivoPaciente(const char* nombreArchivo = "Pacientes.dat");
        //GETTERS.
            int getNuevoId();
            int getCantidadRegistros();
        //METODOS.
            bool guardar(Paciente reg);
            Paciente leer(int pos);
            //AGREGAR: int buscarPosicion(int id);
            bool modificar(Paciente reg, int pos);
            //AGREGAR: bool bajaLogica(int posicion);
};
