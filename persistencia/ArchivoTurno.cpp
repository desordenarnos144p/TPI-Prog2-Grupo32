#include <iostream>
#include <cstdio>
#include <cstring>
#include "ArchivoTurno.h"
#include "../entidades/Turno.h"
#include "../controladores/ManagerTurno.h"

using namespace std;

ArchivoTurno::ArchivoTurno(const char* nombreArchivo){ 
    strcpy(_nombreArchivo, "turnos.dat"); 
}

bool ArchivoTurno::guardar(Turno reg){
    FILE* p = fopen(_nombreArchivo, "ab");
    if(p == NULL){
    return false;
    }
    bool escribio = fwrite(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return escribio;
}

Turno ArchivoTurno::leer(int posicion){
    Turno reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if(p == NULL){
    return reg;
    }
  fseek(p, posicion * sizeof(Turno), SEEK_SET);
    fread(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return reg;
}

int ArchivoTurno::getCantidadRegistros(){
    FILE* p = fopen(_nombreArchivo, "rb");
    if(p == NULL){
    return 0;
    }
    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Turno);
}

int ArchivoTurno::buscarPosicion(int id){
    int cantidad = getCantidadRegistros();
    for(int i = 0; i < cantidad; i++){
    Turno reg = leer(i);
    if(reg.getIdTurno() == id && reg.getEstado() == true){
        return i;
    }
    }
    return -1;
}

bool ArchivoTurno::modificar(Turno reg, int posicion){
    FILE* p = fopen(_nombreArchivo, "rb+");
    if(p == NULL){
    return false;
    }
  fseek(p, posicion * sizeof(Turno), SEEK_SET);
    bool escribio = fwrite(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoTurno::bajaLogica(int posicion){
    Turno reg = leer(posicion);
    reg.setEstado(false);
    return modificar(reg, posicion);
}

int ArchivoTurno::getNuevoId(){
    int cantidad = getCantidadRegistros();
    if(cantidad == 0){
    return 1;
    }
    Turno ultimo = leer(cantidad - 1);
    return ultimo.getIdTurno() + 1;
}