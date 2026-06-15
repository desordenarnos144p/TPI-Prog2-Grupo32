#include "ManagerPaciente.h"
#include <iostream>

using namespace std;

void ManagerPaciente::cargarPaciente(){

    Paciente reg;

    reg.cargar();

    reg.setIdPaciente(_repoPaciente.getNuevoId());

    if(_repoPaciente.guardar(reg)){
        cout << "PACIENTE GUARDADO CORRECTAMENTE..." << endl;
    }
    else{
        cout << "ERROR AL GUARDAR PACIENTE..." << endl;
    }
}

void ManagerPaciente::listarPacientes(){

    int cantidad = _repoPaciente.getCantidadRegistros();

    for(int i=0; i<cantidad; i++){

        Paciente reg = _repoPaciente.leer(i);

        if(reg.getEstado()){
            reg.mostrar();
            cout << endl;
        }
    }
}

void ManagerPaciente::modificarPaciente(){

    cout << "MODIFICAR PACIENTE" << endl;

    // implementar despu�s
}

void ManagerPaciente::eliminarPaciente(){

    cout << "ELIMINAR PACIENTE" << endl;

    // implementar despu�s
}
