#include <iostream>
#include "MenuListados.h"
using namespace std;

MenuListados::MenuListados()
{
    setCantidadItems(2);
}


void MenuListados::mostrarOpciones()
{
    cout << "--------------- MENU LISTADOS --------------" << endl;
    cout << "1 - LISTADOS DE MEDICO ORDENADOS POR APELLIDO" << endl;
    cout << "2 - LISTADOS DE MEDICO ORDENADOS POR ESPECIALIDAD" << endl;
    //ACA VAN TODOS LOS LISTADOS DE TODOS, EJEMPLO LISTADOS DE PACIENTES, ETC
}


void MenuListados::ejecutarOpciones(int opcion)
{
    switch(opcion)
    {
    case 1:
        _medicoManager.listarPorApellido();
        break;
    case 2:
        _medicoManager.listarPorEspecialidad();
        break;
    case 0:
        break;
    }
}
