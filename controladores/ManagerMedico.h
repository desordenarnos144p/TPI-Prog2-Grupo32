#pragma once
#include "MedicoArchivo.h"
#include "EspecialidadArchivo.h"

class MedicoManager{
public:
    MedicoManager();
    void cargarMedico();
    void eliminarMedico();
    void listar();
    void modificarMatricula();

    //LISTADOS
    void listadoOrdenadoPorApellido();
    void listadoOrdenadoPorEspecialidad();

    //CONSULTAS
    //.......

    //AYUDANTES
    void pedirMatriculaNuevaAlUsuario(char* matriculaDestino);
private:
    MedicoArchivo _repoMedico;
    EspecialidadArchivo _repoEspecialidad;
};
