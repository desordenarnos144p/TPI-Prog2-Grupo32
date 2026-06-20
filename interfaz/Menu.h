#pragma once
class Menu{ //MENU BASE
public:
    void ejecutarMenu();

protected: //LO QUE ESTA EN PROTECTED LO UTILIZAN LOS HIJOS
    void setCantidadItems(int cantidad);
    int getCantidadItems();

    virtual void mostrarOpciones() = 0; //OPCION POLIMORFICA, SOLO LO IMPLEMENTAN LOS HIJOS
    int seleccionarOpciones();
    virtual void ejecutarOpciones(int opcion) = 0; //OPCION POLIMORFICA, SOLO LO IMPLEMENTAN LOS HIJOS

private:
    int _cantidadItems;
};
