#include <iostream>
#include "circulo.h"
#include "rectangulo.h"
#include "triangulo.h"

Rectangulo crearRectangulo()
{
	float l, a;
	std::cout << "Largo del rectangulo:" << std::endl;
	std::cin >> l;
	std::cout << "Ancho del rectangulo:" << std::endl;
	std::cin >> a;
	Rectangulo RE(l,a);
	std::cout << "\nRectangulo creado ... \n" << std::endl;
	return RE;
}

Circulo crearCirculo()
{
	float r;
	std::cout << "Radio del circulo:" << std::endl;
	std::cin >> r;
	Circulo CI(r);
	std::cout << "\nCirculo creado ... \n" << std::endl;
	return CI;
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
	std::cout << "\nTriangulo creado ... \n" << std::endl;
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
		std::cout << "1.Crear rectangulo" << "\n" << "2.Crear circulo" << "\n" << "3.Crear triangulo" << "\n" << "4.Salir\n" << "Opcion: ";
		std::cin >> OPC;
		std::cout << "\n" << std::endl; 

		switch(OPC)
		{
			case 1: 
			{
				try {
					if (count_R == 9)
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