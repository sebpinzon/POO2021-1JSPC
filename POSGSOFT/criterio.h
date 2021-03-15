#ifndef CRITERIO_H
#define CRITERIO_H

#include <iostream>
#include <string>

using std::string;

class Criterio
{
	private:
		string nombre;
		float calificacionJurado1,calificacionJurado2,ponderacion;
		string observacionJurado1,observacionJurado2;
		int id;
	public:
		Criterio();
		Criterio(string,float,float,float,string,string);
		string getNombre();
		void setNombre(string);
		float getPonderacion();
		void setPonderacion(float);
		float getCalificacionJurado1();
		void setCalificacionJurado1(float);
		float getCalificacionJurado2();
		void setCalificacionJurado2(float);
		string getObservacionJurado1();
		void setObservacionJurado1(string);
		string getObservacionJurado2();
		void setObservacionJurado2(string);
		int getId();
		void setId(int);
};


#endif