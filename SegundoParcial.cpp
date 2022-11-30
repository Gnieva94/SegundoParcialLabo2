#include "SegundoParcial.h"

//FUNCIONES PARCIAL
void SegundoParcial::alumnosDesaprobados()
{
	InscripcionesArchivo inscripciones;

	int cantidadInscripciones = inscripciones.getCantidad();
	
	int vCursos[10]{};
	Inscripcion* totalInscripciones = new Inscripcion[cantidadInscripciones];
	if (totalInscripciones == nullptr) {
		std::cout << "No se pudo crear vector dinamico." << std::endl;
		return;
	}
	inscripciones.leerTodos(totalInscripciones, cantidadInscripciones);
	for (int x = 0;x < cantidadInscripciones;x++) {
		if (totalInscripciones[x].getNota() != 0) {
			if (totalInscripciones[x].getNota() < 6) {
				vCursos[totalInscripciones[x].getIdCurso() - 1]++;
			}
		}
	}

	int aux = buscarMayorVector(vCursos, 10);

	for (int x = 0;x < 10;x++) {
		if (vCursos[x] == aux) std::cout << "El curso " << x + 1 << " tiene " << vCursos[x] << " alumnos desaprobados." << std::endl;
	}
	
	delete[] totalInscripciones;
}

void SegundoParcial::peorCurso()
{
	bool vCursos[10]{};
	InscripcionesArchivo inscripciones;

	int cantidadInscripciones = inscripciones.getCantidad();
	Inscripcion* totalInscripciones = new Inscripcion[cantidadInscripciones];
	if (totalInscripciones == nullptr) {
		std::cout << "No se pudo crear vector dinamico." << std::endl;
		return;
	}
	inscripciones.leerTodos(totalInscripciones, cantidadInscripciones);
	for (int x = 0;x < cantidadInscripciones;x++) {
		if (totalInscripciones[x].getNota() != 0) {
			if (totalInscripciones[x].getNota() >= 6) {
				vCursos[totalInscripciones[x].getIdCurso() - 1]=true;
			}
		}
	}
	for (int x = 0;x < 10;x++) {
		if (!vCursos[x]) std::cout << "El curso " << x + 1 << " tiene todos sus alumnos desaprobados." << std::endl;
		//else std::cout << "En el curso " << x + 1 << " al menos un alumno aprobo el examen final." << std::endl;
	}

	delete[] totalInscripciones;
}

void SegundoParcial::verGeneraciones()
{
	
	 //Crear un método llamado verGeneraciones que muestre para cada curso la
	 //generación en la que más alumnos tenga inscriptos. Se clasifican según el año de
	 //nacimiento de la siguiente manera:
	 //Generación silenciosa <= 1945
	 //Baby boomers 1946 - 1964
	 //Generación X 1965 - 1980
	 //Millennials 1981 - 1995
	 //Generación Z 1996 - 2012
	 //Generación Alpha >= 2013
	
	InscripcionesArchivo inscripciones;
	EstudiantesArchivo arEstudiantes;
	
	int cantidadInscripciones = inscripciones.getCantidad();
	int cantidadEstudiantes = arEstudiantes.getCantidad();

	Inscripcion* totalInscripciones = new Inscripcion[cantidadInscripciones];
	if (totalInscripciones == nullptr) {
		std::cout << "No se pudo crear vector dinamico." << std::endl;
		return;
	}
	Estudiante* totalEstudiantes = new Estudiante[cantidadEstudiantes];
	if (totalEstudiantes == nullptr) {
		std::cout << "No se pudo crear vector dinamico." << std::endl;
		return;
	}

	inscripciones.leerTodos(totalInscripciones, cantidadInscripciones);
	arEstudiantes.leerTodos(totalEstudiantes, cantidadEstudiantes);

	int mGeneraciones[6][10]{};
	for (int x = 0;x < cantidadInscripciones;x++) {
		for (int y = 0;y < cantidadEstudiantes;y++) {
			if (totalInscripciones[x].getLegajo() == totalEstudiantes[y].getLegajo()) {
				int edad = totalEstudiantes[y].getFechaNacimiento().getAnio();
				if (edad >= 1945) mGeneraciones[0][totalInscripciones[x].getIdCurso()]++;
				if(edad>=1946&&edad<=1964) mGeneraciones[1][totalInscripciones[x].getIdCurso()]++;
				if (edad >= 1965 && edad <= 1980) mGeneraciones[2][totalInscripciones[x].getIdCurso()]++;
				if (edad >= 1981 && edad <= 1995) mGeneraciones[3][totalInscripciones[x].getIdCurso()]++;
				if (edad >= 1996 && edad <= 2012) mGeneraciones[4][totalInscripciones[x].getIdCurso()]++;
				if (edad >= 2013) mGeneraciones[5][totalInscripciones[x].getIdCurso()]++;
			}
		}
	}
	/*for (int x = 0;x < 10;x++) {
		int aux = mGeneraciones[0][x];
		for (int y = 0;y < 6;y++) {
			if (mGeneraciones[y][x] > aux) {
				aux = mGeneraciones[y][x];
			}
		}
	}*/
	for (int i = 0; i < 10; i++)
	{
		int mayor = mGeneraciones[i][0];
		int posicion = 0;
		for (int j = 0; j < 6; j++)
		{
			if (mGeneraciones[i][j] > mayor)
			{
				mayor = mGeneraciones[i][j];
				posicion = j;
			}
		}
		std::cout << "Curso " << i << " - Generacion ";
		switch (posicion)
		{
		case 0:
			std::cout << "Silenciosa";
			break;
		case 1:
			std::cout << "Baby Boomers";
			break;
		case 2:
			std::cout << "X";
			break;
		case 3:
			std::cout << "Millennials";
			break;
		case 4:
			std::cout << "Z";
			break;
		case 5:
			std::cout << "Alpha";
			break;
		}
		std::cout << std::endl;
	}
	delete[] totalInscripciones;
	delete[] totalEstudiantes;
}
	
