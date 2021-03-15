#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <string>
#include <list>
#include "criterio.h"
#include "persona.h"

using std::string;
using std::list;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

class Acta
{
	private:
		int numero_acta,aprovacion,count_jurados=0,count_criterios=0;
		string fecha,periodo,enfasis;
		Persona estudiante,director,codirector;
		bool modalidad,estado;
		list<Persona> listaJurados;
		string listaObservaciones[2];
		list<Criterio> listaCriterios;
		float nota_final;
	public:
		Acta();

		void mostrarActa();

		int getNumeroActa();
		void setNumeroActa(int);

		string getFecha();
		void setFecha(string);

		string getPeriodo();
		void setPeriodo(string);

		string getEnfasis();
		void setEnfasis(string);
		
		int getAprovacion();
		void setAprovacion(int);

		Persona getEstudiante();
		void setEstudiante(Persona);

		Persona getDirector();
		void setDirector(Persona);

		Persona getCodirector();
		void setCodirector(Persona);

		string getModalidad();
		void setModalidad(bool);

		string getEstado();
		void setEstado(bool);

		float getNotaFinal();
		void calcularNotaFinal();

		void mostrarJurado(int);
		string mostrarNombreJurado(int);
		void agregarJurado(Persona);

		void mostrarCriterio(int);
		void agregarCriterio(Criterio);

		void mostrarObservaciones();
		void agregarObservacion(int);

};




#endif