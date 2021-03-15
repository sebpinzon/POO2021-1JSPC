#include <iostream>
#include "acta.h"

int menu()
{
	int opcion;
	cout << "1. Modificar acta" << endl;
	cout << "2. Crear acta" << endl;
	cout << "3. Listar actas" << endl;
	cout << "4. Salir" << endl;
	cout << "Opcion: " << endl;
	cin >> opcion;
	return opcion;
}

void clean()
{
	system("clear");
	system("cls");
}

int modificarActaMenu(list<Acta> actas)
{
	int opcion;
	for (list<Acta>::iterator acta = actas.begin() ; actas != listaCriterios.end() ; actas++)
	{
		Persona estudiante = acta->getEstudiante();
		cout << "Numero de acta: " << acta->getNumeroActa() << "     " << "Nombre de autor: " << estudiante.getNombre() << "     " << "Estado: " << acta->getEstado() << endl;
	}
	cout << "Acta: " << endl;
	cin >> opcion;

	return opcion;
}

Acta crearActa()
{
	Acta nueva;
	cout << "Nueva acta creada...\n" << endl;
	return nueva;
}

void listarActas()
{

}

int main()
{
	int opcion,selector_acta;
	bool stop=true;
	clean();

	list<Acta> actas;
	while(stop)
	{
		opcion = menu();
		try{
			if ((opcion >= 5) || (opcion == 0))
			{
				throw (opcion);
			}
			
			switch (opcion)
			{
			case 1:
			{
				selector_acta = modificarActaMenu(list<Acta> actas);
			}
			break;
			case 2:
			{
				Acta nueva=crearActa();
				actas.push_back(nueva);
			}
			break;
			case 3:
			{
				s
			}
			break;
			case 4:
			{
				s
			}
			break;
			}
		}
		catch(int opcion)
		{
			cout << "Seleccione una opcion valida\n" << endl;
		}
		
	}
	
	
	return 0;
}