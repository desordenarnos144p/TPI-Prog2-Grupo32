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

Paciente::Paciente(
    int idPaciente,
    int idObraSocial,
    const char* nroAfiliado,
    const char* antecedentes,
    Fecha fechaNacimiento,
    const char* dni,
    const char* nombre,
    const char* apellido,
    const char* telefono,
    bool estado
) : Persona(dni, nombre, apellido, telefono, estado){
    _idPaciente = idPaciente;
    _idObraSocial = idObraSocial;
    strcpy(_nroAfiliado, nroAfiliado);
    strcpy(_antecedentes, antecedentes);
    _fechaNacimiento = fechaNacimiento;
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

void Paciente::cargar(){
    Persona::cargar();
    cout << "ID Obra Social: ";
    cin >> _idObraSocial;
    cin.ignore();
    cout << "Numero Afiliado: ";
    cin.getline(_nroAfiliado,30);
    cout << "Antecedentes: ";
    cin.getline(_antecedentes,300);
    cout << "Fecha de nacimiento:" << endl;
    _fechaNacimiento.cargar();
}

void Paciente::mostrar(){
    Persona::mostrar();
    cout << "ID Paciente: " << _idPaciente << endl;
    cout << "ID Obra Social: " << _idObraSocial << endl;
    cout << "Numero Afiliado: " << _nroAfiliado << endl;
    cout << "Antecedentes: " << _antecedentes << endl;
    cout << "Fecha Nacimiento: ";
    _fechaNacimiento.mostrar();
    cout << endl;
}
