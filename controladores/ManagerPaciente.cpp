#include "ManagerPaciente.h"
#include <iostream>

using namespace std;

//CONSTRUCTOR.
    ManagerPaciente::ManagerPaciente(){}
//METODOS.
    void ManagerPaciente::agregar(){
        Paciente reg;
        reg.cargar();
        reg.setIdPaciente(_repoPaciente.getNuevoId());
        if(_repoPaciente.guardar(reg)){
            cout << "PACIENTE GUARDADO CORRECTAMENTE..." << endl;
        } else {
            cout << "ERROR AL GUARDAR PACIENTE..." << endl;
        }
    }

    void ManagerPaciente::modificar(){
        cout << "MODIFICAR PACIENTE" << endl;
        // implementar despu�s
    }

    void ManagerPaciente::bajaLogica(){
        cout << "ELIMINAR PACIENTE" << endl;
        // implementar despu�s
    }

    //AGREGAR: Paciente buscarPorId(int id);

    //AGREGAR: bool existe(int id);

    void ManagerPaciente::listar(){
        int cantidad = _repoPaciente.getCantidadRegistros();
        for(int i = 0; i < cantidad; i++){
            Paciente reg = _repoPaciente.leer(i);
            if(reg.getEstado()){
                reg.mostrar();
                cout << endl;
            }
        }
    }

    //AGREGAR: void listarPorNombre();

    //AGREGAR: void listarPorEdad();
    
    //AGREGAR: void listarPorObraSocial();
