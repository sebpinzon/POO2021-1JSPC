//
// Created by lufe0 on 7/05/2021.
//

#include "Mayor13.h"

float Mayor13::jugar(float gonzosApostar) {
    srand(time(NULL));
    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    numeroJugador = 1+rand()%14;// numeros de 1 a 13
    do{
    cout << "Tu numero aleatorio es: "<< numeroJugador <<"\n";
    cout << "Desea retirarse o seguir con el juego?";
    cout << "Al retirarse perdera la mitad de la apuesta.";
    cout << "Al continuar se evaluara el resultado";
    cout << "1.Continuar 2.Retirarse ";
    cout << "Opcion: ";
    cin >> opcion;
	}
	while((opcion <= 0)||(opcion >= 3));

    float gonzosResulado = calcularResultado(gonzosApostar);
    return gonzosResulado;

    return 0;
}


float Mayor13::calcularResultado(float gonzosApostar) {
	srand(time(NULL));
	if (opcion == 1)
	{
		numeroCasino = 1+rand()%14;// numeros de 1 a 13
		cout << "Tu numero aleatorio es: "<< numeroJugador <<"\n" << "Numero casino: "<< numeroCasino << "\n";
		if (numeroJugador <= numeroCasino)
		{

			return -gonzosApostar;
		}
		else{
			return gonzosApostar*2;
		}
	}
	else{
		return gonzosApostar/2;
	}
}

Mayor13::~Mayor13() {

}
