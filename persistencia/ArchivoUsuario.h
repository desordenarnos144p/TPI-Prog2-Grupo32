#pragma once
#include <string>
#include "../entidades/Usuario.h"

class ArchivoUsuario {
public:
        ArchivoUsuario(const char* nombreArchivo = "Usuarios.dat");
        bool guardar(Usuario reg);
        bool sobreEscribirRegistro(Usuario reg, int pos);
        Usuario leer(int pos);
        bool altaLogicaUsuario(const char* usuario);
        bool bajaLogicaUsuario(const char* usuario);
        void listar();
        void listarActivos();
        int getCantidadRegistros();
        int getNuevoId();
        int buscarUsuario(const char* usuario);
    private:
         char _nombreArchivo[20];
};


