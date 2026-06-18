#pragma once

class ObraSocial {
public:
    ObraSocial();
    ObraSocial( int idObraSocial, const char* nombre, bool estado);

    void setIdObraSocial(int idObraSocial);
    int getIdObraSocial();

    void setNombre(const char* nombre);
    const char* getNombre();

    void setEstado(bool estado);
    bool getEstado();

    void mostrar();
    void ingresarDatos();

private:
    int _idObraSocial;
    char _nombre[30];
    bool _estado;

};
