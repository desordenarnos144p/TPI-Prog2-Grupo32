#pragma once
#include <string>
#include "../entidades/ObraSocial.h"

class ArchivoObraSocial{
    private:
        std::string _nombreArchivo; //Los _nombreArchivo son de tipo char
    public:
        //CONSTRUCTOR.
            ArchivoObraSocial(std::string nombre = "ObraSocial.dat");
        //GETTERS.
            //AGREGAR: int getNuevoId();
            int getCantidadRegistros();
        //METODOS.
            bool guardar(ObraSocial obj);
            ObraSocial leer(int pos);
            int buscarPosicion(int id);
            bool modificar(ObraSocial obj, int pos);
            //AGREGAR: bool bajaLogica(int posicion);
};
