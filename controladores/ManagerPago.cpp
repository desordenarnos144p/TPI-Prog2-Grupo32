#include <iostream>
#include "ManagerPago.h"
#include "entidades/auxiliares/Fecha.h"

using namespace std;

//CONSTRUCTOR.
    ManagerPago::ManagerPago(){}
//METODOS.
    bool ManagerPago::agregar(){
    Pago reg; 
    reg.ingresarDatos();
    reg.setIdPago(_repoPago.getNuevoId());
    bool exito = _repoPago.guardar(reg); 
    if (exito){
        cout << "\nPago registrado correctamente!" << endl;
        return true;
    } else {
        cout << "\nERROR: No se pudo guardar el pago en el disco..." << endl;
        return false;
    }
}

bool ManagerPago::modificar(){ 
    int id;
    cout << "---MODIFICAR PAGO---" << endl;
    cout << "Ingrese el ID del pago a modificar: ";
    cin >> id;
    int pos = _repoPago.buscarPosicion(id);
    if (pos == -1) {
        cout << "\nERROR: El ID de pago no existe o no esta activo..." << endl;
        return false;
    }
    Pago reg = _repoPago.leer(pos);
    cout << "\n---Datos actuales del pago---" << endl;
    reg.mostrar();
    cout << "\n---Ingrese los NUEVOS datos del pago---" << endl;
    reg.ingresarDatos();
    reg.setIdPago(id);
    bool exito = _repoPago.modificar(reg, pos);
    if (exito) {
        cout << "\nPago modificado correctamente!" << endl;
        return true;
    } else {
        cout << "\nERROR: No se pudo actualizar el pago en el archivo..." << endl;
        return false;
    }
}

bool ManagerPago::bajaLogica(){
    int id;
    cout << "---ELIMINAR PAGO (BAJA LOGICA)---" << endl;
    cout << "Ingrese el ID del pago a dar de baja: ";
    cin >> id;
    int pos = _repoPago.buscarPosicion(id);
    if(pos == -1){
        cout << "ERROR: El ID de pago no existe..." << endl;
        return false;
    }
    Pago reg = _repoPago.leer(pos);
    reg.setEstado(false);
    bool exito = _repoPago.modificar(reg, pos);
    if(exito){
        cout << "El pago ha sido cancelado/dado de baja con exito!" << endl;
        return true;
    }else{
        cout << "ERROR: No se pudo procesar la baja en el archivo..." << endl;
        return false;
    }
}

Pago ManagerPago::buscarPorId(int id){
    int cantidad = _repoPago.getCantidadRegistros();
    Pago reg;
    for(int i = 0; i < cantidad; i++){
        reg = _repoPago.leer(i);
        if(reg.getIdPago() == id && reg.getEstado() == true){
            return reg;
        }
    }
    reg.setIdPago(-1);
    return reg;
}

bool ManagerPago::existe(int id){
    Pago reg = buscarPorId(id);
    if (reg.getIdPago() != -1){ 
        return true;
    }
    return false;
}

void ManagerPago::listar(){
    int cantidad = _repoPago.getCantidadRegistros();
    bool hayPagos = false;
    cout << "---LISTADO DE PAGOS ACTIVOS---" << endl;
    for(int i = 0; i < cantidad; i++) {
        Pago reg = _repoPago.leer(i);
        if(reg.getEstado() == true){
            reg.mostrar();
            cout << "-----------------------------------" << endl;
            hayPagos = true;
        }
    }
    if(!hayPagos){
        cout << "No hay pagos activos registrados en el sistema." << endl;
    }
}