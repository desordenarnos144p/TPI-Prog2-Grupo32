#include <iostream>
#include "ManagerMedico.h"

using namespace std;

//CONSTRUCTOR.
    ManagerMedico::ManagerMedico(){
        : _repoMedico(), _repoEspecialidad() //(?)
    }
//METODOS.
    void ManagerMedico::agregar(){ //(?)
        Medico med;
        char auxMatricula[50];
        int id = _repoMedico.getNuevoId();
        cout << "--INGRESO NUEVO MEDICO--" << endl;
        cout << "ID Medico #" << id << endl;
        pedirMatriculaAlUsuario(auxMatricula);
        int pos = _repoMedico.buscarMedico(auxMatricula);
        if(pos >= 0){
            cout << "LA MATRICULA MEDICA YA EXISTE EN EL SISTEMA" << endl;
            return;
        } else {
            med.cargar(auxMatricula, id);
            if(_repoMedico.guardar(med)){
                cout << "Medico guardado" << endl;
            } else {
                cout << "Error, medico no se pudo guardar" << endl;
            }
        }
    }

    //AGREGAR: bool modificar();

    void ManagerMedico::bajaLogica(){
        Medico med;
        char auxMatricula[50];
        pedirMatriculaAlUsuario(auxMatricula);
        int pos = _repoMedico.buscarMedico(auxMatricula);
        if(pos < 0){
            cout << "LA MATRICULA MEDICA NO EXISTE EN EL SISTEMA" << endl;
            return;
        } else {
            med = _repoMedico.leer(pos);
            med.setEstado(false);
            if(_repoMedico.modificar(med, pos)){
                cout << "Medico eliminado" << endl;
            } else {
                cout << "Medico no se pudo eliminar" << endl;
            }
        }
    }

    //AGREGAR: Medico buscarPorId(int id);
    //AGREGAR: bool existe(int id);

    void ManagerMedico::listar(){
        Medico med;
        int cant = _repoMedico.getCantidadRegistros();
        if(cant > 0){
            cout << "-- LISTADO DE MEDICOS --" << endl;
            for(int i = 0; i < cant; i++){
                med = _repoMedico.leer(i);
                if(med.getEstado() == true){
                    med.mostrar();
                    cout << endl;
                }
            }
        }
    }

    void ManagerMedico::modificarMatricula(){
        Medico med;
        char auxMatricula[50];
        pedirMatriculaAlUsuario(auxMatricula);
        int pos = _repoMedico.buscarMedico(auxMatricula);
        if(pos < 0){
            cout << "LA MATRICULA MEDICA NO EXISTE EN EL SISTEMA O ESTA DADA DE BAJA" << endl;
            return;
        } else {
            char nuevaMatricula[50];
            pedirMatriculaAlUsuario(nuevaMatricula);
            if(_repoMedico.buscarMedico(nuevaMatricula) >= 0){
                cout << "LA MATRICULA MEDICA NUEVA YA EXISTE" << endl;
                return;
            } else {
                med = _repoMedico.leer(pos);
                med.setMatricula(nuevaMatricula);
                if(_repoMedico.modificar(med, pos)){
                    cout << "Matricula modificada";
                } else {
                    cout << "Matricula no se pudo modificar";
                }
            }
        }
    }

    void ManagerMedico::listarPorApellido(){
        int cant = _repoMedico.getCantidadRegistros();
        if(cant <= 0){
            cout << "El archivo no tiene registros" << endl;
        }
        Medico *medPuntero = new Medico [cant];
        if(medPuntero==nullptr){
            return;
        }
        for(int i = 0; i < cant; i++){
            medPuntero[i] = _repoMedico.leer(i);
        }
        Medico aux;
        for(int i = 0; i < cant-1; i++){
            for(int x = i+1; x < cant; x++){
                if(strcpy(medPuntero[i].getApellido(), medPuntero[x].getApellido()) > 0){
                    aux = medPuntero[i];
                    medPuntero[i] = medPuntero[x];
                    medPuntero[x] = aux;
                }
            }
        }

        for(int i = 0; i < cant; i++){
            if(medPuntero[i].getEstado() == true){
                medPuntero[i].mostrar();
                cout << "---------------------------" << endl;
            }
        }
        delete[] medPuntero;
    }

    void ManagerMedico::listarPorEspecialidad(){
        int cant = _repoMedico.getCantidadRegistros();
        if(cant <= 0){
            cout << "El archivo no tiene registros" << endl;
        }
        Medico *medPuntero = new Medico [cant];
        if(medPuntero==nullptr){
            return;
        }
        for(int i = 0; i < cant; i++){
            medPuntero[i] = _repoMedico.leer(i);
        }
        Medico aux;
        for(int i = 0; i < cant-1; i++){
            for(int x = i+1; x < cant; x++){
                if(medPuntero[i].getIdEspecialidad() > medPuntero[x].getIdEspecialidad()){
                    aux = medPuntero[i];
                    medPuntero[i] = medPuntero[x];
                    medPuntero[x] = aux;
                }
            }
        }
        Especialidad esp;
        for(int i = 0; i < cant; i++){
            if(medPuntero[i].getEstado() == true){
                medPuntero[i].mostrar();
    /*
                cout << "------------------------------------" << endl;
                ver si lo dejo o no --- > muestra el nombre de la especialidad, no solo un numero
                int idEspecialidad = medPuntero[i].getIdEspecialidad();
                int cantEspecialidad = _repoEspecialidad.getCantidadRegistros();
                for(int j=0; j<cantEspecialidad; j++){
                    esp = _repoEspecialidad.leer(j);
                    if(esp.getIdEspecialidad() == idEspecialidad){
                        cout << "Nombre de la especialidad: " << esp.getNombre() << endl;
                        break;
                    }
                }
                cout << "-----------------------------";
                hasta aca
    */
            }
        }
        delete[]medPuntero;
    }

    void ManagerMedico::pedirMatriculaAlUsuario(char* matriculaDestino){
        bool esValida = false;
        Medico med;
        { //(?)
            cout << "Ingrese matricula medica: ";
            cin >> matriculaDestino;

            esValida = med.validarMatricula(matriculaDestino);

            if(!esValida)
            {
                cout << "Error.. Ingrese nuevamente la matricula: ";
            }
        }
        while(!esValida); //(?)
    }
