#pragma once
#include "persistencia/ArchivoPago.h"
#include "../entidades/Pago.h"

class ManagerPago{
    private:
    ArchivoPago _repoPago;
    public:
        //CONSTRUCTOR.
            ManagerPago();
        //METODOS.
            bool agregar();
            bool modificar();
            bool bajaLogica();
            Pago buscarPorId(int id);
            bool existe(int id);
            void listar();
            void listarPorFecha();
};