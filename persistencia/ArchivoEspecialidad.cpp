#include "EspecialidadArchivo.h"
#include <stdio.h>
#include <cstring>

ArchivoEspecialidad::ArchivoEspecialidad(const char* nombreArchivo)
{
    std::strcpy(_nombreArchivo, nombreArchivo);
}

bool ArchivoEspecialidad::guardar(Especialidad reg)
{
    FILE *p = fopen(_nombreArchivo, "ab");
    if(p == nullptr)
    {
        return false;
    }
    int cant = fwrite(&reg, sizeof(Especialidad), 1, p);
    fclose(p);
    return cant;
}

Especialidad ArchivoEspecialidad::leer(int pos)
{
    Especialidad reg;
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p == nullptr)
    {
        return reg;
    }
    fseek(p, pos * sizeof(Especialidad), SEEK_SET);
    int leer = fread(&reg, sizeof(Especialidad), 1, p);
    fclose(p);
    return reg;
}

int ArchivoEspecialidad::getCantidadRegistros()
{
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p == nullptr)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int tamTotal = ftell(p) / sizeof(Especialidad);
    fclose(p);
    return tamTotal;
}

bool ArchivoEspecialidad::modificar(const Especialidad &reg, int pos)
{
    FILE *p = fopen(_nombreArchivo, "rb+");
    if(p == nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof(Especialidad), SEEK_SET);
    bool escribio = fwrite(&reg, sizeof(Especialidad), 1, p);
    fclose(p);
    return escribio;
}

int ArchivoEspecialidad::getNuevoId()
{
    return getCantidadRegistros() + 1;
}



int ArchivoEspecialidad::buscarEspecialidad(const char* especialidad){
    Especialidad reg;
    int cant = getCantidadRegistros();

    for(int i = 0; i < cant; i++)
    {
        reg = leer(i);
        if(reg.getEstado() == true && strcmp(reg.getNombre(), especialidad) == 0)
        {
            return i;
        }
    }
return -1;
}

