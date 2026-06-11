#pragma once

#include "Persona.h"
#include "auxiliares/Fecha.h"

class Paciente : public Persona{
private:
    int _idPaciente;
    int _idObraSocial;
    char _nroAfiliado[30];
    char _antecedentes[300];
    Fecha _fechaNacimiento;

public:

    Paciente();

    Paciente(
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
    );

    void setIdPaciente(int idPaciente);
    int getIdPaciente();

    void setIdObraSocial(int idObraSocial);
    int getIdObraSocial();

    void setNroAfiliado(const char* nroAfiliado);
    const char* getNroAfiliado();

    void setAntecedentes(const char* antecedentes);
    const char* getAntecedentes();

    void setFechaNacimiento(Fecha fechaNacimiento);
    Fecha getFechaNacimiento();

    void cargar();
    void mostrar();
};
