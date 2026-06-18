#include "Pago.h"
#include <iostream>
#include "../persistencia/ArchivoPago.h"

using namespace std;

Pago::Pago(){
    _idPago = 0;
    _idTurno = 0;
    _monto = 0.0;
    _fecha = Fecha();
    _estado =  false;
}

Pago::Pago(int idPago, int idTurno, float monto, Fecha fecha, bool estado){
    setIdPago(idPago);
    setIdTurno(idTurno);
    setMonto(monto);
    setFecha(fecha);
    setEstado(estado);
}

//GETTERS Y SETTERS.
    int Pago::getIdPago(){
        return _idPago;
    }
    void Pago::setIdPago(int idPago){
        _idPago = idPago;
    }

    int Pago::getIdTurno(){
        return _idTurno;
    }
    void Pago::setIdTurno(int idTurno){
        _idTurno = idTurno;
    }

    float Pago::getMonto(){
        return _monto;
    }
    void Pago::setMonto(float monto){
        _monto = monto;
        //AGREGAR VALIDACIONES.
    }

    Fecha Pago::getFecha(){
        return _fecha;
    }
    void Pago::setFecha(Fecha fecha){
        _fecha = fecha;
    }

    bool Pago::getEstado(){
        return _estado;
    }
    void Pago::setEstado(bool estado){
        _estado = estado;
    }

//METODOS.
    void Pago::ingresarDatos(){
        cout << "ID pago: ";
        cin >> _idPago;
        cout << "ID turno: ";
        cin >> _idTurno;
        cout << "Monto: ";
        cin >> _monto;
        cin.ignore();
        _fecha.cargar();
        _estado = true; 
    }

    void Pago::mostrar(){
        if(!getEstado()){
            cout << "[Pago rechazado / cancelado]" << endl;
            return;
        }
        cout << "DETALLE DEL PAGO Nro: " << getIdPago() << endl;
        cout << "----------------------" << endl;
        cout << "ID Turno asignado: " << getIdTurno() << endl;
        cout << "Monto del pago: " << getMonto() << endl;
        cout << "Fecha del pago: ";
        getFecha().mostrar();
        cout << endl;
    }