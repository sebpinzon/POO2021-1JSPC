#include "detalle_criterio.h"


DetalleCriterio::DetalleCriterio(){}

float DetalleCriterio::getCalificacionJurado1()
{
	return calificacionJurado1;
}

void DetalleCriterio::setCalificacionJurado1(float calificacionJurado1)
{
	this->calificacionJurado1 = calificacionJurado1;
}

float DetalleCriterio::getCalificacionJurado2()
{
	return calificacionJurado2;
}

void DetalleCriterio::setCalificacionJurado2(float calificacionJurado2)
{
	this->calificacionJurado2 = calificacionJurado2;
}

string DetalleCriterio::getObservacion()
{
	return observacion;
}
void DetalleCriterio::setObservacion(string observacion)
{
	this->observacion = observacion;
}

