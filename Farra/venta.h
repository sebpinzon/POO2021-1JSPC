#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <list>
#include "cliente.h"
#include "detalle_venta.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::list;

class Venta
{
	private:
		string fecha;
		float valorTotal, IVATotal;
		Cliente cliente;
		int id;
		list<DetalleVenta> listaDetalleVentas;
	public:
		Venta();
		Venta(string,Cliente,int);
		void agregarDetalleVenta(DetalleVenta);
		void finalizarVenta();
}


#endif