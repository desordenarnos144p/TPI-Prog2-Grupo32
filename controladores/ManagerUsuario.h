#pragma once

#include "persistencia/ArchivoUsuario.h"
#include "../entidades/Usuario.h"

class ManagerUsuario{
    private:
        ArchivoUsuario _repoUsuario;
    public:
        //CONSTRUCTOR.
            ManagerUsuario();
        //METODOS.
            bool agregar();
            bool modificar();
            bool bajaLogica();
            Usuario buscarPorId(int id);
            bool existe(int id);
            void listar();
            int getNuevoId();
};
