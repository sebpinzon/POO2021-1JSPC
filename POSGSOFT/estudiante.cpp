#include "estudiante.h"

Estudiante::Estudiante(){}

Estudiante::Estudiante(string nombre, int id,string enfasis, string email)
{
	this->nombre = nombre;
	this->id = id;
	this->enfasis = enfasis;
	this->email = email;
}

string Estudiante::getNombre()
{
	return this->nombre;
}

void Estudiante::setNombre(string nombre)
{
	this->nombre = nombre;
}

int Estudiante::getId()
{
	return this->id;
}

void Estudiante::setId(int id)
{
	this->id = id;
}

string Estudiante::getEnfasis()
{
	return this->enfasis;
}

void Estudiante::setEnfasis(string enfasis)
{
	this->enfasis = enfasis;
}

string Estudiante::getEmail()
{
	return this->email;
}

void Estudiante::setEmail(string email)
{
	this->email = email;
}