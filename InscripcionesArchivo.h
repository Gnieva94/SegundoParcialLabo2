#pragma once
#include "Inscripcion.h"
class InscripcionesArchivo
{
public:
  Inscripcion leer(int nroRegistro);
  bool leerTodos(Inscripcion estudiantes[], int cantidad);
  bool guardar(Inscripcion reg);
  bool guardar(Inscripcion reg, int nroRegistro);
  int getCantidad();
  int buscar(int id);
};

