#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// CLASE PRODUCTO

class Producto
{
private:
    string marca;
    string tipoProducto;
    int codigoProducto;
    int existencia;
    float valorProducto,valorIVA;

public:
    Producto();
    Producto(string, string, int, int, float,float);
    void mostrarProducto();
    int getCodigoProducto();
    float getValor();
    float getIVA();
};

#endif