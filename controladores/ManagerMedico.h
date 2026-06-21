#pragma once

#include "persistencia/ArchivoEspecialidad.h"
#include "persistencia/ArchivoMedico.h"
#include "entidades/Medico.h"

//#include "EspecialidadArchivo.h" //¿Por que se incluye especialidad archivo?

class ManagerMedico{
    private:
        ArchivoMedico _repoMedico;
        ArchivoEspecialidad _repoEspecialidad; //¿Por que se declara _repoEspecialidad?
    public:
        //CONSTRUCTOR.
            ManagerMedico();
        //METODOS.
            void agregar();
            //AGREGAR: bool modificar();
            void bajaLogica();
            //AGREGAR: Medico buscarPorId(int id);
            //AGREGAR: bool existe(int id);
            void listar(); //luego mejorar.
            void modificarMatricula();
            void listarPorApellido();
            void listarPorEspecialidad();
        //AYUDANTES
            void pedirMatriculaAlUsuario(char* matriculaDestino); //Esta funcion la cumple agregar.
};
