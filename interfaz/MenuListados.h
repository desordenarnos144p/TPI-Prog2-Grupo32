#pragma once
#include "Menu.h"
#include "ManagerMedico.h"

class MenuListados : public Menu{
public:
    MenuListados();

protected:
    void mostrarOpciones() override;
    void ejecutarOpciones(int opcion) override;

private:
    ManagerMedico _medicoManager;
};
