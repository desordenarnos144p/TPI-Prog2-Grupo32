#include "Turno.h"
#include <iostream>
#include "../persistencia/ArchivoTurno.h"

using namespace std;

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
    setIdTurno(idTurno);
    setIdPaciente(idPaciente);
    setIdAgendaMedico(agendaMedico);
    setFecha(fecha);
    setHora(hora);
    }

//GETTERS Y SETTERS.
    int Turno::getIdTurno(){
        return _idTurno;
    }
    void Turno::setIdTurno(int idTurno){
        _idTurno = idTurno;
    }

    int Turno::getIdPaciente(){
        return _idPaciente;
    }
    void Turno::setIdPaciente(int idPaciente){
        _idPaciente = idPaciente;
    }

    int Turno::getIdAgendaMedico(){
        return _idAgendaMedico;
    }
    void Turno::setIdAgendaMedico(int idAgendaMedico){
        _idAgendaMedico = idAgendaMedico;
    }

    Fecha Turno::getFecha(){
        return _fecha;
    }
    void Turno::setFecha(Fecha fecha){
        _fecha = fecha;
    }

    Hora Turno::getHora(){
        return _hora;
    }
    void Turno::setHora(Hora hora){
        _hora = hora;
    }

    bool Turno::getEstado(){
        return _estado;
    }
    void Turno::setEstado(bool estado){
        _estado = estado;
    }

//METODOS
    void Turno::ingresarDatos(){
        cout << "ID Paciente: ";
        cin >> _idPaciente;
        cout << "ID Agenda Medico: ";
        cin >> _idAgendaMedico;
        cin.ignore();
        cout << "---Datos de la fecha---" << endl;
        _fecha.cargar();
        cout << "---Datos de la hora---" << endl;
        _hora.cargar();
        _estado = true;
    }

    void Turno::mostrar(){
        if(!getEstado()){
            cout << "[Turno inactivo / cancelado]" << endl;
            return;
        }
        cout << "DETALLE DEL TURNO Nro: " << getIdTurno() << endl;
        cout << "-----------------------" << endl;
        cout << "ID Paciente asignado: " << getIdPaciente() << endl;
        cout << "ID Agenda del Medico: " << getIdAgendaMedico() << endl;
        cout << "Fecha del turno: "; 
        getFecha().mostrar(); 
        cout << endl;
        cout << "Hora del Turno: "; 
        getHora().mostrar();  
        cout << endl;
}