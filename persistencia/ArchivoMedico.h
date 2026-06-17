#pragma once

class ArchivoMedico{
        private:
            char _nombreArchivo[20];
    public:
        //CONSTRUCTOR.
            ArchivoMedico(const char* nombreArchivo = "Medicos.dat");
        //GETTERS.
            int getNuevoId();
            int getCantidadRegistros();
        //METODOS.
            bool guardar(const Medico &reg);
            Medico leer(int pos);
            //AGREGAR: int buscarPosicion(int id);
            bool modificar(const Medico &reg, int pos);
            //AGREGAR: bool bajaLogica(int posicion);
            int buscarPosicion(int id);
};
