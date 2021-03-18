#ifndef CRITERIO_H
#define CRITERIO_H

#include <iostream>
#include <string>
#include "detalle_criterio.h"

using std::string;

class Criterio
{
	private:
		string nombre;
		float ponderacion;
		int id;
		DetalleCriterio detalles;
	public:
		Criterio();

		string getNombre();
		void setNombre(string);

		float getPonderacion();
		void setPonderacion(float);

		int getId();
		void setId(int);

		DetalleCriterio getDetalle();
		void setDetalle(DetalleCriterio);
};


#endif