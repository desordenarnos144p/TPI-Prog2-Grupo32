#pragma once
#include "Persona.h"
class Medico : public Persona
{
public:
    Medico();
    Medico(const char* dni, const char* nombre,
    const char* apellido, const char* telefono, bool estado,
    int idMedico, const char* matricula, int idEspecialidad);

    void setIdMedico(int idMedico);
    int getIdMedico();

    void setMatricula(const char* matricula);
    const char* getMatricula();

    void setIdEspecialidad(int idEspecialidad);
    int getIdEspecialidad();

    void cargar(const char* matricula = 0, int idMedico = 0);
    void mostrar();


    bool validarMatricula(const char* matricula);
private:
    int _idMedico;
    int _idEspecialidad;
    char _matricula[50];
};