void SegundoParcial::generarReporte()
{
	//Crear un método llamado generarReporte que genere un archivo llamado
	//reportes.dat donde se guarde para cada curso el porcentaje de aprobados y
	//desaprobados de todos los cursos que se hayan terminado.
	InscripcionesArchivo inscripciones;
	SegundoParcial sp;

	int cantidadInscripciones = inscripciones.getCantidad();
	
	Inscripcion* totalInscripciones = new Inscripcion[cantidadInscripciones];
	if (totalInscripciones == nullptr) {
		std::cout << "No se pudo crear vector dinamico." << std::endl;
		return;
	}
	
	inscripciones.leerTodos(totalInscripciones, cantidadInscripciones);
	
	int mCursos[10][3]{};
	for (int x = 0;x < cantidadInscripciones;x++) {
		if (totalInscripciones[x].getNota() == 0) mCursos[totalInscripciones[x].getIdCurso() - 1][2]++;
		if(totalInscripciones[x].getNota()>=6) mCursos[totalInscripciones[x].getIdCurso() - 1][0]++;
		mCursos[totalInscripciones[x].getIdCurso() - 1][1]++;
	}
	for (int x = 0;x < 10;x++) {
		int total=0, desaprobados=0;
		if (mCursos[x][2] == 0) {
			total = mCursos[x][1];
			desaprobados = mCursos[x][0] - total;
		}
		int pAprobados = mCursos[x][0]/total;
		int pDesaprobados = desaprobados / total;
		/*std::cout << "El porcentaje de aprobados del curso " << x + 1 << " es: " << pAprobados << std::endl;
		std::cout << "El porcentaje de desaprobados del curso " << x + 1 << " es: " << pDesaprobados << std::endl;*/
		sp.setIdCurso(x + 1);
		sp.setPorcentajeAprobados(pAprobados);
		sp.setPorcentajeDesaprobados(pDesaprobados);
		if (guardar(sp)) std::cout << "Guardado correctamente." << std::endl;

	}




	delete[] totalInscripciones;
}

//FUNCIONES AUXILIARES
int buscarMayorVector(int* vCursos, int cant)
{
	int aux=vCursos[0];
	for (int x = 1;x < cant;x++) {
		if (vCursos[x] > aux) {
			aux = vCursos[x];
		}
	}
	return aux;
}

bool guardar(SegundoParcial& sp)
{
	FILE* p = fopen("reportes.dat", "ab");
	if (p == NULL) {
		return false;
	}
	bool ok = fwrite(&sp, sizeof(SegundoParcial), 1, p);
	fclose(p);
	return ok;
}

bool leerTodos(SegundoParcial* vSp, int cantidad)
{
	FILE* p;
	p = fopen("reportes.dat", "rb");
	if (p == NULL) {
		return false;
	}
	fread(vSp, sizeof(SegundoParcial), cantidad, p);
	fclose(p);
	return true;
}

