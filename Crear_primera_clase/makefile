all: compilar
compilar: circulo rectangulo triangulo main
	g++ -o salida circulo.o rectangulo.o triangulo.o main.o
circulo: circulo.cpp circulo.h
	g++ -c circulo.cpp
rectangulo: rectangulo.cpp rectangulo.h
	g++ -c rectangulo.cpp
triangulo: triangulo.cpp triangulo.h
	g++ -c triangulo.cpp
main: main.cpp rectangulo.h triangulo.h circulo.h
	g++ -c main.cpp