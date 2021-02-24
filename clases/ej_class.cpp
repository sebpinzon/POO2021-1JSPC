#include <iostream>
#include <string>

using namespace std;

class Rectangulo
{
	private:
		float largo, ancho;
	
	public:
		Rectangulo(float, float); //Constructor
		void calcularPerimetro();
		void calcularArea();
		void setLargo(float);//cambiar valor del largo
		void setAncho(float);
		float getLargo();
		float getAncho();

};
//Asi se usa cuando cambio el nombre de las variables en los prameros
/*Rectangulo::Rectangulo(float largo1, float ancho1)
{
	//Inicializa las variables de instancia.
	largo = largo1;
	ancho = ancho1;
	cout << "Creado..." << endl;
}*/

//Usar "this" para no tener que cambiar el nombr de las variables
Rectangulo::Rectangulo(float largo, float ancho)
{
	//Inicializa las variables de instancia.
	this->largo = largo;
	this->ancho = ancho;
	cout << "\n" << "Creado..." << endl;
}

void Rectangulo::setLargo(float largo)
{
	this->largo = largo;
}

void Rectangulo::setAncho(float ancho)
{
	this->ancho = ancho;
}

float Rectangulo::getLargo()
{
	return this->largo;
}

float Rectangulo::getAncho()
{
	return this->ancho;
}

void Rectangulo::calcularPerimetro()
{
	float perimetro;
	perimetro = (2*largo) + (2*ancho);
	cout << "Perimetro: " << perimetro << endl;
}

void Rectangulo::calcularArea()
{
	float perimetro;
	perimetro = largo*ancho;
	cout << "Area: " << perimetro << endl;
}


int main() {
	float an, la;

	cout << "Ingrese ancho: ";
	cin >> an;
	cout << "Ingrese largo: ";
	cin >> la;
	Rectangulo myObj(la,an);  // Create an object of MyClass
	cout << myObj.getLargo() << endl;
	cout << myObj.getAncho() << endl;
	myObj.calcularArea();
	myObj.calcularPerimetro();
	myObj.setLargo(50);
	myObj.setAncho(50);
	cout << myObj.getLargo() << endl;
	cout << myObj.getAncho() << endl;
	myObj.calcularArea();
	myObj.calcularPerimetro();
    // Print attribute values
    //cout << myObj.largo << "\n";
    //cout << myObj.ancho << "\n";
	return 0;
}