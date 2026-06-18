#include "ArchivoAgendaMedico.h"
#include <cstdio>
#include <cstring>

ArchivoAgendaMedico::ArchivoAgendaMedico(
  const char* nombreArchivo
)
{
  strcpy(_nombreArchivo, nombreArchivo);
}

bool ArchivoAgendaMedico::guardar(
  AgendaMedico reg
)
{
  FILE* pFile = fopen(_nombreArchivo,"ab");

  if(pFile == nullptr)
  {
    return false;
  }

  bool escribio = fwrite(&reg, sizeof(AgendaMedico), 1, pFile);

  fclose(pFile);

  return escribio;
}

AgendaMedico ArchivoAgendaMedico::leer(int pos)
{
  AgendaMedico reg;

  FILE* pFile = fopen(_nombreArchivo,"rb");

  if(pFile == nullptr)
  {
    return reg;
  }

  fseek(
    pFile,
    sizeof(AgendaMedico) * pos, SEEK_SET
  );

  fread(&reg, sizeof(AgendaMedico), 1, pFile);

  fclose(pFile);

  return reg;
}

bool ArchivoAgendaMedico::modificar(
  AgendaMedico reg,
  int pos
)
{
  FILE* pFile = fopen(_nombreArchivo,"rb+" );

  if(pFile == nullptr)
  {
    return false;
  }

  fseek(pFile, sizeof(AgendaMedico) * pos, SEEK_SET);

  bool escribio = fwrite(&reg, sizeof(AgendaMedico), 1, pFile);

  fclose(pFile);

  return escribio;
}

int ArchivoAgendaMedico::getCantidadRegistros()
{
  FILE* pFile = fopen(_nombreArchivo,"rb");

  if(pFile == nullptr)
  {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);

  int cantidad = ftell(pFile) / sizeof(AgendaMedico);

  fclose(pFile);

  return cantidad;
}

int ArchivoAgendaMedico::getNuevoId()
{
  return getCantidadRegistros() + 1;
}

int ArchivoAgendaMedico::buscarPorId(
  int idAgenda
)
{
  AgendaMedico reg;

  int cantidad = getCantidadRegistros();

  for(int i = 0; i < cantidad; i++)
  {
    reg = leer(i);

    if(reg.getIdAgenda() == idAgenda)
    {
      return i;
    }
  }

  return -1;
}