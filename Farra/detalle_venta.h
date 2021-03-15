#ifndef DETALLE_VENTA_H
#define DETALLE_VENTA_H

#include <iostream>
#include "producto.h"

using std::cin;
using std::cout;
using std::endl;
using std::list;

class DetalleVenta
{
	private:
		Producto producto;
		float valorProductoVenta, valorIVA;
		int cantidadProducto;
	public:
		DetalleVenta();
		DetalleVenta(Producto, int);
		float getValor();
		float getIVA();
}


#endif