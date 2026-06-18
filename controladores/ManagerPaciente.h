#pragma once

#include "../persistencia/ArchivoPaciente.h"

class ManagerPaciente{
private:
  ArchivoPaciente _repoPaciente;

public:
  //CONSTRUCTOR
  ManagerPaciente();

  //METODOS
  void cargarPaciente();
  void listarPacientes();
  void modificarPaciente();
  void eliminarPaciente();

  void listadoOrdenadoPorApellido();

  // METODOS PENDIENTES DE IMPLEMENTAR (COMENTADOS):
  // Paciente buscarPorId(int id);
  // bool existe(int id);
  // void listarPorNombre();
  // void listarPorEdad();
  // void listarPorObraSocial();
};