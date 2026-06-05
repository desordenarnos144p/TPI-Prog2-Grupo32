#include <iostream>
#include "Persona.h"
#include <cstring>
using namespace std;

Persona::Persona()
{
    std::strcpy(_dni, "0");
    std::strcpy(_nombre, "Sin nombre");
    std::strcpy(_apellido, "Sin apellido");
    std::strcpy(_telefono, "0");
    _estado = false;
}

Persona::Persona(const char* dni, const char* nombre, const char* apellido, const char* telefono, bool estado)
{
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEstado(estado);
}

void Persona::setDni(const char* dni)
{
    int largo = strlen(dni);

    if(largo < 6 || largo > 15) {
        strcpy(_dni, "0");
        return;
    }


    for(int i=0; i< largo; i++)
    {
        if(dni[i] < '0' || dni[i] > '9')
        {
            strcpy(_dni, "0");
            return;
        }
    }

    strcpy(_dni, dni);
}
const char* Persona::getDni()
{
    return _dni;
}

void Persona::setNombre(const char* nombre)
{
    int largo = strlen(nombre);

    for(int i=0; i<largo; i++){
        if(nombre[i] >= '0' && nombre[i] <= '9'){
            strcpy(_nombre, "Sin nombre");
            return;
        }
    }

    strcpy(_nombre, nombre);
}
const char* Persona::getNombre()
{
    return _nombre;
}

void Persona::setApellido(const char* apellido)
{
    int largo = strlen(apellido);

    for(int i=0; i<largo; i++){
        if(apellido[i] >= '0' && apellido[i] <= '9'){
            strcpy(_apellido, "Sin apellido");
            return;
        }
    }

    strcpy(_apellido, apellido);
}
const char* Persona::getApellido()
{
    return _apellido;
}

void Persona::setTelefono(const char* telefono)
{
    int largo = strlen(telefono);

    if(largo < 6 || largo > 15) {
        strcpy(_telefono, "0");
        return;
    }

    for(int i=0; i<largo; i++)
    {
        if(telefono[i] < '0' || telefono[i] > '9')
        {
            strcpy(_telefono, "0");
            return;
        }
    }

    strcpy(_telefono, telefono);
}
const char* Persona::getTelefono()
{
    return _telefono;
}

void Persona::setEstado(bool estado)
{
    _estado = estado;
}
bool Persona::getEstado()
{
    return _estado;
}



void Persona::cargar(){
    char auxDni[20];
    char auxNombre[50];
    char auxApellido[50];
    char auxTelefono[20];
    cout << "-- CARGAR DATOS DE LA PERSONA --" << endl;

    cout << "Ingrese DNI: ";
    cin.getline(auxDni, 20);
    setDni(auxDni);

    cout << "Ingrese nombre: ";
    cin.getline(auxNombre, 50);
    setNombre(auxNombre);

    cout << "Ingrese apellido: ";
    cin.getline(auxApellido, 50);
    setApellido(auxApellido);

    cout << "Ingrese telefono: ";
    cin.getline(auxTelefono, 20);
    setTelefono(auxTelefono);

    setEstado(true);
}
void Persona::mostrar(){
    cout << "----- DATOS DE LA PERSONA -----" << endl;
    cout << "DNI: " << _dni << endl;
    cout << "Nombre completo: " << _nombre << " "<< _apellido << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
    cout << "-------------------------" << endl;
}
