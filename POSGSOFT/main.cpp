#include <iostream>
#include "acta.h"

using std::getline;

int menu()
{
	int opcion;
	cout << "1. Modificar acta" << endl;
	cout << "2. Crear acta" << endl;
	cout << "3. Listar actas" << endl;
	cout << "4. Salir" << endl;
	cout << "Opcion: ";
	cin >> opcion;
	return opcion;
}

void clean()
{
	system("clear");
	system("cls");
}

Persona modificarPersona(Persona persona)
{
	bool stop = true;
	string nombre,email,celular;
	bool ubicacion;
	int id,selector;
	clean();
	while(stop)
	{
		cout << "1. Modificar Nombre" << endl;
		cout << "2. Modificar Ubicacion" << endl;
		cout << "3. Modificar Email" << endl;
		cout << "4. Modificar Celular" << endl;
		cout << "5. Modificar Id" << endl;
		cout << "6. Mostrar perfil" << endl;
		cout << "7. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;

		cout << "\n" << endl;
		try{
			if ((selector >= 8) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
					cout << "\n" << endl;
					cout << "Nombre actual: " << persona.getNombre() << endl;
					cout << "Nombre nuevo: ";
					getline(cin,nombre);
					getline(cin,nombre);
					persona.setNombre(nombre);
				}
				break;
				case 2:
				{
					clean();
					cout << "\n" << endl;
					cout << "Ubicacion actual: " << persona.getUbicacion() << endl;
					cout << "Ubicacion nuevo(1.Extreno 2.Interno): ";
					cin >> ubicacion;
					persona.setUbicacion(ubicacion);
				}
				break;
				case 3:
				{
					clean();
					cout << "\n" << endl;
					cout << "Email actual: " << persona.getEmail() << endl;
					cout << "Email nuevo: ";
					cin >> email;
					persona.setEmail(email);
				}
				break;
				case 4:
				{
					clean();
					cout << "\n" << endl;
					cout << "Celular actual: " << persona.getCelular() << endl;
					cout << "Celular nuevo: ";
					cin >> celular;
					persona.setCelular(email);
				}
				break;
				case 5:
				{
					clean();
					cout << "\n" << endl;
					cout << "Id actual: " << persona.getId() << endl;
					cout << "Id nuevo: ";
					cin >> id;
					persona.setId(id);
				}
				break;
				case 6:
				{
					clean();
					persona.mostrarPersona();
				}
				break;
				case 7:
				{
					stop = false;
				}
				break;
			}
		}
		catch(int selector)
		{
			cout << "Seleccione una opcion valida\n" << endl;
		}
	}
	return persona;
}

