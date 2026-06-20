#pragma once

#include "../persistencia/ArchivoPaciente.h"

class ManagerPaciente
{
private:
    ArchivoPaciente _repoPaciente;

public:
    void cargarPaciente(); //implementar luego alta logica y comprobar si el paciente ya esta cargado
    void listarPacientes();
    void modificarPaciente();
    void eliminarPaciente();


//Listados
    void listadoOrdenadoPorApellido();
    void listadoOrdenadoPorObraSocial();
    void listadoOrdenadoPorEdad();

//Consultas

    void consultarPacientePorDni();
    void consultarPacientePorAfiliado();
};
