#pragma once 

#include "../entidades/auxiliares/Fecha.h"

class Pago{
    private:
        int _idPago;
        int _idTurno;
        float _monto;
        Fecha _fecha;
        bool _estado;
    public:
        //CONSTRUCTORES.
            Pago();
            Pago(int idPago, int idTurno, float monto, Fecha fecha, bool estado);
        //GETTERS Y SETTERS.
            int getIdPago();
            void setIdPago(int idPago);

            int getIdTurno();
            void setIdTurno(int idTurno);

            float getMonto();
            void setMonto(float monto);

            Fecha getFecha();
            void setFecha(Fecha fecha);

            bool getEstado();
            void setEstado(bool estado);
        //METODOS.
            void ingresarDatos();
            void mostrar();
};
