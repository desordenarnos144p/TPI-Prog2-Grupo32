#pragma once
#include "Menu.h"
#include "ManagerAgendaMedico.h"
class MenuMedico : public Menu{
public:
    MenuMedico();

protected:
    void mostrarOpciones() override;
    void ejecutarOpciones(int opcion) override;

private:
    ManagerAgendaMedico _managerAgendaMedico; //SE CONECTA CON EL MANAGER DE AGENDA MEDICA
};
