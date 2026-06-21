pragma once
#include "Menu.h"
#include "MenuListados.h"

class MenuAdministrador : public Menu{
public:
    MenuAdministrador();

protected:
    void mostrarOpciones() override;
    void ejecutarOpciones(int opcion) override;

private:
    //ACA SE CONECTARIA CON LOS MENU LISTADOS, CONSULTAS, REPORTES
    MenuListados _menuListados;
    //MenuConsultas _menuConsultas;
    //MenuReportes _menuReportes;
};
