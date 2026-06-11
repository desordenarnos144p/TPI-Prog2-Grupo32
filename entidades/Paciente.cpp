#include "Paciente.h"
#include <cstring>
#include <iostream>

using namespace std;

Paciente::Paciente(){

    _idPaciente = 0;
    _idObraSocial = 0;

    strcpy(_nroAfiliado, "SIN AFILIADO");
    strcpy(_antecedentes, "SIN ANTECEDENTES");
}
void Paciente::setIdPaciente(int idPaciente){
    _idPaciente = idPaciente;
}

int Paciente::getIdPaciente(){
    return _idPaciente;
}
void Paciente::setIdObraSocial(int idObraSocial){
    _idObraSocial = idObraSocial;
}

int Paciente::getIdObraSocial(){
    return _idObraSocial;
}
void Paciente::setNroAfiliado(const char* nroAfiliado){
    strcpy(_nroAfiliado, nroAfiliado);
}

const char* Paciente::getNroAfiliado(){
    return _nroAfiliado;
}
void Paciente::setAntecedentes(const char* antecedentes){
    strcpy(_antecedentes, antecedentes);
}

const char* Paciente::getAntecedentes(){
    return _antecedentes;
}
void Paciente::setFechaNacimiento(Fecha fechaNacimiento){
    _fechaNacimiento = fechaNacimiento;
}

Fecha Paciente::getFechaNacimiento(){
    return _fechaNacimiento;
}
void Paciente::cargar()
{
    cout << "Cargar paciente" << endl;
}

void Paciente::mostrar()
{
    cout << "ID Paciente: " << _idPaciente << endl;
}
