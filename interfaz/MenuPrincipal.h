#pragma once
#include "Menu.h"
#include "ManagerUsuario.h"
class MenuPrincipal : public Menu{
public:
    MenuPrincipal();

protected:
    void mostrarOpciones() override;
    void ejecutarOpciones(int opcion) override;

private:
    ManagerUsuario _managerUsuario; //EL MENU PRINCIPAL SE CONECTA CON MANAGER USUARIO
};
