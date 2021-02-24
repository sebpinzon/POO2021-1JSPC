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


class Rectangulo
{
	private:
		float largo, ancho;
	
	public:
		Rectangulo();
		Rectangulo(float, float);
		float calcularPerimetro();
		float calcularArea();
		void setLargo(float);
		void setAncho(float);
		float getLargo();
		float getAncho();

};

Rectangulo::Rectangulo()
{
	this->largo = 0;
	this->ancho = 0;
}

Rectangulo::Rectangulo(float largo, float ancho)
{
	this->largo = largo;
	this->ancho = ancho;
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

float Rectangulo::calcularPerimetro()
{
	float perimetro;
	perimetro = (2*largo) + (2*ancho);
	return perimetro;
}

float Rectangulo::calcularArea()
{
	float area;
	area = largo*ancho;
	return area;
}

Rectangulo crearRectangulo()
{
	float l, a;
	std::cout << "Largo del rectangulo:" << std::endl;
	std::cin >> l;
	std::cout << "Ancho del rectangulo:" << std::endl;
	std::cin >> a;
	Rectangulo RE(l,a);
	return RE;
}

Circulo crearCirculo()
{
	float r;
	std::cout << "Radio del circulo:" << std::endl;
	std::cin >> r;
	Circulo CI(r);
	return CI;
}



int main()
{
	int SIZE=10, OPC=0, count_R=0, count_C=0;
	bool STOP = true;
	Rectangulo REC;
	Circulo CIR;
	Circulo circulos[SIZE];
	Rectangulo rectangulos[SIZE];


	while(STOP)
	{
		std::cout << "1.Crear rectangulo" << "\n" << "2.Crear circulo" << "\n" << "3.Salir\n" << std::endl;
		std::cin >> OPC;

		switch(OPC)
		{
			case 1: 
			{
				try {
					if (count_R >= 9)
					{
						throw (count_R);
						break;
					}
					REC = crearRectangulo();
					rectangulos[count_R] = REC;
					count_R++;
					
					
				}
				catch(int count_R)
				{
					std::cout << "No hay más espacio para guardar Rectangulos\n" << std::endl;
				}
				
			}
			break;
			case 2:
			{
				try{
					if (count_C >= 9)
					{
						throw (count_C);
						break;
					}
					CIR = crearCirculo();
					circulos[count_C] = CIR;
					count_C++;				
					
				}
				catch(int count_C)
				{
					std::cout << "No hay más espacio para guardar Circulos\n" << std::endl;
				}
				
			}
			break;
			case 3:
			{
				STOP = false;
				
			} 
			break;
			default: std::cout << "\n" << "Escoja de nuevo..." << "\n" << std::endl;
			break;
		}

	}

	return 0;
}