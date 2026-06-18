#pragma once
#include "../persistencia/ArchivoAgendaMedico.h"
#include "../entidades/AgendaMedico.h"

class ManagerAgendaMedico{
private:
  ArchivoAgendaMedico _repoAgenda;

public:

  void cargarAgenda();
  void listarAgendas();

  void modificarAgenda();
  void eliminarAgenda();
};