#pragma once
#include "../persistencia/ArchivoUsuario.h"
#include "../entidades/Usuario.h"

class ManagerUsuario{
public:
    ManagerUsuario();

    bool registrarUsuario();   //NUEVO  CON VERIFICACION DE ESTADO
    bool modificarUsuario();  // CAMBIE MODIFICAR (CADA ATRIBUTO DEL USUARIO) PARA APLICARLO EN MENU ADMIN EN GESTION DE USUARIOS
    bool eliminarUsuario(); // BAJA LOGICA

    int getNuevoId();
    Usuario login();        //NUEVO CON VERIFICACION DE ESTADO
    bool reactivarUsuario(); // NUEVO DA LA ALTA A UN ARCHIVO CON ESTADO FALSE
private:
    ArchivoUsuario _repoUsuario;

};
