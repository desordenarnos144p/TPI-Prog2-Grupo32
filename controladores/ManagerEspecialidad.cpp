#include <iostream>
#include <cstring>
#include "ManagerEspecialidad.h"
#include "Especialidad.h"
using namespace std;

ManagerEspecialidad::ManagerEspecialidad()
    : _repoEspecialidad()
{
}

void ManagerEspecialidad::cargarEspecialidad()
{
    Especialidad esp;
    char auxNombreEspecialidad[50];
    int id = _repoEspecialidad.getNuevoId();
    cout << "-- INGRESO DE ESPECIALIDAD MEDICA --" << endl;
    cout << "ID Especialidad #" << id << endl;

    pedirEspecialiadNuevaAlUsuario(auxNombreEspecialidad);

    int pos = _repoEspecialidad.buscarEspecialidad(auxNombreEspecialidad);

    if(pos >= 0)
    {
        cout << "LA ESPECIALIDAD YA EXISTE EN EL SISTEMA" << endl;
        return;
    }
    else
    {
        esp.cargar(auxNombreEspecialidad, id);

        if(_repoEspecialidad.guardar(esp))
        {
            cout << "Especialidad guardada" << endl;
        }
        else
        {
            cout << "Error, especialidad no guardada" << endl;
        }
    }
}

void ManagerEspecialidad::eliminarEspecialidad()
{
    Especialidad esp;
    char auxNombreEspecialidad[50];

    pedirEspecialiadNuevaAlUsuario(auxNombreEspecialidad);

    int pos = _repoEspecialidad.buscarEspecialidad(auxNombreEspecialidad);

    if(pos < 0)
    {
        cout << "ERROR... ESPECIALIDAD NO EXISTE EN EL SISTEMA" << endl;
        return;
    }
    else
    {
        esp = _repoEspecialidad.leer(pos);

        esp.setEstado(false);

        if(_repoEspecialidad.modificar(esp, pos))
        {
            cout << "Especialidad eliminada" << endl;
        }
        else
        {
            cout << "Especialidad no se pudo eliminar" << endl;
        }
    }
}

void ManagerEspecialidad::listar()
{
    Especialidad esp;
    int cant = _repoEspecialidad.getCantidadRegistros();

    if(cant > 0)
    {
        cout << "-- LISTADO DE ESPECIALIDADES --" << endl;
        for(int i = 0; i < cant; i++)
        {
            esp = _repoEspecialidad.leer(i);
            if(esp.getEstado() == true)
            {
                esp.mostrar();
                cout << endl;
            }
        }
    }
    else
    {
        cout << "El archivo no tiene registros" << endl;
    }
}

void ManagerEspecialidad::modificarEspecialidad()
{
    Especialidad esp;
    char auxNombreEspecialidad[50];

    pedirEspecialiadNuevaAlUsuario(auxNombreEspecialidad);

    int pos = _repoEspecialidad.buscarEspecialidad(auxNombreEspecialidad);

    if(pos < 0)
    {
        cout << "ERROR... ESPECIALIDAD NO EXISTE EN EL SISTEMA O ESTA DADA DE BAJA" << endl;
        return;
    }
    else
    {
        char auxNuevoNombreEspecialidad[50];
        pedirEspecialiadNuevaAlUsuario(auxNuevoNombreEspecialidad);

        esp = _repoEspecialidad.leer(pos);

        esp.setNombre(auxNuevoNombreEspecialidad);

        if(_repoEspecialidad.modificar(esp, pos))
        {
            cout << "Nombre modificado" << endl;
        }
        else
        {
            cout << "Nombre no se pudo modificar" << endl;
        }
    }
}



void ManagerEspecialidad::pedirEspecialiadNuevaAlUsuario(char *especialidadDestino)
{
    Especialidad esp;
    bool esValida = false;
do
    {
        cout << "Ingrese nombre de especialidad a cargar: ";
        cin >> especialidadDestino;

        esValida = esp.validarEspecialidad(especialidadDestino);
        if(!esValida)
        {
            cout << "Error.. Ingrese nuevamente la especialidad " << endl;
        }

    }
    while(!esValida);
}



void ManagerEspecialidad::listadoOrdenadoPorEspecialidad()
{
    //1) ME FIJO SI TENGO REGISTROS
    int cant = _repoEspecialidad.getCantidadRegistros();
    //2) SI EL REGISTRO NO TIENE NADA, ME VOY CON UN RETURN
    if(cant <= 0)
    {
        cout << "El archivo no tiene registros" << endl;
        return;
    }

    //3) SI TIENE REGISTROS PIDO MEMORIA DINAMICA PARA CANT --- > CANT PUEDE SER 5, 20, 50 O 500 REGISTROS
    Especialidad *esp = new Especialidad[cant];

    //4) LEO LO QUE HAY EN CANT Y LO TRAIGO A MEMORIA
    for(int i=0; i<cant; i++)
    {
        esp[i] = _repoEspecialidad.leer(i);
    }

    //5) HAGO LA COMPARACION DE LA PRIMER LETRA DE LA ESPECIALIDAD
    //ORDENADO ALFABETICAMENTE --- > SI DA MENOR A 0 ES PORQUE EL PRIMER NOMBRE VA PRIMERO
    //SE LLAMA METODO BURBUJA
    Especialidad aux;
    for(int i=0; i<cant - 1; i++)
        {
        for(int x= i+1; x<cant; x++)
            {
            if(strcmp(esp[i].getNombre(), esp[x].getNombre()) < 0)
                {
                    aux = esp[i]; //ME CREO UN VARIABLE AUX PARA GUARDAR PROVISORIAMENTE
                    esp[i] = esp[x];
                    esp[x] = aux;
                }
            }
        }

    //6) MOSTRAR
    for(int i=0; i<cant; i++)
    {
        if(esp[i].getEstado())
            {
                esp[i].mostrar();
        cout << "------------------"<< endl;
            }
    }
//7) CIERRE DE MEMORIA DINAMICA
delete[] esp;
}

