#pragma once

class ArchivoTurno{
    private:
        char nombreArchivo[20];
    public:
        //CONSTRUCTOR.
            ArchivoTurno();
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