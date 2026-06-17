#include <iostream>
#include "ManagerUsuario.h"

using namespace std;
//CONSTRUCTOR.
    ManagerUsuario::ManagerUsuario(){}
//METODOS.
    bool ManagerUsuario::agregar(){
        Usuario obj;
        obj.cargar();
        obj.setIdUsuario(getNuevoId());
        return _repoUsuario.guardar(obj);
    }

    bool ManagerUsuario::modificar(){
        int id;
        cout << "Ingrese ID del usuario: ";
        cin >> id;
        int pos = _repoUsuario.buscarPorId(id);
        if(pos < 0){
            return false;
        }
        Usuario obj;
        obj.cargar();
        obj.setIdUsuario(id);
        return _repoUsuario.modificar(obj, pos);
    }

    bool ManagerUsuario::bajaLogica(){
        int id;
        cout << "Ingrese ID del usuario a eliminar: ";
        cin >> id;
        int pos = _repoUsuario.buscarPorId(id);
        if(pos < 0){
            return false;
        }
        Usuario obj = _repoUsuario.leer(pos);
        obj.setEstado(false);
        return _repoUsuario.modificar(obj, pos);
    }

    Usuario ManagerUsuario::buscarPorId(int id){
        int pos = _repoUsuario.buscarPorId(id);
        if(pos >= 0){
            return _repoUsuario.leer(pos);
        }
        return Usuario();
    }

    bool ManagerUsuario::existe(int id){
        int pos = _repoUsuario.buscarPorId(id);
        if(pos >= 0){
            return true;
        } else {
            return false;
        }
    }

    void ManagerUsuario::listar(){
        int cantidad = _repoUsuario.cantidadRegistros();
        for(int i = 0; i < cantidad; i++){
            Usuario obj = _repoUsuario.leer(i);
            if(obj.getEstado()){
                obj.mostrar();
            }
        }
    }

    int ManagerUsuario::getNuevoId(){
        return _repoUsuario.cantidadRegistros() + 1;
    }
