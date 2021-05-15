//
// Created by lufe0 on 7/05/2021.
//

#ifndef CASINO_MAYOR13_H
#define CASINO_MAYOR13_H


#include "Juego.h"
#include<cstdlib>
#include<ctime>

class Mayor13 : public Juego {

protected:
    int numeroCasino;
    int numeroJugador;
    int opcion;
    virtual float calcularResultado(float gonzosApostar) ;
public:
    virtual ~Mayor13();
    virtual float jugar(float gonzosApostar) ;

};


#endif //CASINO_MAYOR13_H
