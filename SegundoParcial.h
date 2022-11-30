#pragma once
#include <iostream>
#include "EstudiantesArchivo.h"
#include "InscripcionesArchivo.h"
class SegundoParcial
{
private:
	int  _idCurso;
	float _pAprobados, _pDesaprobados;
public:
	//FUNCIONES PARCIAL
	void alumnosDesaprobados();
	void peorCurso();
	void verGeneraciones();
	void generarReporte();
	void mostrarReporte();

	//METODOS DE CLASE
	void setPorcentajeAprobados(float porcentajeAprobados) { _pAprobados = porcentajeAprobados; }
	void setPorcentajeDesaprobados(float porcentajeDesaprobados) { _pDesaprobados = porcentajeDesaprobados; }
	void setIdCurso(int idCurso) { _idCurso = idCurso; }
	float getPorcentajeAprobados() { return _pAprobados; }
	float getPorcentajeDesaprobados() { return _pDesaprobados; }
	int getIdCurso() { return _idCurso; }
};

//FUNCIONES AUXILIARES
int buscarMayorVector(int* vCursos, int cant);
bool guardar(SegundoParcial& sp);
bool leerTodos(SegundoParcial* vSp, int cantidad);
int getCantidadArchivo();