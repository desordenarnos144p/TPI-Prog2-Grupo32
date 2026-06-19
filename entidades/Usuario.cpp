#include <iostream>
#include "Usuario.h"
#include <cstring>

using namespace std;

Usuario::Usuario()
{
    _idUsuario=0;
    _idRol=0;
    _estado = false;
    std::strcpy(_usuario, "");
    std::strcpy(_nombre, "");
    std::strcpy(_password, "");
}

Usuario::Usuario(int idUsuario, const char* nombre, const char* usuario, const char* password, int idRol, bool estado)
{
    setIdUsuario(idUsuario);
    setIdRol(idRol);
    setEstado(estado);
    setUsuario(usuario);
    setNombre(nombre);
    setPassword(password);
}


void Usuario::setIdUsuario(int idUsuario){
        if (idUsuario > 0) {
        _idUsuario = idUsuario;
    }
}
int Usuario::getIdUsuario(){
    return _idUsuario;
}

void Usuario::setNombre(const char* nombre){
    if(strlen(nombre) < 50){
        strcpy(_nombre, nombre);
    }
}
const char* Usuario::getNombre(){
    return _nombre;
}

void Usuario::setUsuario(const char* usuario){
    if(strlen(usuario) < 50){
        strcpy(_usuario, usuario);
    }
}
const char* Usuario::getUsuario(){
    return _usuario;
}

void Usuario::setPassword(const char* password){
    if(strlen(password) < 50){
        strcpy(_password, password);
    }
}
const char* Usuario::getPassword(){
    return _password;
}

void Usuario::setIdRol(int rol){
    _idRol = rol;
}

int Usuario::getIdRol(){
    return _idRol;
}

void Usuario::setEstado (bool estado){
    _estado = estado;
}
bool Usuario:: getEstado(){
    return _estado;
}

void Usuario::ingresarDatos(){

    char auxNombre[50];
    char auxUsuario[50];
    char auxPassword[50];
    int idRol;

    cout << "Nombre completo: ";
    cin.ignore();
    cin.getline(auxNombre, 50);
    setNombre(auxNombre);

    cout << "Nombre de usuario: ";
    cin.getline(auxUsuario, 50);
    setUsuario(auxUsuario);

    cout << "Password: ";
    cin.getline(auxPassword, 50);
    setPassword(auxPassword);

    cout << "Ingrese Rol de Usuario (1:Adiministrador 2:Medico 3:Paciente): "; // ACÁ VA EL LISTADO DE ROLES DESDE ManagerRol
    cin >> idRol;

    setIdRol(idRol);

    setEstado(true);
}

void Usuario::mostrar(){  // metodo para mostrar datos de usuarios registrados en listar()
  //  cout << " --------------------------------------------------" << endl;
    cout << "DATOS DE USUARIO:" << endl<<endl;
    cout << "ID Usuario: " << _idUsuario << endl;
    cout << "Usuario: " << _usuario << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Rol: " << _idRol << endl;
    cout << "Contrasenia: " << _password << endl;
    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
    cout << " --------------------------------------------------" << endl;
}
