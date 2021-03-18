#include "criterio.h"

Criterio::Criterio(){}

string Criterio::getNombre()
{
	return nombre;
}

void Criterio::setNombre(string nombre)
{
	this->nombre = nombre;
}

float Criterio::getPonderacion()
{
	return ponderacion;
}

void Criterio::setPonderacion(float ponderacion)
{
	this->ponderacion = ponderacion;
}
int Criterio::getId()
{
	return id;
}

void Criterio::setId(int id)
{
	this->id = id;
}

DetalleCriterio Criterio::getDetalle()
{
	return detalles;
}

void Criterio::setDetalle(DetalleCriterio detalles)
{
	this->detalles = detalles;
}