#include <iostream>
#include "MenuMedico.h"
using namespace std;

MenuMedico::MenuMedico()
{
    setCantidadItems(1);
}


void MenuMedico::mostrarOpciones()
{
    cout << "----------- SECTOR MEDICO-----------" << endl;
    cout << "---------------------------------------" << endl;
    cout << "1 - VER AGENDA MEDICA" << endl; //TURNOS ACTIVOS SOLAMENTE //MODIFICAR EN MANAGER AGENDAMEDICO !!!
    cout << "0 - SALIR" << endl;
}

void MenuMedico::ejecutarOpciones(int opcion)
{
    switch(opcion)
    {
    case 1:
        _managerAgendaMedico.listarAgendas();
        break;
    case 0:
        break;
    }
}
