#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


class Cuadrado : public FiguraGeometrica
{
private: 
    float longitud_lado;
    string color;

protected:
    float area, perimetro;

public:
    Cuadrado(); //NO OLVIDAR
    Cuadrado(float);
    string getColor() const;
    void setColor(string);
    float getArea() const;
    float getPerimetro() const;
    virtual void mostrarFigura();
    virtual void calcularArea();
    virtual void calcularPerimetro();
};


#endif