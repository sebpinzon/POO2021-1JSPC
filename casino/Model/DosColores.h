//
// Created by lufe0 on 8/05/2021.
//

#ifndef CASINO_DOSCOLORES_H
#define CASINO_DOSCOLORES_H

#include "Juego.h"
#include<cstdlib>
#include<ctime>


class DosColores:public Juego {

protected:
    float calcularResultado(float gonzosApostar,int& numeroJugador,int& numeroCasino,int& colorJugador,int& colorCasino);

public:
    float jugar(float gonzosApostar) override;
    virtual ~DosColores();

};


#endif //CASINO_DOSCOLORES_H
