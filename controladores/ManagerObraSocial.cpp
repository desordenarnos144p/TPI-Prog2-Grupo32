#include <iostream>
#include "ManagerObraSocial.h"

using namespace std;

ManagerObraSocial::ManagerObraSocial()
{
}

bool ManagerObraSocial::agregar()
{
    ObraSocial obj;

    obj.ingresarDatos();
    obj.setIdObraSocial(getNuevoId());

    return _repoObraSocial.guardar(obj);
}

bool ManagerObraSocial::modificar()
{
    int id;

    cout << "Ingrese ID de la Obra Social: ";
    cin >> id;

    int pos = _repoObraSocial.buscar(id);

    if(pos < 0){
        return false;
    }

    ObraSocial obj = _repoObraSocial.leer(pos);

    obj.ingresarDatos();
    obj.setIdObraSocial(id);

    return _repoObraSocial.modificar(obj, pos);
}

bool ManagerObraSocial::eliminar()
{
    int id;

    cout << "Ingrese ID de la Obra Social a eliminar: ";
    cin >> id;

    int pos = _repoObraSocial.buscar(id);

    if(pos < 0){
        return false;
    }

    ObraSocial obj = _repoObraSocial.leer(pos);

    obj.setEstado(false);

    return _repoObraSocial.modificar(obj, pos);
}

ObraSocial ManagerObraSocial::buscarPorId(int id)
{
    int pos = _repoObraSocial.buscar(id);

    if(pos >= 0){
        return _repoObraSocial.leer(pos);
    }

    return ObraSocial();
}

bool ManagerObraSocial::existe(int id)
{
    return _repoObraSocial.buscar(id) >= 0;
}

void ManagerObraSocial::listar()
{
    int cantidad = _repoObraSocial.cantidadRegistros();

    for(int i = 0; i < cantidad; i++){

        ObraSocial obj = _repoObraSocial.leer(i);

        if(obj.getEstado()){
            obj.mostrar();
        }
    }
}

int ManagerObraSocial::getNuevoId()
{
    return _repoObraSocial.cantidadRegistros() + 1;
