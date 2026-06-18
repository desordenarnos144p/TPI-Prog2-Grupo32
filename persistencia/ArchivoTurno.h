#pragma once

class ArchivoTurno{
    private:
        char _nombreArchivo[20];
    public:
        //CONSTRUCTOR.
            ArchivoTurno(const char* nombreArchivo = "Turnos.dat");
        //GETTERS.
            int getNuevoId();
            int getCantidadRegistros();
        //METODOS.
            bool guardar(Turno reg);
            Turno leer(int posicion);
            int buscarPosicion(int id);
            bool modificar(Turno reg, int posicion);
            bool bajaLogica(int posicion);
};