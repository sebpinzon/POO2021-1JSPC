#include "Cliente.h"

//CONSTRUCTORES CLIENTE
Cliente::Cliente(string nombre, string email, int id, string telefono)
{
    this->nombre = nombre;
    this->email = email;
    this->id = id;
    this->telefono = telefono;
}

//METODOS CLIENTE

void Cliente::mostrarCliente()
{

    cout << "|===============================| \n";
    cout << " Nombre: " << this->nombre << endl;
    cout << " email: " << this->email << endl;
    cout << " Id: " << this->id << endl;
    cout << " telefono: " << this->telefono << endl;
}

string Cliente::getNombre()
{
    return this->nombre;
}