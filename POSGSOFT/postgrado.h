#ifndef POSTGRADO_H
#define POSTGRADO_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "acta.h"

using std::string;
using std::list;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::ios;
using std::to_string;

class Postgrado
{
	private:
		list<string> listaDirectores;
		list<string> listaJurados;
		list<Acta> listaActas;
		int numero_directores=0, numero_jurados=0, numero_actas=0;

	public:
		Postgrado();

		void clean();

		list<Acta> getlistaActas();
		void setlistaActas(list<Acta>);

		list<string> getlistaDirectores();
		void setlistaDirectores(list<string>);

		list<string> getlistaJurados();
		void setlistaJurados(list<string>);

		Persona modificarPersona(Persona);
		list<Criterio> modificarCriterios(list<Criterio>);
		string modificarObservacionGeneral(string);
		string modificarObservacionAprobacion(string);
		int modificarNumeroActa(int);
		string modificarFechaActa(string);
		string modificarPeriodoActa(string);
		string modificarEnfasisActa(string);
		bool modificarModalidadActa(bool);
		bool modificarEstadoActa(bool);
		string modificarNombreActa(string);
		int modificarActa();
		void crearActa();
		void listarActas();
		void archivoTexto(list<Acta>::iterator);
		int crearArchivoTexto();
		void listarporDirector();
		void listarporJurado();



};

#endif