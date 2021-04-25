#include "Cuadrado.h"

Cuadrado::Cuadrado()
    : color("Rojo"), area(0.0), perimetro(0.0)
{
}
Cuadrado::Cuadrado(float lado)
    : Cuadrado()
{
    this->longitud_lado = lado;
}

// Getters y setters
string Cuadrado::getColor() const
{
    return this->color;
}
void Cuadrado::setColor(string color)
{
    this->color = color;
}

float Cuadrado::getArea() const
{
    return this->area;
}

float Cuadrado::getPerimetro() const
{
    return this->perimetro;
}

void Cuadrado::mostrarFigura();
{
    cout << "Color" << color << endl;
}

void calcularArea()
{
	this->area = (this->longitud_lado)*(this->longitud_lado);
}
void calcularPerimetro()
{
	this->perimetro = 4*longitud_lado;
}
