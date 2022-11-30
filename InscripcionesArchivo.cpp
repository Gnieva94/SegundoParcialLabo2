#include <iostream>
#include "InscripcionesArchivo.h"

using namespace std;

Inscripcion InscripcionesArchivo::leer(int nroRegistro) {
  Inscripcion reg;
  FILE* pFile;
  pFile = fopen("inscripciones.dat", "rb");

  if (pFile == NULL) {
    cout << "No se pudo abrir el archivo" << endl;
    return reg;
  }

  fseek(pFile, nroRegistro * sizeof(Inscripcion), SEEK_SET);
  fread(&reg, sizeof(Inscripcion), 1, pFile);
  fclose(pFile);
  return reg;
}

bool InscripcionesArchivo::leerTodos(Inscripcion inscripciones[], int cantidad) {
  FILE* pFile;
  pFile = fopen("inscripciones.dat", "rb");

  if (pFile == NULL) {
    cout << "No se pudo abrir el archivo" << endl;
    return false;
  }

  fread(inscripciones, sizeof(Inscripcion), cantidad, pFile);
  fclose(pFile);
  return true;
}


bool InscripcionesArchivo::guardar(Inscripcion reg) {
  FILE* pFile;
  pFile = fopen("inscripciones.dat", "ab");

  if (pFile == NULL) {
    cout << "No se pudo abrir el archivo" << endl;
    return false;
  }

  fwrite(&reg, sizeof(Inscripcion), 1, pFile);
  fclose(pFile);
  return true;
}

bool InscripcionesArchivo::guardar(Inscripcion reg, int nroRegistro) {
  FILE* pFile;
  pFile = fopen("inscripciones.dat", "rb+");

  if (pFile == NULL) {
    cout << "No se pudo abrir el archivo" << endl;
    return false;
  }

  fseek(pFile, nroRegistro * sizeof(Inscripcion), SEEK_SET);
  fwrite(&reg, sizeof(Inscripcion), 1, pFile);
  fclose(pFile);
  return true;
}

int InscripcionesArchivo::getCantidad() {
  FILE* pFile;
  pFile = fopen("inscripciones.dat", "rb");

  if (pFile == NULL) {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  int cant = ftell(pFile) / sizeof(Inscripcion);
  fclose(pFile);
  return cant;
}

int InscripcionesArchivo::buscar(int id) {
  FILE* pFile;
  pFile = fopen("inscripciones.dat", "rb");

  if (pFile == NULL) {
    cout << "No se pudo abrir el archivo" << endl;
    return -1;
  }

  Inscripcion reg;
  int nroRegistro = 0;
  while (fread(&reg, sizeof(Inscripcion), 1, pFile)) {
    if (reg.getId() == id) {
      fclose(pFile);
      return nroRegistro;
    }
    nroRegistro++;
  }
  fclose(pFile);
  return -1;
}

