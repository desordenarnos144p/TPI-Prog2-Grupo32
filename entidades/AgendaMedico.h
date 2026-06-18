#pragma once

#include "auxiliares/Fecha.h"
#include "auxiliares/Hora.h"

class AgendaMedico{

private:

    int _idAgenda;
    int _idMedico;
    Fecha _fecha;
    Hora _hora;
    bool _disponible;
    bool _estado;

public:

    AgendaMedico();

    AgendaMedico(int idAgenda, int idMedico, Fecha fecha, Hora hora, bool disponible, bool estado);


    void setIdAgenda(int idAgenda);
    int getIdAgenda();

    void setIdMedico(int idMedico);
    int getIdMedico();

    void setFecha(Fecha fecha);
    Fecha getFecha();

    void setHora(Hora hora);
    Hora getHora();

    void setDisponible(bool disponible);
    bool getDisponible();

    void setEstado(bool estado);
    bool getEstado();

    void cargar();
    void mostrar();




};
