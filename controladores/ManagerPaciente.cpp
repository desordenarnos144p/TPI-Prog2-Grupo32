#include "ManagerPaciente.h"
#include <iostream>
#include <cstring>

using namespace std;

void ManagerPaciente::cargarPaciente()
{

    Paciente reg;

    reg.cargar();

    reg.setIdPaciente(
        _repoPaciente.getNuevoId()
    );

    if(_repoPaciente.guardar(reg))
    {
        cout << "PACIENTE GUARDADO CORRECTAMENTE" << endl;
    }
    else
    {
        cout << "ERROR AL GUARDAR PACIENTE" << endl;
    }
}

void ManagerPaciente::listarPacientes()
{

    int cantidad = _repoPaciente.getCantidadRegistros();

    for(int i=0; i<cantidad; i++)
    {

        Paciente reg = _repoPaciente.leer(i);

        if(reg.getEstado())
        {
            reg.mostrar();
            cout << endl;
        }
    }
}

void ManagerPaciente::modificarPaciente()
{

    cout << "MODIFICAR PACIENTE" << endl;

    // implementar después
}

void ManagerPaciente::eliminarPaciente()
{

    cout << "ELIMINAR PACIENTE" << endl;

    // implementar después baja lo0gica
}

//listatar por apellido

void ManagerPaciente::listadoOrdenadoPorApellido()
{

    int cantidad = _repoPaciente.getCantidadRegistros();

    Paciente vec[1000];

    int j = 0;

    for(int i=0; i<cantidad; i++)
    {

        Paciente reg = _repoPaciente.leer(i);

        if(reg.getEstado())
        {

            vec[j] = reg;
            j++;
        }
    }

    for(int i=0; i<j-1; i++)
    {

        for(int k=i+1; k<j; k++)
        {

            if(strcmp(vec[i].getApellido(), vec[k].getApellido()) > 0)\
            {
                Paciente aux;

                aux = vec[i];
                vec[i] = vec[k];
                vec[k] = aux;
            }
        }
    }

    cout << "PACIENTES ORDENADOS POR APELLIDO" << endl;

    for(int i=0; i<j; i++)
    {

        vec[i].mostrar();
        cout << endl;
    }
}
