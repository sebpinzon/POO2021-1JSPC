#include "detalle_venta.h"

DetalleVenta::DetalleVenta(){}

DetalleVenta::DetalleVenta(Producto producto, int cantidad)
{
	float valor_final = producto.getValor() * cantidad;
	this->valorProductoVenta = valor_final;
	this->valorIVA = producto.getValor();
	this->cantidad = cantidad;
}

float getValor()
{
	return this->valorProductoVenta;
}

float getIVA()
{
	return this->valorIVA;
}