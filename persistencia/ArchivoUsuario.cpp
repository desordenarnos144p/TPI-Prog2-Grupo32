#include "ArchivoUsuario.h"
#include "../entidades/Usuario.h"

//CONSTRUCTOR.
    ArchivoUsuario::ArchivoUsuario(std::string nombre)
        :_nombreArchivo(nombre){
    }//(?)

//GETTERS,
    //AGREGAR: int getNuevoId();

    int ArchivoUsuario::getCantidadRegistros(){
        FILE *pUser;
        int tamTotal;
        pUser = fopen(_nombreArchivo.c_str(), "rb");
        if(pUser == nullptr){
            return 0;
        }
        fseek(pUser, 0, SEEK_END);
        tamTotal = ftell(pUser) / sizeof(Usuario);
        fclose(pUser);
        return tamTotal;
    }

//METODOS.
    bool ArchivoUsuario::guardar(Usuario obj){
        FILE *pUser;
        pUser = fopen(_nombreArchivo.c_str(), "ab");
        if(pUser == nullptr){
            return false;
        }
        int escribio = fwrite(&obj, sizeof(Usuario), 1, pUser);
        fclose(pUser);
        return escribio;
    }

    Usuario ArchivoUsuario::leer(int pos){
        Usuario obj;
        FILE *pUser;
        pUser = fopen(_nombreArchivo.c_str(), "rb");
        if(pUser == nullptr){
            return obj;
        }
        fseek(pUser, pos * sizeof(Usuario), SEEK_SET);
        fread(&obj, sizeof(Usuario), 1, pUser);
        fclose(pUser);
        return obj;
    }

    int ArchivoUsuario::buscarPosicion(int id){
        int total = getCantidadRegistros();
        for(int i = 0; i < total; i++){
            Usuario obj = leer(i);
            if(obj.getIdUsuario() == id && obj.getEstado() == true){
                return i;
            }
        }
        return -1;
    }

    bool ArchivoUsuario::modificar(Usuario obj, int pos){
        FILE *pUser = fopen(_nombreArchivo.c_str(), "rb+");
        if(pUser == nullptr){
            return false;
        }
        fseek(pUser, pos * sizeof(Usuario), SEEK_SET);
        bool escribio = fwrite(&obj, sizeof(Usuario), 1, pUser);
        fclose(pUser);
        return escribio;
    }

    //AGREGAR: bool bajaLogica(int posicion);