list<Criterio> modificarCriterios(list<Criterio> listaCriterios)
{
	bool stop = true;
	string nombre;
	float calificacionJurado1,calificacionJurado2,ponderacion;
	string observacionJurado1,observacionJurado2;
	int id=1,opcion,selector;
	clean();
	cout << "Criterios actuales:" <<endl;
	cout << "\n" << endl;
	list<Criterio>::iterator criterio = listaCriterios.begin();
	for (criterio ; criterio != listaCriterios.end() ; criterio++)
	{
		cout << id << "." ;
		criterio->getNombre();
		cout << "\n" << endl;
		id++;
	}
	cout << "Criterio: ";
	cin >> opcion;

	indice=1;

	criterio = listaCriterios.begin();
	while(criterio != listaCriterios.end())
	{
		if (indice == opcion)
		{
			break;
		}
		indice++;
		criterio++;
	}

	nombre = criterio->getNombre();
	calificacionJurado1 = criterio->getCalificacionJurado1();
	calificacionJurado2 = criterio->getCalificacionJurado2();
	ponderacion = criterio->getPonderacion();
	observacionJurado1 = criterio->getObservacionJurado1();
	observacionJurado2 = criterio->getObservacionJurado2();
	id = criterio->getId();

	while(stop)
	{
		cout << "1. Modificar Nombre" << endl;
		cout << "2. Modificar calificacion jurado 1" << endl;
		cout << "3. Modificar calificacion jurado 2" << endl;
		cout << "4. Modificar ponderacion del criterio" << endl;
		cout << "5. Modificar observacion del jurado 1" << endl;
		cout << "6. Mostrar observacion del jurado 2" << endl;
		cout << "7. Modificar Id" << endl;
		cout << "8. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;

		cout << "\n" << endl;
		try{
			if ((selector >= 9) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
					cout << "Nombre del criterio actual: " << endl;
					cout << nombre << endl;
					cout << "Nombre nuevo del criterio: ";
					getline(cin,nombre);
					getline(cin,nombre);
					criterio.setNombre(nombre);
				}
				break;
				case 2:
				{
					clean();
					cout << "\n" << endl;
					cout << "Ubicacion actual: " << criterio.getUbicacion() << endl;
					cout << "Ubicacion nuevo(1.Extreno 2.Interno): ";
					cin >> ubicacion;
					criterio.setUbicacion(ubicacion);
				}
				break;
				case 3:
				{
					clean();
					cout << "\n" << endl;
					cout << "Email actual: " << criterio.getEmail() << endl;
					cout << "Email nuevo: ";
					cin >> email;
					criterio.setEmail(email);
				}
				break;
				case 4:
				{
					clean();
					cout << "\n" << endl;
					cout << "Celular actual: " << criterio.getCelular() << endl;
					cout << "Celular nuevo: ";
					cin >> celular;
					criterio.setCelular(email);
				}
				break;
				case 5:
				{
					clean();
					cout << "\n" << endl;
					cout << "Id actual: " << criterio.getId() << endl;
					cout << "Id nuevo: ";
					cin >> id;
					criterio.setId(id);
				}
				break;
				case 6:
				{
					clean();
					criterio.mostrarPersona();
				}
				break;
				case 7:
				{
					stop = false;
				}
				break;
			}
		}
		catch(int selector)
		{
			cout << "Seleccione una opcion valida\n" << endl;
		}
	}
	return persona;
}
list<Acta> modificarActa(list<Acta> actas)
{
	int opcion,indice=1,selector=0;
	bool stop = true;
	Acta acta_modificar;
	Persona estudiante,codirector,director,jurado1,jurado2;
	list<Critrio> listaCriterios;
	list<Acta>::iterator acta = actas.begin();
	for (acta ; acta != actas.end() ; acta++)
	{
		Persona estudiante = acta->getEstudiante();
		cout << indice++ << "." << "Numero de acta: " << acta->getNumeroActa() << "     " << "Nombre de autor: " << estudiante.getNombre() << "     " << "Estado: " << acta->getEstado() << endl;
	}
	cout << "Acta: ";
	cin >> opcion;

	indice=1;

	acta = actas.begin();
	while(acta != actas.end())
	{
		if (indice == opcion)
		{
			break;
		}
		indice++;
		acta++;
	}

	estudiante = acta->getEstudiante();
	codirector = acta->getCodirector();
	director = acta->getDirector();
	jurado1 = acta->getJurado1();
	jurado2 = acta->getJurado2();
	listaCriterios = acta->getListaCriterios();


	while(stop)
	{
		cout << "1. Modificar Estudiente" << endl;
		cout << "2. Modificar Director" << endl;
		cout << "3. Modificar Codirector" << endl;
		cout << "4. Modificar Jurado 1" << endl;
		cout << "5. Modificar Jurado 2" << endl;
		cout << "6. Modificar Criterios" << endl;
		cout << "7. Modificar Observaciones" << endl;
		cout << "8. Modificar Estado del acta" << endl;
		cout << "9. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;

		cout << "\n" << endl;
		try{
			if ((selector >= 10) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
			case 1:
			{
				estudiante=modificarPersona(estudiante);
				acta->setEstudiante(estudiante);
			}
			break;
			case 2:
			{
				director=modificarPersona(director);
				acta->setDirector(director);
			}
			break;
			case 3:
			{
				codirector=modificarPersona(codirector);
				acta->setCodirector(codirector);
			}
			break;
			case 4:
			{
				jurado1=modificarPersona(jurado1);
				acta->setJurado1(jurado1);
			}
			break;
			case 5:
			{
				jurado2=modificarPersona(jurado2);
				acta->setJurado2(jurado2);
			}
			break;
			case 6:
			{
				listaCriterios = modificarCriterios(listaCriterios);
				acta->setListaCriterios(listaCriterios);

			}
			break;
			case 7:
			{
				
			}
			break;
			case 8:
			{
				
			}
			break;
			case 9:
			{
				stop = false;
			}
			break;
			}
		}
		catch(int selector)
		{
			cout << "Seleccione una opcion valida\n" << endl;
		}
	}

	return actas;
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
		cout << "\n" << endl;
		try{
			if ((opcion >= 5) || (opcion == 0))
			{
				throw (opcion);
			}
			
			switch (opcion)
			{
			case 1:
			{
				actas = modificarActa(actas);
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
				
			}
			break;
			case 4:
			{
				
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