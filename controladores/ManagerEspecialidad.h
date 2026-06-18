#pragma once
#include "ArchivoEspecialidad.h"

class ManagerEspecialidad{
public:
    ManagerEspecialidad();
    void cargarEspecialidad();
    void eliminarEspecialidad();
    void listar();
    void modificarEspecialidad();

    //LISTADOS
    void listadoOrdenadoPorEspecialidad();

    //AYUDANTES
    void pedirEspecialiadNuevaAlUsuario(char* especialidadDestino);
private:
    ArchivoEspecialidad _repoEspecialidad;
};
