#include <iostream>
#include "ManagerTurno.h"
#include "entidades/auxiliares/Fecha.h"
#include "entidades/auxiliares/Hora.h"

using namespace std;

//CONSTRUCTOR.
    ManagerTurno::ManagerTurno(){}
//METODOS.
bool ManagerTurno::agregar(){
    Turno reg; 
    reg.ingresarDatos();
    reg.setIdTurno(_repoTurno.getNuevoId());
    bool exito = _repoTurno.guardar(reg); 
    if (exito){
        cout << "\nTurno registrado correctamente!" << endl;
        return true;
    } else {
        cout << "\nERROR: No se pudo guardar el turno en el disco..." << endl;
        return false;
    }
}

bool ManagerTurno::modificar(){ 
    int id;
    cout << "---MODIFICAR TURNO---" << endl;
    cout << "Ingrese el ID del turno a modificar: ";
    cin >> id;
    int pos = _repoTurno.buscarPosicion(id);
    if (pos == -1) {
        cout << "\nERROR: El ID de turno no existe o no esta activo..." << endl;
        return false;
    }
    Turno reg = _repoTurno.leer(pos);
    cout << "\n---Datos actuales del turno---" << endl;
    reg.mostrar();
    cout << "\n---Ingrese los NUEVOS datos del turno---" << endl;
    reg.ingresarDatos();
    reg.setIdTurno(id);
    bool exito = _repoTurno.modificar(reg, pos);
    if (exito) {
        cout << "\nTurno modificado correctamente!" << endl;
        return true;
    } else {
        cout << "\nERROR: No se pudo actualizar el turno en el archivo..." << endl;
        return false;
    }
}

bool ManagerTurno::bajaLogica(){
    int id;
    cout << "---ELIMINAR TURNO (BAJA LOGICA)---" << endl;
    cout << "Ingrese el ID del turno a dar de baja: ";
    cin >> id;
    int pos = _repoTurno.buscarPosicion(id);
    if(pos == -1){
        cout << "ERROR: El ID de turno no existe..." << endl;
        return false;
    }
    Turno reg = _repoTurno.leer(pos);
    reg.setEstado(false);
    bool exito = _repoTurno.modificar(reg, pos);
    if(exito){
        cout << "El turno ha sido cancelado/dado de baja con exito!" << endl;
        return true;
    }else{
        cout << "ERROR: No se pudo procesar la baja en el archivo..." << endl;
        return false;
    }
}

Turno ManagerTurno::buscarPorId(int id){
    int cantidad = _repoTurno.getCantidadRegistros();
    Turno reg;
    for(int i = 0; i < cantidad; i++){
        reg = _repoTurno.leer(i);
        if(reg.getIdTurno() == id && reg.getEstado() == true){
            return reg;
        }
    }
    reg.setIdTurno(-1);
    return reg;
}

bool ManagerTurno::existe(int id){
    Turno reg = buscarPorId(id);
    if (reg.getIdTurno() != -1){ 
        return true;
    }
    return false;
}

void ManagerTurno::listar(){
    int cantidad = _repoTurno.getCantidadRegistros();
    bool hayTurnos = false;
    cout << "---LISTADO DE TURNOS ACTIVOS---" << endl;
    for(int i = 0; i < cantidad; i++) {
        Turno reg = _repoTurno.leer(i);
        if(reg.getEstado() == true){
            reg.mostrar();
            cout << "-----------------------------------" << endl;
            hayTurnos = true;
        }
    }
    if(!hayTurnos){
        cout << "No hay turnos activos registrados en el sistema." << endl;
    }
}

void ManagerTurno::listarPorFecha(){
    Fecha fechaBusqueda;
    cout << "---LISTAR TURNOS POR FECHA---" << endl;
    fechaBusqueda.cargar();
    int cantidad = _repoTurno.getCantidadRegistros();
    bool encontroAlguno = false;
    cout << "\n---LISTADO DE TURNOS PARA LA FECHA SELECCIONADA---" << endl;
    for(int i = 0; i < cantidad; i++) {
        Turno reg = _repoTurno.leer(i);
        if(reg.getEstado() == true && 
            reg.getFecha().getDia() == fechaBusqueda.getDia() &&
            reg.getFecha().getMes() == fechaBusqueda.getMes() &&
            reg.getFecha().getAnio() == fechaBusqueda.getAnio()){
            reg.mostrar();
            cout << "-----------------------------------" << endl;
            encontroAlguno = true;
        }
    }
    if(!encontroAlguno){
        cout << "No se encontraron turnos programados para esta fecha." << endl;
    }
}