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
		Persona estudiante,director,codirector,jurado1,jurado2;
		bool modalidad,estado=1;
		string observacion;
		string observacion_aprobacion;
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
		bool getModalidadBin();
		void setModalidad(bool);

		string getEstado();
		bool getEstadoBin();
		void setEstado(bool);

		float getNotaFinal();
		void calcularNotaFinal();

		Persona getJurado1();
		void setJurado1(Persona);

		Persona getJurado2();
		void setJurado2(Persona);

		list<Criterio> getListaCriterios();
		void setListaCriterios(list<Criterio> listaCriterios);
		void mostrarCriterio(int);

		string getObservacion();
		void setObservacion(string);

		string getObservacionAprobacion();
		void setObservacionAprobacion(string);

};


#endif