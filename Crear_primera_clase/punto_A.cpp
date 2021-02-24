#include <iostream>
#include <string>


class Circulo
{
	private:
		float RADIO, PI=3.14;

	public:
		Circulo();
		Circulo(float);
		float getRadio();
		void setRadio(float);
		float calcularArea();
		float calcularPerimetro();

};

Circulo::Circulo()
{
	this->RADIO = 0;
}

Circulo::Circulo(float RADIO)
{
	this->RADIO = RADIO;
}

float Circulo::getRadio()
{
	return this->RADIO;
}

void Circulo::setRadio(float RADIO)
{
	this->RADIO = RADIO;
}

float Circulo::calcularArea()
{
	float a,b,c;
	a = this->RADIO;
	b = this->PI;
	c = b * (a*a);
	return c;
}

float Circulo::calcularPerimetro()
{
	float a,b,c;
	a = this->RADIO;
	b = this->PI;
	c = 2*a*b;
	return c;
}

int main()
{
	Circulo cir1(2), cir2(3);
	std::cout << "Area circulo1: "<< cir1.calcularArea() << std::endl;
	std::cout << "Perimetro circulo1: "<< cir1.calcularPerimetro() << std::endl;

	std::cout << "Area circulo2: "<< cir2.calcularArea() << std::endl;
	std::cout << "Perimetro circulo2: "<< cir2.calcularPerimetro() << std::endl;

	std::cout << "Radio circulo1: "<< cir1.getRadio() << std::endl;
	return 0;
}