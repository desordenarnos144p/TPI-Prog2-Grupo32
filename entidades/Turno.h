#pragma once

#include "../entidades/auxiliares/Hora.h"
#include "../entidades/auxiliares/Fecha.h"

class Turno{
    private:
        int _idTurno;
        int _idPaciente;
        int _idAgendaMedico;
        Fecha _fecha;
        Hora _hora;
        bool _estado;
    public:
        //CONSTRUCTORES.
            Turno();
            Turno(int idTurno, int idPaciente, int idAgendaMedico, Fecha fecha, Hora hora, bool estado);
        //GETTERS Y SETTERS.
            int getIdTurno();
            void setIdTurno(int idTurno);

            int getIdPaciente();
            void setIdPaciente(int idPaciente);

            int getIdAgendaMedico();
            void setIdAgendaMedico(int idAgendaMedico);

            Fecha getFecha();
            void setFecha(Fecha fecha);

            Hora getHora();
            void setHora(Hora hora);

            bool getEstado();
            void setEstado(bool estado);
        //METODOS.
            void ingresarDatos();
            void mostrar();
};