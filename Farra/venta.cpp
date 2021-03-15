#include "venta.h"

Venta::Venta(){}

Venta::Venta(string fecha,Cliente cliente, int id,)
{
	this->fecha = fecha;
	this->cliente = cliente;
	this->id = id;
}

void Venta::agregarDetalleVenta(DetalleVenta detalle_venta)
{
	listaDetalleVentas.push_back(detalle_venta);
}

void Venta::finalizarVenta()
{
	for (list<DetalleVenta>::iterator detalle_venta = listaDetalleVentas.begin(); detalle_venta != listaDetalleVentas.end(); detalle_venta++)
    {
        this->valorTotal = detalle_venta->getValor() + valorTotal;
        this->IVATotal = detalle_venta->getIVA() + IVATotal;
    }
}