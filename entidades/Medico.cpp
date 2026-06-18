#include <iostream>
#include "Medico.h"
#include <cstring>

using namespace std;

Medico::Medico()
  : Persona(), _idMedico(0), _idEspecialidad(0)
{
  strcpy(_matricula, "0");
}

Medico::Medico(const char* dni, const char* nombre, const char* apellido, const char* telefono, bool estado, int idMedico, const char* matricula, int idEspecialidad)
  : Persona(dni, nombre, apellido, telefono, estado)
{
  setIdMedico(idMedico);
  setMatricula(matricula);
  setIdEspecialidad(idEspecialidad);
}

void Medico::setIdMedico(int idMedico)
{
  if(idMedico > 0)
  {
    _idMedico = idMedico;
  }
  else
  {
    _idMedico = 0;
  }
}

int Medico::getIdMedico()
{
  return _idMedico;
}

void Medico::setMatricula(const char* matricula)
{
  int largo = strlen(matricula);

  if(largo < 0 || largo > 10)
  {
    strcpy(_matricula, "0");
    return;
  }

  for(int i=0; i<largo; i++)
  {
    if(matricula[i] < '0' || matricula[i] > '9')
    {
      strcpy(_matricula, "0");
      return;
    }
  }

  strcpy(_matricula, matricula);
}

const char* Medico::getMatricula()
{
  return _matricula;
}

void Medico::setIdEspecialidad(int idEspecialidad)
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

int Medico::getIdEspecialidad()
{
  return _idEspecialidad;
}

void Medico::cargar(const char* matricula, int idMedico)
{
  int auxIdMedico, auxIdEspecialidad;
  char auxMatricula[50];

  Persona::cargar();

  if(idMedico != 0)
  {
    setIdMedico(idMedico);
  }
  else
  {
    cout << "ID Medico: ";
    cin >> auxIdMedico;
    setIdMedico(auxIdMedico);
  }

  if(matricula != 0)
  {
    setMatricula(matricula);
  }
  else
  {
    cout << "Matricula Medico: ";
    cin >> auxMatricula;
    setMatricula(auxMatricula);
  }

  cout << "ID Especialidad (1 - 10): ";
  cin >> auxIdEspecialidad;
  setIdEspecialidad(auxIdEspecialidad);

  setEstado(true);
}

void Medico::mostrar()
{
  cout << endl;
  Persona::mostrar();
  cout << "- DATOS MEDICOS -" << endl;
  cout << "ID Medico: " << _idMedico << endl;
  cout << "Matricula: " << _matricula << endl;
  cout << "ID Especialidad: " << _idEspecialidad << endl;
}

bool Medico::validarMatricula(const char* matricula)
{
  while(strcmp(matricula