#include "AgendaMedico.h"
#include <iostream>

using namespace std;

AgendaMedico::AgendaMedico(){

    _idAgenda = 0;
    _idMedico = 0;

    _disponible = true;
    _estado = true;
}

AgendaMedico::AgendaMedico(
    int idAgenda,
    int idMedico,
    Fecha fecha,
    Hora hora,
    bool disponible,
    bool estado
){

    _idAgenda = idAgenda;
    _idMedico = idMedico;

    _fecha = fecha;
    _hora = hora;

    _disponible = disponible;
    _estado = estado;
}

void AgendaMedico::setIdAgenda(int idAgenda){
    _idAgenda = idAgenda;
}

int AgendaMedico::getIdAgenda(){
    return _idAgenda;
}

void AgendaMedico::setIdMedico(int idMedico){
    _idMedico = idMedico;
}

int AgendaMedico::getIdMedico(){
    return _idMedico;
}

void AgendaMedico::setFecha(Fecha fecha){
    _fecha = fecha;
}

Fecha AgendaMedico::getFecha(){
    return _fecha;
}

void AgendaMedico::setHora(Hora hora){
    _hora = hora;
}

Hora AgendaMedico::getHora(){
    return _hora;
}

void AgendaMedico::setDisponible(bool disponible){
    _disponible = disponible;
}

bool AgendaMedico::getDisponible(){
    return _disponible;
}

void AgendaMedico::setEstado(bool estado){
    _estado = estado;
}

bool AgendaMedico::getEstado(){
    return _estado;
}

void AgendaMedico::cargar(){

    cout << "ID Medico: ";
    cin >> _idMedico;

    cout << endl;

    cout << "Fecha:" << endl;
    _fecha.cargar();

    cout << endl;

    cout << "Hora:" << endl;
    _hora.cargar();

    _disponible = true;
    _estado = true;
}

void AgendaMedico::mostrar(){

    cout << "ID Agenda: " << _idAgenda << endl;
    cout << "ID Medico: " << _idMedico << endl;

    cout << "Fecha: ";
    _fecha.mostrar();

    cout << endl;

    cout << "Hora: ";
    _hora.mostrar();

    cout << endl;

    cout << "Disponible: "
         << (_disponible ? "SI" : "NO")
         << endl;

    cout << "Estado: "
         << (_estado ? "ACTIVO" : "INACTIVO")
         << endl;
}
