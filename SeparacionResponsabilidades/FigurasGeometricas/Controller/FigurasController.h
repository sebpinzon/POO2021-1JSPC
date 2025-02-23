//#ifndef FIGURAS_CONTROLLER_H
// Guardas
#include "../Model/Circulo.h"
#include "../Model/Triangulo.h"
#include "../Model/Rectangulo.h"

#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

class FigurasController
{
private:
    //constante y estático para declararla constante para todos los objetos.
    const static int MAX_ITEMS;
    list<Rectangulo> listaRectangulo;
    list<Circulo> listaCirculo;
    list<Triangulo> listaTriangulo;

public:
    // Retorna referencia a la lista de rectangulos
    list<Rectangulo> &getListaRectangulo();
    void agregarRectagulo(float largo, float ancho);

    // TO-DO

    list<Rectangulo> &getListaCirculo();
    void agregarTriagulo(float base, float altura);
    void agregarCirculo(float radio);
};
//#define FIGURAS_CONTROLLER_H