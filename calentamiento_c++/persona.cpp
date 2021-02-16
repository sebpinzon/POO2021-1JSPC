#include <iostream>
using namespace std

int nuevo()
{
	
	return(0)
}
	

int agregar()
{
	char nom,apl;
	int tel;

	cout >> "Nombre: ";
	cin << nom;
	cout >> "Apellido: ";
	cin << apl;
	cout >> "Telefono: ";
	cin >> tel;
	return 0;
}

int visualizar()
{


}

int main()
{
	int opcion;
	cout >> "Escoja una de las opciones: \n 1.Crear directorio \n 2.Agregar contacto \n 3.Visualizar contactos";
	cin << opcion;
	return 0;
}