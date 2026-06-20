#include "ManagerPaciente.h"
#include <iostream>
#include <cstring>

using namespace std;




void ManagerPaciente::cargarPaciente() {
    Paciente reg;
    int idOS;

    cout << "ID Obra Social: ";
    cin >> idOS;

    if (_archivoObraSocial.buscarPorID(idOS) == -1) {
        cout << "La obra social no existe." << endl;
        return;
    }

    reg.setIdObraSocial(idOS);

    // seguir cargando el resto de los datos...

    _archivoPaciente.guardar(reg);
}

void ManagerPaciente::modificarPaciente()
{
    int idPaciente;

    cout << "MODIFICAR PACIENTE" << endl;
    cout << "ID Paciente: ";
    cin >> idPaciente;

    int pos = _repoPaciente.buscarPorId(idPaciente);

    if(pos == -1)
    {
        cout << "EL PACIENTE NO EXISTE" << endl;
        return;
    }

    Paciente reg = _repoPaciente.leer(pos);

    cout << endl;
    cout << "DATOS ACTUALES:" << endl;
    reg.mostrar();

    cout << endl;
    cout << "INGRESE LOS NUEVOS DATOS:" << endl;

    cin.ignore();

    reg.cargar();

    // Mantener el mismo ID
    reg.setIdPaciente(idPaciente);

    if(_repoPaciente.modificar(reg, pos))
    {
        cout << "PACIENTE MODIFICADO CORRECTAMENTE" << endl;
    }
    else
    {
        cout << "ERROR AL MODIFICAR PACIENTE" << endl;
    }
}

//baja logica
void ManagerPaciente::eliminarPaciente()
{
    int idPaciente;

    cout << "ELIMINAR PACIENTE" << endl;
    cout << "ID Paciente: ";
    cin >> idPaciente;

    int pos = _repoPaciente.buscarPorId(idPaciente);

    if(pos == -1)
    {
        cout << "EL PACIENTE NO EXISTE" << endl;
        return;
    }

    Paciente reg;

    reg = _repoPaciente.leer(pos);
    //evito borrar dos veces
    if(!reg.getEstado())
    {
        cout << "EL PACIENTE YA ESTA DADO DE BAJA" << endl;
        return;
    }

    reg.setEstado(false);

    if(_repoPaciente.modificar(reg, pos))
    {
        cout << "PACIENTE DADO DE BAJA CORRECTAMENTE" << endl;
    }
    else
    {
        cout << "ERROR AL DAR DE BAJA EL PACIENTE" << endl;
    }
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

            if(strcmp(vec[i].getApellido(), vec[k].getApellido()) > 0)
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

//Listado ordenado por Obra social

void ManagerPaciente::listadoOrdenadoPorObraSocial()
{
    int cantidad = _repoPaciente.getCantidadRegistros();

    Paciente vec[1000];

    int j = 0;

    // Cargar pacientes activos en el vector
    for(int i = 0; i < cantidad; i++)
    {
        Paciente reg = _repoPaciente.leer(i);

        if(reg.getEstado())
        {
            vec[j] = reg;
            j++;
        }
    }

    // Ordenar por ID de Obra Social
    for(int i = 0; i < j - 1; i++)
    {
        for(int k = i + 1; k < j; k++)
        {
            if(vec[i].getIdObraSocial() > vec[k].getIdObraSocial())
            {
                Paciente aux;

                aux = vec[i];
                vec[i] = vec[k];
                vec[k] = aux;
            }
        }
    }

    cout << "PACIENTES ORDENADOS POR OBRA SOCIAL" << endl;

    for(int i = 0; i < j; i++)
    {
        vec[i].mostrar();
        cout << endl;
    }
}

//Listado por Edad

void ManagerPaciente::listadoOrdenadoPorEdad()
{
    int cantidad = _repoPaciente.getCantidadRegistros();

    Paciente vec[1000];

    int j = 0;

    // Cargar pacientes activos
    for(int i = 0; i < cantidad; i++)
    {
        Paciente reg = _repoPaciente.leer(i);

        if(reg.getEstado())
        {
            vec[j] = reg;
            j++;
        }
    }

    // Ordenar por fecha de nacimiento

    for(int i = 0; i < j - 1; i++)
    {
        for(int k = i + 1; k < j; k++)
        {
            Fecha fecha1 = vec[i].getFechaNacimiento();
            Fecha fecha2 = vec[k].getFechaNacimiento();

            if(fecha1.getAnio() > fecha2.getAnio() ||
                    (fecha1.getAnio() == fecha2.getAnio() && fecha1.getMes() > fecha2.getMes()) ||
                    (fecha1.getAnio() == fecha2.getAnio() &&
                     fecha1.getMes() == fecha2.getMes() &&
                     fecha1.getDia() > fecha2.getDia()))
            {
                Paciente aux;

                aux = vec[i];
                vec[i] = vec[k];
                vec[k] = aux;
            }
        }
    } // <- estas dos llaves faltaban

    cout << "PACIENTES ORDENADOS POR EDAD" << endl;

    for(int i = 0; i < j; i++)
    {
        vec[i].mostrar();
        cout << endl;
    }

}

//Consultas

void ManagerPaciente::consultarPacientePorDni()
{
    char dni[20];

    cout << "DNI: ";
    cin.ignore();
    cin.getline(dni, 20);

    int pos = _repoPaciente.buscarPorDni(dni);

    if(pos == -1)
    {
        cout << "PACIENTE NO ENCONTRADO" << endl;
        return;
    }

    Paciente reg = _repoPaciente.leer(pos);

    reg.mostrar();
}

void ManagerPaciente::consultarPacientePorAfiliado()
{
    char afiliado[30];

    cout << "Numero de Afiliado: ";
    cin.ignore();
    cin.getline(afiliado, 30);

    int pos = _repoPaciente.buscarPorNroAfiliado(afiliado);

    if(pos == -1)
    {
        cout << "PACIENTE NO ENCONTRADO" << endl;
        return;
    }

    Paciente reg = _repoPaciente.leer(pos);

    reg.mostrar();
}
