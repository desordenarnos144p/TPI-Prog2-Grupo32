#include <iostream>
#include "entidades/auxiliares/Fecha.h"
#include "entidades/auxiliares/Hora.h"
#include "controladores/ManagerPaciente.h"

using namespace std;

int main(){

    ManagerPaciente manager;

    manager.cargarPaciente();

    cout << "\n\nLISTADO DE PACIENTES\n" << endl;

    manager.listarPacientes();

    return 0;
}
