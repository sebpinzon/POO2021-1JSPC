#include "triangulo.h"

//CONSTRUCTORES TRIANGULO

Triangulo::Triangulo() {}

Triangulo::Triangulo(float base, float altura)
{

    this->base = base;
    this->altura = altura;
}

//METODOS TRIANGULO

void Triangulo::calcularArea()
{
    this->area = (this->base * this->altura) / 2;
}

void Triangulo::calcularPerimetro()
{
    float perimetro, temp;
    temp = base / 2;
    this->perimetro = 2 * ((sqrt((temp * temp)) + (altura * altura))) + base;
}
