#include "Circulo.h"

//Inicializa la variable PI que es estática y constante
const float Circulo::PI = 3.1416;

//CONSTRUCTORES CIRCULO
Circulo::Circulo()
{
}

Circulo::Circulo(float radio) : Circulo()
{

    this->radio = radio;
}

//METODOS CIRCULO

void Circulo::calcularArea()
{
    
    this->area = PI * (radio * radio);
    
}

void Circulo::calcularPerimetro()
{
    
    this->perimetro = (2 * PI) * radio;
    
}

void Circulo::mostrarFigura()
{
	cout << "El radio: " << radio << endl;
    if (area == 0)
    {
        calcularArea();
    }
    if (perimetro == 0)
    {
        calcularPerimetro();
    }
    cout << "El perimetro: " << perimetro << " -- "
         << "el area: " << area << endl;
}

float Circulo::getRadio() const
{

    return this->radio;
}

void Circulo::setRadio(float radio)
{

    this->radio = radio;
}