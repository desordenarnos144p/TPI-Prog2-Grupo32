#pragma once

class ArchivoPago{
    private:
        char _nombreArchivo[20];
    public:
        //CONSTRUCTOR.
            ArchivoPago(const char* nombreArchivo = "Pagos.dat");
        //GETTERS.
            int getNuevoId();
            int getCantidadRegistros();
        //METODOS.
            bool guardar(Pago reg);
            Pago leer(int posicion);
            int buscarPosicion(int id);
            bool modificar(Pago reg, int posicion);
            bool bajaLogica(int posicion);
};