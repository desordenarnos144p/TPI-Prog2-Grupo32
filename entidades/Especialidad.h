#pragma once

class Especialidad{
public:
    Especialidad();
    Especialidad(int idEspecialidad, const char* nombre, bool estado);

    void setIdEspecialidad(int idEspecialidad);
    int getIdEspecialidad();

    void setNombre(const char* nombre);
    const char* getNombre();

    void setEstado(bool estado);
    bool getEstado();

    void cargar(const char* especialidad = 0, int id = 0);
    void mostrar();

    bool validarEspecialidad(const char* especialidad);

private:
    int _idEspecialidad;
    char _nombre[50];
    bool _estado;
};
