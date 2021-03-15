all: compilar
compilar: producto cliente  detalle_venta venta menu tienda main
		g++ -o tienda producto.o cliente.o tienda.o menu.o main.o
cliente: cliente.cpp cliente.h
		g++ -c cliente.cpp
producto: producto.cpp producto.h
		g++ -c producto.cpp
detalle_venta: detalle_venta.cpp detalle_venta.h
		g++ -c detalle_venta.cpp
venta: venta.cpp venta.h
		g++ -c venta.cpp
tienda: tienda.cpp tienda.h
		g++ -c tienda.cpp
menu: menu.cpp menu.h
		g++ -c menu.cpp
main: main.cpp menu.h tienda.h producto.h 
	  g++ -c main.cpp
clean: 
	delete producto.o Cliente.o tienda.o menu.o main.o detalle_venta.o venta.o