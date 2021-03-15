#ifndef TIENDA_H
#define TIENDA_H

#include "producto.h"
#include "cliente.h"
#include <iostream>
#include <list>

using std::list;

class Tienda
{
private:
    string nombre;
    string nombreDueno;
    int capClient;
    int capProducto;
    int cantidad_productos=0;
    int cantidad_clientes=0;
    int cantidad_ventas=0;
    list<Producto> listaProductos; //list<Clase> nombre_de_lista
    list<Cliente> listaCliente;

    void setDummyData(); //Datos de prueba.

public:
    Tienda();
    void setNombre();
    void setDueno();
    void mostrarTodosProducto();
    Producto buscarProducto(int);
    Cliente buscarCliente(string nombre);
    void mostrarTodosCliente();
    void agregarProducto();
    void agregarCliente();
    void vender();
};

#endif