#include <cstdio>
#include <cstring>
#include "ArchivoMedico.h"
#include "../controladores/ManagerMedico.h"

//CONSTRUCTOR.
    ArchivoMedico::ArchivoMedico(const char* nombreArchivo){
        strcpy(_nombreArchivo, nombreArchivo);
    }

//GETTERS.
    int ArchivoMedico::getNuevoId(){
        return getCantidadRegistros() + 1;
    }

    int ArchivoMedico::getCantidadRegistros(){
        FILE *p = fopen(_nombreArchivo, "rb");
        if(p == nullptr){
            return 0;
        }
        fseek(p, 0, SEEK_END);
        int tamTotal = ftell(p) / sizeof(Medico);
        fclose(p);
        return tamTotal;
    }

//METODOS.
    bool ArchivoMedico::guardar(const Medico reg){
        FILE *p = fopen(_nombreArchivo, "ab");
        if(p == nullptr){
            return false;
        }
        int cant = fwrite(&reg, sizeof(Medico), 1, p);
        fclose(p);
        return cant;
    }

    Medico ArchivoMedico::leer(int pos){
        Medico reg;
        FILE *p = fopen(_nombreArchivo, "rb");
        if(p == nullptr){
            return reg;
        }
        fseek(p, pos * sizeof(Medico), SEEK_SET);
        int leer = fread(&reg, sizeof(Medico), 1, p);
        fclose(p);
        return reg;
    }

    //AGREGAR: int buscarPosicion(int id);

    bool ArchivoMedico::modificar(const Medico &reg, int pos){
        FILE *p = fopen(_nombreArchivo, "rb+");
        if(p == nullptr){
            return false;
        }
        fseek(p, pos * sizeof(Medico), SEEK_SET);
        bool escribio = fwrite(&reg, sizeof(Medico), 1, p);
        fclose(p);
        return escribio;
    }

    //AGREGAR: bool bajaLogica(int posicion);

    int ArchivoMedico::buscarPosicion(int id){
        int cantidad = getCantidadRegistros();
        for(int i = 0; i < cantidad; i++){
            Medico reg = leer(i);
            if(reg.getIdMedico() == id && reg.getEstado() == true){
                return i;
            }
        }
        return -1;
    }
    //lo que agregue en el .h
    int ArchivoMedico::buscarMedico(const char* matricula)
{
    Medico reg;
    int cant = getCantidadRegistros();

    for(int i=0; i<cant; i++)
    {
        reg = leer(i);

        if(strcmp(reg.getMatricula(), matricula) == 0)
        {
            return i;
        }
    }

    return -1;
}
