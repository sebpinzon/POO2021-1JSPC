#include <iostream>
#include "rectangulo.h"


Rectangulo::Rectangulo()
{
	this->largo = 0;
	this->ancho = 0;
}

Rectangulo::Rectangulo(float largo, float ancho)
{
	this->largo = largo;
	this->ancho = ancho;
}

void Rectangulo::setLargo(float largo)
{
	this->largo = largo;
}

void Rectangulo::setAncho(float ancho)
{
	this->ancho = ancho;
}

float Rectangulo::getLargo()
{
	return this->largo;
}

float Rectangulo::getAncho()
{
	return this->ancho;
}

float Rectangulo::calcularPerimetro()
{
	float perimetro;
	perimetro = (2*largo) + (2*ancho);
	return perimetro;
}

float Rectangulo::calcularArea()
{
	float area;
	area = largo*ancho;
	return area;
}