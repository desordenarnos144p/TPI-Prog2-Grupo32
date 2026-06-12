#include <iostream>
#include <cstring>
#include "ObraSocial.h"

using namespace std;

ObraSocial::ObraSocial()
{
   _idObraSocial =0;
    std::strcpy(_nombre, "Sin nombre");
    _estado = false;
}

ObraSocial::ObraSocial(int idObraSocial, const char* nombre, bool estado)
{
    setIdObraSocial(idObraSocial);
    setNombre(nombre);
    setEstado(estado);

}

    void ObraSocial::setIdObraSocial(int idObraSocial){
        if (idObraSocial > 0) {
        _idObraSocial = idObraSocial;
        }
    }
    int ObraSocial::getIdObraSocial(){
        return _idObraSocial;
    }

    void ObraSocial::setNombre(const char* nombre){
        if(strlen(nombre) < 30){
        strcpy(_nombre, nombre);
            }
    }
    const char* ObraSocial::getNombre(){
        return _nombre;
    }

    void ObraSocial::setEstado(bool estado){
        _estado = estado;
    }
    bool ObraSocial::getEstado(){
         return _estado;
    }

    void ObraSocial::ingresarDatos(){

    char auxNombre[30];
    int auxIdObraSocial;

    cout << "-- CARGAR DATOS DE LA OBRA SOCIAL --" << endl;

    cout << "Ingrese ID de la Obra Social: ";
    cin >> auxIdObraSocial;
    cin.ignore();
    setIdObraSocial(auxIdObraSocial);

    cout << "Ingrese nombre: ";
    cin.getline(auxNombre, 30);
    setNombre(auxNombre);

    setEstado(true);
}
    void ObraSocial::mostrar(){
         cout << " --------------------------------------------------" << endl;
    cout << "DATOS DE Obra Social:" << endl;
    cout << "ID Obra Social: " << _idObraSocial<< endl;
    cout << "Nombre de la Obra Social: " << _nombre << endl;
    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
    cout << " --------------------------------------------------" << endl;
    }
