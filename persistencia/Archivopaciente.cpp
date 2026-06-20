#include "ArchivoPaciente.h"
#include <cstdio>
#include <cstring>

ArchivoPaciente::ArchivoPaciente(const char* nombreArchivo)
{
    strcpy(_nombreArchivo, nombreArchivo);
}

bool ArchivoPaciente::guardar(Paciente reg)
{

    FILE* pFile = fopen(_nombreArchivo, "ab");

    if(pFile == nullptr) return false;

    bool escribio = fwrite(&reg, sizeof(Paciente), 1, pFile);

    fclose(pFile);

    return escribio;
}

Paciente ArchivoPaciente::leer(int pos)
{

    Paciente reg;

    FILE* pFile = fopen(_nombreArchivo, "rb");

    if(pFile == nullptr) return reg;

    fseek(pFile, sizeof(Paciente) * pos, SEEK_SET);

    fread(&reg, sizeof(Paciente), 1, pFile);

    fclose(pFile);

    return reg;
}

bool ArchivoPaciente::modificar(Paciente reg, int pos)
{

    FILE* pFile = fopen(_nombreArchivo, "rb+");

    if(pFile == nullptr) return false;

    fseek(pFile, sizeof(Paciente) * pos, SEEK_SET);

    bool escribio = fwrite(&reg, sizeof(Paciente), 1, pFile);

    fclose(pFile);

    return escribio;
}

int ArchivoPaciente::getCantidadRegistros()
{

    FILE* pFile = fopen(_nombreArchivo, "rb");

    if(pFile == nullptr) return 0;

    fseek(pFile, 0, SEEK_END);

    int cantidad = ftell(pFile) / sizeof(Paciente);

    fclose(pFile);

    return cantidad;
}

int ArchivoPaciente::getNuevoId()
{

    return getCantidadRegistros() + 1;
}

int ArchivoPaciente::buscarPorId(int idPaciente)
{
    Paciente reg;
    int posicion = 0;

    FILE *pFile = fopen(_nombreArchivo, "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(Paciente), 1, pFile) == 1)
    {
        if(reg.getIdPaciente() == idPaciente)
        {
            fclose(pFile);
            return posicion;
        }

        posicion++;
    }

    fclose(pFile);

    return -1;
}

//buscar por DNI

int ArchivoPaciente::buscarPorDni(const char* dni)
{
    Paciente reg;
    int posicion = 0;

    FILE* pFile = fopen(_nombreArchivo, "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(Paciente), 1, pFile) == 1)
    {
        if(strcmp(reg.getDni(), dni) == 0)
        {
            fclose(pFile);
            return posicion;
        }

        posicion++;
    }

    fclose(pFile);

    return -1;
}

int ArchivoPaciente::buscarPorNroAfiliado(const char* nroAfiliado)
{
    Paciente reg;
    int posicion = 0;

    FILE* pFile = fopen(_nombreArchivo, "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(Paciente), 1, pFile) == 1)
    {
        if(strcmp(reg.getNroAfiliado(), nroAfiliado) == 0)
        {
            fclose(pFile);
            return posicion;
        }

        posicion++;
    }

    fclose(pFile);

    return -1;
}
