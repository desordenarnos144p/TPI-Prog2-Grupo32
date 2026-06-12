#include "../entidades/Usuario.h"

class ManagerUsuario{
public:
    ManagerUsuario();

    bool agregar();
    bool modificar();
    bool eliminar();

    Usuario buscarPorId(int id);
    bool existe(int id);

    void listar();

    int getNuevoId();
private:
    ArchivoUsuario _repoUsuario;

};
