#include <iostream>
#include "circulo.h"

Circulo::Circulo()
{
	this->RADIO = 0;
}

Circulo::Circulo(float RADIO)
{
	this->RADIO = RADIO;
}

float Circulo::getRadio()
{
	return this->RADIO;
}

void Circulo::setRadio(float RADIO)
{
	this->RADIO = RADIO;
}

float Circulo::calcularArea()
{
	float a,b,c;
	a = this->RADIO;
	b = this->PI;
	c = b * (a*a);
	return c;
}

float Circulo::calcularPerimetro()
{
	float a,b,c;
	a = this->RADIO;
	b = this->PI;
	c = 2*a*b;
	return c;
}
