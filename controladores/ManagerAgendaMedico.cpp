#include "ManagerAgendaMedico.h"
#include <iostream>

using namespace std;

void ManagerAgendaMedico::cargarAgenda(){

  AgendaMedico reg;

  reg.cargar();

  reg.setIdAgenda(
    _repoAgenda.getNuevoId()
  );

  if(_repoAgenda.guardar(reg)){
    cout << "AGENDA GUARDADA CORRECTAMENTE" << endl;
  }
  else{
    cout << "ERROR AL GUARDAR AGENDA" << endl;
  }
}
void ManagerAgendaMedico::listarAgendas(){

  int cantidad =
    _repoAgenda.getCantidadRegistros();

  for(int i = 0; i < cantidad; i++){

    AgendaMedico reg =
      _repoAgenda.leer(i);

    if(reg.getEstado()){

      reg.mostrar();

      cout << endl;
    }
  }
}
void ManagerAgendaMedico::eliminarAgenda(){

  int idAgenda;

  cout << "ID Agenda: ";
  cin >> idAgenda;

  int pos =
    _repoAgenda.buscarPorId(idAgenda);

  if(pos == -1){

    cout << "NO EXISTE LA AGENDA" << endl;

    return;
  }

  AgendaMedico reg =
    _repoAgenda.leer(pos);

  reg.setEstado(false);

  if(_repoAgenda.modificar(reg, pos)){

    cout << "AGENDA ELIMINADA" << endl;
  }
}
void ManagerAgendaMedico::modificarAgenda(){

  int idAgenda;

  cout << "ID Agenda: ";
  cin >> idAgenda;

  int pos =
    _repoAgenda.buscarPorId(idAgenda);

  if(pos == -1){

    cout << "NO EXISTE LA AGENDA" << endl;

    return;
  }

  AgendaMedico reg =
    _repoAgenda.leer(pos);

  cout << endl;
  cout << "NUEVOS DATOS" << endl;

  reg.cargar();

  reg.setIdAgenda(idAgenda);

  if(_repoAgenda.modificar(reg, pos)){

    cout << "AGENDA MODIFICADA" << endl;
  }
}