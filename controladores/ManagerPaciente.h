#pragma once

#include "../persistencia/ArchivoPaciente.h"

class ManagerPaciente{
private:
    ArchivoPaciente _repoPaciente;

public:
    void cargarPaciente();
    void listarPacientes();
    void modificarPaciente();
    void eliminarPaciente();
};
