#include <iostream>
#include <cstring>
#include "ArchivoPaciente.h"

//CONSTRUCTOR.
    ArchivoPaciente::ArchivoPaciente(const char* nombreArchivo){
        strcpy(_nombreArchivo, nombreArchivo);
    }

//GETTERS.
    int ArchivoPaciente::getNuevoId(){
        return getCantidadRegistros() + 1;
    }

    int ArchivoPaciente::getCantidadRegistros(){
        FILE* pFile = fopen(_nombreArchivo, "rb");
        if(pFile == nullptr){
            return 0;
        }
        fseek(pFile, 0, SEEK_END);
        int cantidad = ftell(pFile) / sizeof(Paciente);
        fclose(pFile);
        return cantidad;
    }

//METODOS.
    bool ArchivoPaciente::guardar(Paciente reg){
        FILE* pFile = fopen(_nombreArchivo, "ab");
        if(pFile == nullptr){
            return false;
        }
        bool escribio = fwrite(&reg, sizeof(Paciente), 1, pFile);
        fclose(pFile);
        return escribio;
    }

    Paciente ArchivoPaciente::leer(int pos){
        Paciente reg;
        FILE* pFile = fopen(_nombreArchivo, "rb");
        if(pFile == nullptr){
            return reg;
        }
        fseek(pFile, sizeof(Paciente) * pos, SEEK_SET);
        fread(&reg, sizeof(Paciente), 1, pFile);
        fclose(pFile);
        return reg;
    }

    //AGREGAR: int buscarPosicion(int id);

    bool ArchivoPaciente::modificar(Paciente reg, int pos){
        FILE* pFile = fopen(_nombreArchivo, "rb+");
        if(pFile == nullptr){
            return false;
        }
        fseek(pFile, sizeof(Paciente) * pos, SEEK_SET);
        bool escribio = fwrite(&reg, sizeof(Paciente), 1, pFile);
        fclose(pFile);
        return escribio;
    }

    //AGREGAR: bool bajaLogica(int posicion);