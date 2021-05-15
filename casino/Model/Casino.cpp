
#include "Casino.h"

// Constructor que inicializa las ganancias y perdidas en cero
Casino::Casino() {
    cout <<"Inicialice casino";
    jugadoresMap.clear(); // Se limpian los jugadores del casino
}


void Casino::agregarJuego(Juego* juego) {
    juegosDisponibles.push_back(juego);
}



void Casino::agregarJugador(Jugador *pJugador) {
    cout << "Agrendo jugador..." << endl;
    jugadoresMap.insert(pair<long, Jugador*> (pJugador->getId(),pJugador));
}

bool Casino::verExisteJugador(long id) {

    // Si el jugador se encuentra en el mapa retorna true, de lo contrario retorna false
    jugadoresMap.at(id);
    if (jugadoresMap.count(id))
        return true;
    else
        return false;

}

Jugador* Casino::consultarJugador(long id) {
    return jugadoresMap[id]; // Retora el apuntador a jugador.
}

double Casino::convertirPesosAGonzos(double dinero) {

    // Cada 10 mil pesos equivalen a 100 Gonzos
    double conversion = (dinero*100)/10000;
    return conversion;
}

vector<Juego*> &Casino::consultarJuegos() {
    return juegosDisponibles;
}

void Casino::retirarJugador(long id) {
    // Remover jugador
    cout << "Eliminando jugador..." << endl;
    jugadoresMap.erase(id);
}


double Casino::convertirGonzosPesos(float gonzos) {
    // Pendiente por implementar
    double conversion = (gonzos*10000)/100;
    return conversion;
}

Casino::~Casino() {

}