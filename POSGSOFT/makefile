all: compilar
compilar: persona criterio acta main
		g++ -o posgsoft persona.o criterio.o acta.o main.o
persona: persona.cpp persona.h
		g++ -c persona.cpp
criterio: criterio.cpp criterio.h
		g++ -c criterio.cpp
acta: acta.cpp acta.h
		g++ -c acta.cpp
main: main.cpp acta.h
	g++ -c main.cpp
clean: 
	delete persona.o estudiante.o criterio.o acta.o main.o