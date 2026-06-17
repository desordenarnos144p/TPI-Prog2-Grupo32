#pragma once

#include "../persistencia/ArchivoPaciente.h"

class ManagerPaciente{
    private:
        ArchivoPaciente _repoPaciente;
    public:
        //CONSTRUCTOR.
            ManagerPaciente();
        //METODOS.
            void agregar();
            void modificar();
            void bajaLogica();
            //AGREGAR: Paciente buscarPorId(int id);
            //AGREGAR: bool existe(int id);
            void listar();
            //AGREGAR: void listarPorNombre();
            //AGREGAR: void listarPorEdad();
            //AGREGAR: void listarPorObraSocial();
};
