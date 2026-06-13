#pragma once
class Persona{
public:
    Persona();
    Persona(const char* dni, const char* nombre, const char* apellido, const char* telefono, bool estado);

    void setDni(const char* dni);
    const char* getDni();

    void setNombre(const char* nombre);
    const char* getNombre();

    void setApellido(const char* apellido);
    const char* getApellido();

    void setTelefono(const char* telefono);
    const char* getTelefono();

    void setEstado(bool estado);
    bool getEstado();

    void cargar();
    void mostrar();
protected:
    char _dni[20];
    char _nombre[50];
    char _apellido[50];
    char _telefono[20];
    bool _estado;
};
