#pragma once
#include <string>

class Inscripcion
{
  int _id;
  int _idcurso;
  int _legajo;
  int _nota;

public:
  Inscripcion();
  Inscripcion(int id, int idcurso, int legajo, int nota);
  
  
  int getId();
  void setId(int id);

  int getIdCurso();
  void setIdCurso(int idcurso);

  int getLegajo();
  void setLegajo(int legajo);

  int getNota();
  void setNota(int nota);

  std::string toString();
};

