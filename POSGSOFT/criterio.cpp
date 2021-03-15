#include "criterio.h"

Criterio::Criterio(){}

Criterio::Criterio(string nombre,float ponderacion, float calificacionJurado1,float calificacionJurado2,string observacionJurado1,string observacionJurado2)
{
	this->nombre = nombre;
	this->ponderacion = ponderacion;
	this->calificacionJurado1 = calificacionJurado1;
	this->calificacionJurado2 = calificacionJurado2;
	this->observacionJurado1 = observacionJurado1;
	this->observacionJurado2 = observacionJurado2;
}

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

float Criterio::getCalificacionJurado1()
{
	return calificacionJurado1;
}

void Criterio::setCalificacionJurado1(float calificacionJurado1)
{
	this->calificacionJurado1 = calificacionJurado1;
}

float Criterio::getCalificacionJurado2()
{
	return calificacionJurado2;
}

void Criterio::setCalificacionJurado2(float calificacionJurado2)
{
	this->calificacionJurado2 = calificacionJurado2;
}

string Criterio::getObservacionJurado1()
{
	return observacionJurado1;
}
void Criterio::setObservacionJurado1(string observacionJurado1)
{
	this->observacionJurado1 = observacionJurado1;
}

string Criterio::getObservacionJurado2()
{
	return observacionJurado2;
}

void Criterio::setObservacionJurado2(string observacionJurado2)
{
	this->observacionJurado2 = observacionJurado2;
}

int Criterio::getId()
{
	return id;
}

void Criterio::setId(int id)
{
	this->id = id;
}