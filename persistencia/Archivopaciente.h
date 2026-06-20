#pragma once

#include "../entidades/Paciente.h"


class ArchivoPaciente
{
private:
    char _nombreArchivo[30];

public:
    ArchivoPaciente(const char* nombreArchivo = "Pacientes.dat");

    bool guardar(Paciente reg);
    Paciente leer(int pos);
    bool modificar(Paciente reg, int pos);

    int getCantidadRegistros();
    int getNuevoId();
    int buscarPorId(int idPaciente);

    //buscar por DNI para consultas
    int buscarPorDni(const char* dni);
    int buscarPorNroAfiliado(const char* nroAfiliado);

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
