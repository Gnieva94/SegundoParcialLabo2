#include "Inscripcion.h"

Inscripcion::Inscripcion()
{
  _id = 0;
  _idcurso = 0;
  _legajo = 0;
  _nota = 0;
}

Inscripcion::Inscripcion(int id, int idcurso, int legajo, int nota)
{
  _id = id;
  _idcurso = idcurso;
  _legajo = legajo;
  _nota = nota;
}

int Inscripcion::getId()
{
  return _id;
}

void Inscripcion::setId(int id)
{
  _id = id;
}

int Inscripcion::getIdCurso()
{
  return _idcurso;
}

void Inscripcion::setIdCurso(int idcurso)
{
  _idcurso = idcurso;
}

int Inscripcion::getLegajo()
{
  return _legajo;
}

void Inscripcion::setLegajo(int legajo)
{
  _legajo = legajo;
}

int Inscripcion::getNota()
{
  return _nota;
}

void Inscripcion::setNota(int nota)
{
  _nota = nota;
}

std::string Inscripcion::toString()
{
  std::string cadena;
  cadena = std::to_string(_id) + "," + std::to_string(_idcurso) + "," + std::to_string(_legajo) + "," + std::to_string(_nota);
  return cadena;
}



