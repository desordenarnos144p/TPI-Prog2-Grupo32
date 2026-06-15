#pragma once

#include "persistencia/ArchivoTurno.h"
#include "entidades/Turno.h"

class ManagerTurno{
    private:
        ArchivoTurno _repoTurno;
    public:
        //CONSTRUCTOR.
            ManagerTurno();
        //METODOS.
            bool agregar();
            bool modificar();
            bool bajaLogica();
            Turno buscarPorId(int id);
            bool existe(int id);
            void listar();
            void listarPorFecha();
};