#include <cstdio>
#include "ArchivoUsuario.h"
#include <cstring>

ArchivoUsuario::ArchivoUsuario(const char* nombreArchivo)
{
    strcpy(_nombreArchivo, nombreArchivo);
}

bool ArchivoUsuario::guardar(Usuario reg){
    reg.setIdUsuario(getNuevoId());

    FILE *pUser = fopen(_nombreArchivo, "ab");

    if(pUser == nullptr){
        return false;
    }

    bool escribio = fwrite(&reg, sizeof reg, 1, pUser);

    fclose(pUser);

    return escribio;
}

bool ArchivoUsuario::sobreEscribirRegistro(Usuario reg, int pos){
    FILE *pUser = fopen(_nombreArchivo, "rb+");  // le agrega al modo lo que le falta

    if(pUser == nullptr){
        return false;
    }

    fseek(pUser, pos * sizeof(Usuario), SEEK_SET);

    bool escribio = fwrite(&reg, sizeof(Usuario), 1, pUser);

    fclose(pUser);

    return escribio;
}

bool ArchivoUsuario::altaLogicaUsuario(const char* usuario){
    Usuario reg;

    int pos = buscarUsuario(usuario);

    if(pos==-1){
        return false;
    }

    reg=leer(pos);

    if(reg.getEstado()==true){
        return true;
    }
    reg.setEstado(true);
    return sobreEscribirRegistro(reg, pos);
}

bool ArchivoUsuario::bajaLogicaUsuario(const char* usuario){
    Usuario reg;

    int pos = buscarUsuario(usuario);

    if(pos==-1){
        return false;
    }

    reg=leer(pos);

    reg.setEstado(false);

    return sobreEscribirRegistro(reg, pos);
}

Usuario ArchivoUsuario::leer(int pos) {
    Usuario reg;
    FILE *pUser = fopen(_nombreArchivo, "rb");

    if (pUser == nullptr){
     return reg;
    }

    fseek(pUser, pos * sizeof reg, SEEK_SET);  //SEEK_SET = 0

    fread(&reg, sizeof reg, 1, pUser);

    fclose(pUser);

    return reg;
}

int ArchivoUsuario::getCantidadRegistros() {
    FILE *pUser;
    int tamTotal;

    pUser = fopen(_nombreArchivo, "rb");
    if (pUser == nullptr){
     return 0;
    }

    fseek(pUser, 0, SEEK_END);
    tamTotal = ftell(pUser) / sizeof(Usuario);
    fclose(pUser);
    return tamTotal;
}


int ArchivoUsuario::buscarUsuario(const char* usuario){
   Usuario reg;
    int posicion=0;
    FILE *pUser=fopen(_nombreArchivo, "rb");

    if(pUser==nullptr){
        return -1;
    }

    while(fread(&reg, sizeof reg, 1, pUser)==1){
        if(strcmp(usuario, reg.getUsuario())==0){
            fclose(pUser);
            return posicion;
        }
        posicion++;
    }
    fclose(pUser);

    return -1;
}

void ArchivoUsuario::listar(){
    Usuario reg;
    FILE *pUser;

    pUser=fopen(_nombreArchivo, "rb");

    if(pUser==nullptr){
        return;
    }
    while(fread(&reg, sizeof reg, 1, pUser)!=0){
        reg.mostrar();
    }
    fclose(pUser);
}

void ArchivoUsuario::listarActivos(){
    Usuario reg;
    FILE *pUser;

    pUser=fopen(_nombreArchivo, "rb");

    if(pUser==nullptr){
        return;
    }
    while(fread(&reg, sizeof reg, 1, pUser)!=0){
        if(reg.getEstado()){
            reg.mostrar();
        }
    }
    fclose(pUser);
}

int ArchivoUsuario::getNuevoId(){
    int cantidad = getCantidadRegistros();

    if(cantidad == 0){
        return 1;
    }

    Usuario ultimo = leer(cantidad - 1);

    return ultimo.getIdUsuario() + 1;
}

