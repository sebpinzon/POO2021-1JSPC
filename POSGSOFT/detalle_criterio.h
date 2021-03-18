#ifndef DETALLE_CRITERIO_H
#define DETALLE_CRITERIO_H

#include <iostream>
#include <string>

using std::string;

class DetalleCriterio
{
	private:
		float calificacionJurado1,calificacionJurado2;
		string observacion;
	public:
		DetalleCriterio();

		float getCalificacionJurado1();
		void setCalificacionJurado1(float);

		float getCalificacionJurado2();
		void setCalificacionJurado2(float);

		string getObservacion();
		void setObservacion(string);
};


#endif