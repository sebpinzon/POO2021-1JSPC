#include "persona.h"

Persona::Persona(){}

Persona::Persona(string nombre, string email, string celular, bool ubicacion, int id)
{
	this->nombre = nombre;
	this->email = email;
	this->celular = celular;
	this->ubicacion = ubicacion;
	this->id = id;
}

string Persona::getNombre()
{
	return nombre;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Persona::getUbicacion()
{
	string interno = "Interno", externo = "Externo";

	if (ubicacion == 0)
	{
		return interno;
	}
	else
	{
		return externo;
	}
}

void Persona::setUbicacion(bool ubicacion)
{
	this->ubicacion = ubicacion;
}

string Persona::getEmail()
{
	return email;
}

void Persona::setEmail(string email)
{
	this->email = email;
}

string Persona::getCelular()
{
	return celular;
}

void Persona::setCelular(string celular)
{
	this->celular = celular;
}

int Persona::getId()
{
	return id;
}

void Persona::setId(int id)
{
	this->id = id;
}