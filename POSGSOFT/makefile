all: compilar
compilar: persona criterio acta detalle postgrado main
		g++ -o posgsoft persona.o criterio.o detalle_criterio.o acta.o postgrado.o main.o
persona: persona.cpp persona.h
		g++ -c persona.cpp
criterio: criterio.cpp criterio.h
		g++ -c criterio.cpp
acta: acta.cpp acta.h
		g++ -c acta.cpp
detalle: detalle_criterio.cpp detalle_criterio.h
		g++ -c detalle_criterio.cpp
postgrado: postgrado.cpp postgrado.h
		g++ -c postgrado.cpp
main: main.cpp postgrado.h
	g++ -c main.cpp
clean: 
	delete persona.o estudiante.o criterio.o acta.o main.o detalle_criterio.o postgrado.o