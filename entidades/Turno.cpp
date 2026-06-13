#include "Turno.h"
#include <iostream>

//CONSTRUCTORES.
    Turno::Turno(){
        _idTurno = 0;
        _idPaciente = 0;
        _idAgendaMedico = 0;
        _fecha = Fecha();
        _hora = Hora();
        _estado = false;
    }
    Turno::Turno(int idTurno, int idPaciente, int agendaMedico, Fecha fecha, Hora hora, bool estado){

    };
//GETTERS Y SETTERS.
    int Turno::getIdTurno(){
        return _idTurno;
    };
    void Turno::setIdTurno(int idTurno){
        _idTurno = idTurno;
    };

    int Turno::getIdPaciente(){
        return _idPaciente;
    };
    void Turno::setIdPaciente(int idPaciente){
        _idPaciente = idPaciente;
    };

    int Turno::getIdAgendaMedico(){
        return _idAgendaMedico;
    };
    void Turno::setIdAgendaMedico(int idAgendaMedico){
        _idAgendaMedico = idAgendaMedico;
    };

    Fecha Turno::getFecha(){
        return _fecha;
    };
    void Turno::setFecha(Fecha fecha){
        _fecha = fecha;
    };

    Hora Turno::getHora(){
        return _hora;
    };
    void Turno::setHora(Hora hora){
        _hora = hora;
    };

    bool Turno::getEstado(){
        return _estado;
    };
    void Turno::setEstado(bool estado){
        _estado = estado;
    };
