#pragma once
/*
#include <string>
#include "../entidades/ObraSocial.h"

class ArchivoObraSocial{
        private:
        std::string _nombreArchivo;
    public:
            ArchivoObraSocial(std::string nombre = "ObraSocial.dat");
            ObraSocial leer(int pos);
            bool guardar(ObraSocial obj);
            int cantidadRegistros();
            int buscar(int id);
            bool modificar(ObraSocial obj, int pos);
};
*/

//Se desarrollo ArchivoObrasocial en el archivo ManagerObraSocial.

#include "persistencia/ArchivoObraSocial.h"
#include "entidades/ObraSocial.h"

class ManagerObraSocial{
    private:
        ArchivoObraSocial _repoObraSocial;
    public:
        //CONSTRUCTOR.
            ManagerObraSocial();
        //METODOS.
            bool agregar();
            bool modificar();
            bool bajaLogica();
            ObraSocial buscarPorId(int id);
            bool existe(int id);
            void listar();
};