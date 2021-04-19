#include "Rectangulo.h"

//CONSTRUCTORES RECTANGULO

Rectangulo::Rectangulo() {}

Rectangulo::Rectangulo(float ancho, float largo)
{

    this->ancho = ancho;
    this->largo = largo;
}

//METODOS RECTANGULO

void Rectangulo::calcularArea()
{
    this->area = largo * ancho;
    
}

void Rectangulo::calcularPerimetro()
{
    
    this->perimetro = (2 * largo) + (2 * ancho);
    
}

void Rectangulo::mostrarFigura()
{
    cout << "El ancho: " << ancho << " -- "
         << "el largo: " << largo << endl;
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

float Rectangulo::getAncho()
{
    return this->ancho;
}

float Rectangulo::getLargo()
{
    return this->largo;
}

void Rectangulo::setAncho(float ancho)
{
    this->ancho = ancho;
}
void Rectangulo::setLargo(float largo)
{
    this->largo = largo;
}
