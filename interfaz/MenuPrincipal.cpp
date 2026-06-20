#include <iostream>
#include "MenuPrincipal.h"
#include "MenuAdministrador.h"
#include "MenuMedico.h"
using namespace std;

MenuPrincipal::MenuPrincipal()
{
    setCantidadItems(2);
}

void MenuPrincipal::mostrarOpciones()
{
    cout << " -- BIENVENIDOS A LA CLINICA MEDICA --" << endl;
    cout << " ----------- MENU PRINCIPAL ----------" << endl;
    cout << " 1 - INICIAR SESION" << endl;
    cout << " 2 - CREAR USUARIO" << endl;
    cout << " 0 - SALIR" << endl;
}


//FALTA SEGUIR IMPLEMENTANDO ....

void MenuPrincipal::ejecutarOpciones(int opcion)
{
    switch(opcion)
    {
    case 1:
    {
        Usuario reg = _managerUsuario.login();

        if(reg.getIdRol() == 0) //ACA PODRIA SACAR ESTO ??PORQUE SUPONEMOS UN AMBIENTE IDEAL, DONDE LA PERSONA SOLO PONE ROL 1 , 2 O 3
        {
            cout << "NO se pudo iniciar sesion" << endl;
            break;
        }

        switch(reg.getIdRol())
        {
        case 1:
        {
            MenuAdministrador menuAdmi;
            menuAdmi.ejecutarMenu();
            break;
        }
        case 2:
        {
            MenuMedico menuMed;
            menuMed.ejecutarMenu();
            break;
        }
        }
        break;
    }
    case 2:
    {
        _managerUsuario.registrarUsuario();
        break;
    }
    case 0:
        break;
    }
}
