#include <iostream>
#include <string>
#include <math.h>


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

class Triangulo
{
	private:
		float LADO_A, LADO_B, LADO_C;
		float ANGU_A_B, ANGU_B_C, ANGU_C_A;
	public:
		Triangulo();
		Triangulo(float, float, float,float,float,float);
		float calcularArea();
		float calcularPerimetro();
		float getLado();
		void setLado(float);
		float getAngulo();
		void setAngulo(float);
};

Triangulo::Triangulo()
{
	this->LADO_A = 0;
	this->LADO_B = 0;
	this->LADO_C = 0;
	this->ANGU_A_B = 0;
	this->ANGU_B_C = 0;
	this->ANGU_C_A = 0;
}

Triangulo::Triangulo(float LADO_A, float LADO_B, float LADO_C, float ANGU_A_B, float ANGU_B_C, float ANGU_C_A)
{
	this->LADO_A = LADO_A;
	this->LADO_B = LADO_B;
	this->LADO_C = LADO_C;
	this->ANGU_A_B = ANGU_A_B;
	this->ANGU_B_C = ANGU_B_C;
	this->ANGU_C_A = ANGU_C_A;
}

void Triangulo::setLado(float value)
{
	int OPC;
	std::cout << "1.Lado A" << "2.Lado B" << "3.Lado C" << std::endl;
	std::cin >> OPC;
	if (OPC == 1)
	{
		this->LADO_A = value;
	}
	else if (OPC == 2)
	{
		this->LADO_B = value;	
	}
	else if (OPC == 3)
	{
		this->LADO_C = value;	
	}
	else
	{
		std::cout << "Lado no valido"<< std::endl;
	}
	
}

void Triangulo::setAngulo(float value)
{
	int OPC;
	std::cout << "1.Angulo A-B" << "2.Angulo B-C" << "3.Angulo C-A" << std::endl;
	std::cin >> OPC;
	if (OPC == 1)
	{
		this->ANGU_A_B = value;
	}
	else if (OPC == 2)
	{
		this->ANGU_B_C = value;	
	}
	else if (OPC == 3)
	{
		this->ANGU_C_A = value;	
	}
	else
	{
		std::cout << "Angulo no valido"<< std::endl;
	}
}

float Triangulo::getLado()
{
	int OPC;
	float S;
	std::cout << "1.Lado A" << "2.Lado B" << "3.Lado C" << std::endl;
	std::cin >> OPC;
	if (OPC == 1)
	{
		S=this->LADO_A;
	}
	else if (OPC == 2)
	{
		S=this->LADO_B;	
	}
	else if (OPC == 3)
	{
		S=this->LADO_C;	
	}
	else
	{
		std::cout << "Lado no valido"<< std::endl;
	}

	return S;
}

float Triangulo::getAngulo()
{
	int OPC;
	float S;
	std::cout << "1.Angulo A-B" << "2.Angulo B-C" << "3.Angulo C-A" << std::endl;
	std::cin >> OPC;
	if (OPC == 1)
	{
		S=this->ANGU_A_B;
	}
	else if (OPC == 2)
	{
		S=this->ANGU_B_C;	
	}
	else if (OPC == 3)
	{
		S=this->ANGU_C_A;	
	}
	else
	{
		std::cout << "Angulo no valido"<< std::endl;
	}

	return S;
}

float Triangulo::calcularPerimetro()
{
	float perimetro;
	perimetro = LADO_A+LADO_B+LADO_C;
	return perimetro;
}

float Triangulo::calcularArea()
{
	float perimetro, s, area;
	perimetro = calcularPerimetro();
	s = perimetro/2;
	area = sqrt(s*(s-LADO_A)*(s-LADO_B)*(s-LADO_C));
	return area;
}

Triangulo crearTriangulo()
{
	float L_a, L_b, L_c;
	float A_a_b, A_b_c, A_c_a;
	std::cout << "A " << "/" << "\\" << "B" << std::endl;
	std::cout << "  __ " << std::endl;
	std::cout << "  C " << std::endl;
	std::cout << "Lado A del Triangulo:" << std::endl;
	std::cin >> L_a;
	std::cout << "Lado B del Triangulo:" << std::endl;
	std::cin >> L_b;
	std::cout << "Lado C del Triangulo:" << std::endl;
	std::cin >> L_c;
	std::cout << "Angulo entre A y B:" << std::endl;
	std::cin >> A_a_b;
	std::cout << "Angulo entre B y C:" << std::endl;
	std::cin >> A_b_c;
	std::cout << "Angulo entre C y A:" << std::endl;
	std::cin >> A_c_a;
	Triangulo TRI(L_a, L_b, L_c, A_a_b, A_b_c, A_c_a);
	return TRI;
}



int main()
{
	int SIZE=10, OPC=0, count_R=0, count_C=0, count_T=0;
	bool STOP = true;
	
	Circulo CIR;
	Rectangulo REC;
	Triangulo TRI;
	Circulo circulos[SIZE];
	Rectangulo rectangulos[SIZE];
	Triangulo triangulos[SIZE];


	while(STOP)
	{
		std::cout << "1.Crear rectangulo" << "\n" << "2.Crear circulo" << "\n" << "3.Crear triangulo" << "\n" << "4.Salir\n" << std::endl;
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
				try{
					if (count_T >= 9)
					{
						throw (count_T);
						break;
					}
					TRI = crearTriangulo();
					triangulos[count_T] = TRI;
					count_T++;				
					
				}
				catch(int count_T)
				{
					std::cout << "No hay más espacio para guardar Triangulos\n" << std::endl;
				}
				
			}
			break;
			case 4:
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