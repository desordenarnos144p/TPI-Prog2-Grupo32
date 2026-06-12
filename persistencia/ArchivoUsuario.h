#pragma once
#include <string>
#include "../entidades/Usuario.h"

class ArchivoUsuario {
public:
        ArchivoUsuario(std::string nombre = "Usuario.dat");
        bool guardar(Usuario obj);
        Usuario leer(int pos);
        int cantidadRegistros();
        int buscarPorId(int id);
        bool modificar(Usuario obj, int pos);

    private:
        std::string _nombreArchivo;
};


