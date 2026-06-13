#include <iostream>
#include "Fecha.h"

using namespace std;

Fecha::Fecha(){
    _dia = 1;
    _mes = 1;
    _anio = 2000;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

bool Fecha::validarFecha(){

    if(_anio < 1900) return false;

    if(_mes < 1 || _mes > 12) return false;

    if(_dia < 1 || _dia > 31) return false;

    return true;
}

void Fecha::cargar(){

    cout << "Dia: ";
    cin >> _dia;

    cout << "Mes: ";
    cin >> _mes;

    cout << "Anio: ";
    cin >> _anio;
}

void Fecha::mostrar(){

    cout << _dia << "/"
         << _mes << "/"
         << _anio;
}
