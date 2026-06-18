#include <iostream>
#include "Especialidad.h"
#include <cstring>
using namespace std;

Especialidad::Especialidad()
    : _idEspecialidad(0), _estado(false)
{
    strcpy(_nombre, "Sin especialidad");
}

Especialidad::Especialidad(int idEspecialidad, const char* nombre, bool estado)
{
    setIdEspecialidad(idEspecialidad);
    setNombre(nombre);
    setEstado(estado);
}

void Especialidad::setIdEspecialidad(int idEspecialidad)
{
    if(idEspecialidad > 0)
    {
        _idEspecialidad = idEspecialidad;
    }
    else
    {
        _idEspecialidad = 0;
    }
}

int Especialidad::getIdEspecialidad()
{
    return _idEspecialidad;
}

void Especialidad::setNombre(const char* nombre)
{
    int largo = strlen(nombre);
    if(largo <= 0 || largo > 49)
    {
        strcpy(_nombre, "0");
        return;
    }
    strcpy(_nombre, nombre);
}

const char* Especialidad::getNombre()
{
    return _nombre;
}

void Especialidad::setEstado(bool estado)
{
    _estado = estado;
}

bool Especialidad::getEstado()
{
    return _estado;
}

void Especialidad::cargar(const char* especialidad, int id)
{
    int auxId;
    char auxNombre[50];

    cout << "ID Especialidad: ";
    cin >> auxId;
    setIdEspecialidad(auxId);

    cout << "Nombre Especialidad: ";
    cin >> auxNombre;
    setNombre(auxNombre);

    setEstado(true);
}

void Especialidad::mostrar()
{
    cout << endl;
    cout << "- DATOS ESPECIALIDAD MEDICA -" << endl;
    cout << "ID Especialidad: " << _idEspecialidad << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
}


bool Especialidad::validarEspecialidad(const char* especialidad){
    int largo = strlen(especialidad);

    if(largo <= 0)
    {
        return false;
    }
    return true;
}

