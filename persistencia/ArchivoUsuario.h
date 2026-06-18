#pragma once
#include <string>
#include "../entidades/Usuario.h"

class ArchivoUsuario{
    private:
        std::string _nombreArchivo; //Los _nombreArchivo son de tipo char
    public:
        //CONSTRUCTOR.    
            ArchivoUsuario(std::string nombre = "Usuario.dat");
        //GETTERS.
            //AGREGAR: int getNuevoId();
            int getCantidadRegistros();
        //METODOS.
            bool guardar(Usuario obj);
            Usuario leer(int pos);
            int buscarPosicion(int id);
            bool modificar(Usuario obj, int pos);
            //AGREGAR: bool bajaLogica(int posicion);
};


