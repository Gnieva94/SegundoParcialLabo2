#pragma once
#include <iostream>
#include "EstudiantesArchivo.h"
#include "InscripcionesArchivo.h"
class SegundoParcial
{
private:
	int _pAprobados, _pDesaprobados, _idCurso;
public:
	//FUNCIONES PARCIAL
	void alumnosDesaprobados();
	void peorCurso();
	void verGeneraciones();
	void generarReporte();

	//METODOS DE CLASE
	void setPorcentajeAprobados(int porcentajeAprobados) { _pAprobados = porcentajeAprobados; }
	void setPorcentajeDesaprobados(int porcentajeDesaprobados) { _pDesaprobados = porcentajeDesaprobados; }
	void setIdCurso(int idCurso) { _idCurso = idCurso; }
	int getPorcentajeAprobados() { return _pAprobados; }
	int getPorcentajeDesaprobados() { return _pDesaprobados; }
	int getIdCurso() { return _idCurso; }
};

//FUNCIONES AUXILIARES
int buscarMayorVector(int* vCursos, int cant);
bool guardar(SegundoParcial& sp);
bool leerTodos(SegundoParcial* vSp, int cantidad);