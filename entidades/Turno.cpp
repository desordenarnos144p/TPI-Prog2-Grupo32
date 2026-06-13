#include "Turno.h"
#include <iostream>
#include "../persistencia/ArchivoTurno.h"
#include "../persistencia/ArchivoPaciente.h"
#include "../persistencia/ArchivoAgendaMedico.h"

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
    setIdTurno(archivoTurno.getNuevoId());
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
    int idPaciente, idAgendaMedico;
    Fecha fecha;
    Hora hora;
    cout << "---REGISTRAR NUEVO TURNO---" << endl;
    setIdTurno(archivoTurno.getNuevoId());
    setIdPaciente(archivoPaciente.getNuevoId());
    setIdAgendaMedico(archivoMedico.getNuevoId());  
    cout << "--- Datos de la fecha ---" << endl;
    fecha.cargar(); 
    setFecha(fecha);
    cout << "---Datos de la hora---" << endl;
    hora.cargar();  
    setHora(hora);
    setEstado(true);
    cout << "Turno cargado correctamente!" << endl;
}

void Turno::mostrar(){
    if (!getEstado()) {
        cout << "[Turno Inactivo / Cancelado]" << endl;
        return;
    }
    cout << "DETALLE DEL TURNO Nro: " << getIdTurno() << endl;
    cout << "------------------------" << endl;
    cout << "ID Paciente Asignado: " << getIdPaciente() << endl;
    cout << "ID Agenda del Medico: " << getIdAgendaMedico() << endl;
    cout << "Fecha del Turno: "; 
    getFecha().mostrar(); 
    cout << endl;
    cout << "Hora del Turno: "; 
    getHora().mostrar();  
    cout << endl;
}