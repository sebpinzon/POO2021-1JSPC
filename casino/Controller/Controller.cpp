//
// Created by lufe0 on 7/05/2021.
//

#include "Controller.h"
#include "../Model/Mayor13.h"
#include "../Model/DosColores.h"

Controller::Controller() {
  this->casino = Casino();
  // Se agregan los juegos disponibles para el casino
  Mayor13 *juego1 = new Mayor13();
  DosColores *juego2 = new DosColores();
  casino.agregarJuego(juego1);
  casino.agregarJuego(juego2);

}
void Controller::agregarJugador(long id, string nombreJugador, double dinero)
{
    // Se agrega jugador solo si no existe con anticipacion
    if (casino.verExisteJugador(id) == false){
        // Se convierte el dinero a Gonzos
        double cantGonzos = casino.convertirPesosAGonzos(dinero);
        Jugador *pJugador = new Jugador (id, nombreJugador, cantGonzos);
        casino.agregarJugador(pJugador);

    }
    else {
        throw std::domain_error("El jugador con la identificacion recibida ya existe\n");
    }
}

bool Controller::jugar(int idJuego, long idJugador, float gonzosApostar) {

    float resultado,gonzos;

    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    if (idJuego > casino.consultarJuegos().size()){
        throw std::domain_error("NO existe el juego que desea jugar\n");
    }
    if (verPuedeContinuar(idJugador)== false){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    if (verSaldoGonzos(idJugador,gonzosApostar)== false){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    
    // Si no hay errores se inicia el juego
    int posJuego = idJuego -1; // Se corrige la posicion para acceder al juego
    Juego *pJuegoAJugar = casino.consultarJuegos().at(posJuego);

    // Consutlta al jugador, consulta los gonzos iniciales, juega y obtiene el resultado
    Jugador *pJugador = casino.consultarJugador(idJugador);
    gonzos = pJugador->getCantGonzos();
    resultado = pJuegoAJugar->jugar(gonzosApostar);

    // Actualiza el saldo del jugador con el resultado
    pJugador->actualizarGonzos(resultado);

    // Actualiza la cantidad de juegos jugados
    pJugador->aumentarJuegos();

    // Retorna verdadero si el jugador ganó y false si el jugador perdio
    if (pJugador->getCantGonzos() <= gonzos){
        return false;
    }
    else{
        return true;
    }
}

void Controller::verInfoJugador(long idJugador){
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    Jugador *pJugador = casino.consultarJugador(idJugador);
    pJugador->mostrarInfo();
}

bool Controller::verPuedeContinuar(int idJugador) {
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (casino.verExisteJugador(idJugador) == false) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe");
    }
    Jugador *pJugador = casino.consultarJugador(idJugador);
    if (pJugador->getCantGonzos() == 0) {
        return false;
    }
    return true;
}

bool Controller::verSaldoGonzos(int idJugador,float gonzosApostar) {
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    Jugador *pJugador = casino.consultarJugador(idJugador);
    if (pJugador->getCantGonzos() >= gonzosApostar) {
        return true;
    }
    return false;
}

void Controller::retirarJugador(long idJugador) {
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    
    casino.retirarJugador(idJugador);
}

void Controller::recargarGonzos(long idJugador) {
    // Consutlta al jugador
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    float recarga;
    int numeroJugador;
    Jugador *pJugador = casino.consultarJugador(idJugador);
    do {
        cout << "Ingrese el valor a recargar en miles de pesos: ";
        cin >> recarga;
        // Actualiza el saldo del jugador con el resultado
        srand(time(NULL));
        numeroJugador = 1+rand()%10;// numeros de 1 a 10
        if (numeroJugador > 5) {
            recarga = recarga * 2;
            pJugador->actualizarGonzos(recarga);
        }
        else{
            pJugador->actualizarGonzos(recarga);
        }
        cout << "Recarga exitosa ...";
    } while (recarga <= 0);
}

