#include <iostream>
#include <math.h>
#include "triangulo.h"

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