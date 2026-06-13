#include <iostream>
#include "Hora.h"

using namespace std;

Hora::Hora(){
    _hora = 0;
    _minuto = 0;
}

Hora::Hora(int hora, int minuto){
    _hora = hora;
    _minuto = minuto;
}

void Hora::setHora(int hora){
    _hora = hora;
}

void Hora::setMinuto(int minuto){
    _minuto = minuto;
}

int Hora::getHora(){
    return _hora;
}

int Hora::getMinuto(){
    return _minuto;
}

bool Hora::validarHora(){

    if(_hora < 0 || _hora > 23)
        return false;

    if(_minuto < 0 || _minuto > 59)
        return false;

    return true;
}

void Hora::cargar(){

    cout << "Hora: ";
    cin >> _hora;

    cout << "Minutos: ";
    cin >> _minuto;
}

void Hora::mostrar(){

    if(_hora < 10) cout << "0";

    cout << _hora << ":";

    if(_minuto < 10) cout << "0";

    cout << _minuto;
}
