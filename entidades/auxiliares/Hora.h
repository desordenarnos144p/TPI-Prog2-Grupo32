#pragma once

class Hora{
private:
    int _hora;
    int _minuto;

public:
    Hora();
    Hora(int hora, int minuto);

    void setHora(int hora);
    void setMinuto(int minuto);

    int getHora();
    int getMinuto();

    bool validarHora();

    void cargar();
    void mostrar();
};
