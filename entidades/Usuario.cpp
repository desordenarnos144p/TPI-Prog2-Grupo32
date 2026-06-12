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
    if(rol == 1 || rol == 2){
        _idRol = rol;
    }
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
//ingresar datos
void Usuario::cargar(){

    char auxNombre[50];
    char auxUsuario[50];
    char auxPassword[50];
    int rol;

    cout << "Nombre completo: ";
    cin.getline(auxNombre, 50);
    setNombre(auxNombre);

    cout << "Nombre de usuario: ";
    cin.getline(auxUsuario, 50);
    setUsuario(auxUsuario);

    cout << "Password: ";
    cin.getline(auxPassword, 50);
    setPassword(auxPassword);

   do{
    cout << "Rol (1-Medico / 2-Recepcionista): ";
    cin >> rol;
    }while(rol != 1 && rol != 2);

    setIdRol(rol);
    setEstado(true);
}

void Usuario::mostrar(){
    cout << " --------------------------------------------------" << endl;
    cout << "DATOS DE USUARIO:" << endl;
    cout << "ID Usuario: " << _idUsuario << endl;
    cout << "Usuario: " << _usuario << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Rol: " << _idRol << endl;
    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
    cout << " --------------------------------------------------" << endl;
}
