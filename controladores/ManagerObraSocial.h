#pragma once
#include <string>
#include "../entidades/ObraSocial.h"

class ArchivoObraSocial {
public:
        ArchivoObraSocial(std::string nombre = "ObraSocial.dat");
        ObraSocial leer(int pos);
        bool guardar(ObraSocial obj);
        int cantidadRegistros();
        int buscar(int id);
        bool modificar(ObraSocial obj, int pos);
    private:
        std::string _nombreArchivo;
};
