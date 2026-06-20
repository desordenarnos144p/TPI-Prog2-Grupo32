#include <iostream>
#include "Menu.h"
using namespace std;


void Menu::ejecutarMenu()
{
    int opcion;

    do{

    mostrarOpciones();
    opcion = seleccionarOpciones();
    ejecutarOpciones(opcion);

    }while(opcion != 0);
}



void Menu::setCantidadItems(int cantidadItems)
{
    _cantidadItems = cantidadItems;
}
int Menu::getCantidadItems()
{
    return _cantidadItems;
}



int Menu::seleccionarOpciones()
{
    int opcion;
    do{
        cout << "Opcion: ";
        cin >> opcion;

        if(opcion < 0 || opcion > getCantidadItems())
            {
                cout << "Opcion incorrecta" << endl;
            }

    }while(opcion < 0 || opcion > getCantidadItems());

return opcion;
}
