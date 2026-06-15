#include "MedicoArchivo.h"
#include <stdio.h>
#include <cstring>

MedicoArchivo::MedicoArchivo(const char* nombreArchivo)
{
    std::strcpy(_nombreArchivo, nombreArchivo);
}


bool MedicoArchivo::guardar(const Medico &reg)
{
    FILE *p = fopen(_nombreArchivo, "ab");
    if(p==nullptr)
    {
        return false;
    }

    int cant = fwrite(&reg, sizeof(Medico), 1, p);
    fclose(p);
    return cant;
}


Medico MedicoArchivo::leer(int pos)
{
    Medico reg;
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p==nullptr)
    {
        return reg;
    }

    fseek(p, pos * sizeof(Medico), SEEK_SET);
    int leer = fread(&reg, sizeof(Medico), 1, p);

    fclose(p);
    return reg;
}


int MedicoArchivo::getCantidadRegistros()
{
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p==nullptr)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int tamTotal = ftell(p) / sizeof(Medico);

    fclose(p);
    return tamTotal;
}



bool MedicoArchivo::modificar(const Medico &reg, int pos)
{
    FILE *p = fopen(_nombreArchivo, "rb+");
    if(p==nullptr)
    {
        return false;
    }

    fseek(p, pos * sizeof(Medico), SEEK_SET);
    bool escribio = fwrite(&reg, sizeof(Medico), 1, p);

    fclose(p);
    return escribio;
}


int MedicoArchivo::getNuevoId()
{
    return getCantidadRegistros() + 1;
}




int MedicoArchivo::buscarMedico(const char* matricula)
{
    Medico med;
    int cant = getCantidadRegistros();

    for(int i=0; i<cant; i++)
        med = leer(i);

    if(med.getEstado() == true && strcmp(med.getMatricula(), matricula) == 0)
    {
        return i;
    }
}
return -1;
}
