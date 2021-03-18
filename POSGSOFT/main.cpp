#include <iostream>
#include <fstream>
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
					cout << "Ubicacion nuevo(1.Extreno 0.Interno): ";
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
	DetalleCriterio detalle;
	float calificacionJurado1,calificacionJurado2,ponderacion;
	string observacion;
	int id,opcion,selector,indice;
	clean();
	cout << "Criterios actuales(si no hay,seleccione 0):" <<endl;
	cout << "\n" << endl;
	list<Criterio>::iterator criterio = listaCriterios.begin();
	for (criterio ; criterio != listaCriterios.end() ; criterio++)
	{
		cout << criterio->getId() << ". " << criterio->getNombre();		
		cout << "\n" << endl;
	}
	cout << "Criterio: ";
	cin >> opcion;

	if (opcion == 0)
	{
		cout << "Agrege un criterio, se recomienda seleccionar la opcion 8." <<endl;
	}

	if (opcion != 0)
	{
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

		detalle = criterio->getDetalle();
	}

	

	while(stop)
	{
		cout << "1. Modificar Nombre" << endl;
		cout << "2. Modificar calificacion jurado 1" << endl;
		cout << "3. Modificar calificacion jurado 2" << endl;
		cout << "4. Modificar ponderacion del criterio" << endl;
		cout << "5. Modificar observacion" << endl;
		cout << "6. Modificar Id" << endl;
		cout << "7. Agregar criterio" << endl;
		cout << "8. Eliminar criterio" << endl;
		cout << "9. Salir" << endl;
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
					cout << "Nombre del criterio actual: " << criterio->getNombre() << "\n" << endl;
					cout << "Nombre nuevo del criterio: ";
					getline(cin,nombre);
					getline(cin,nombre);
					criterio->setNombre(nombre);
				}
				break;
				case 2:
				{
					clean();
					cout << "Calificacion del jurado 1 actual: " << detalle.getCalificacionJurado1() << endl;
					cout << "Calificacion del jurado 1 nueva: ";
					cin >> calificacionJurado1;
					detalle.setCalificacionJurado1(calificacionJurado1);
				}
				break;
				case 3:
				{
					clean();
					cout << "Calificacion del jurado 2 actual: " << detalle.getCalificacionJurado2() << endl;
					cout << "Calificacion del jurado 2 nueva: ";
					cin >> calificacionJurado2;
					detalle.setCalificacionJurado2(calificacionJurado1);
				}
				break;
				case 4:
				{
					clean();
					cout << "Ponderacion actual: " << criterio->getPonderacion() << endl;
					cout << "Ponderacion nueva(numero entre 0 y 1 ): ";
					cin >> ponderacion;
					criterio->setPonderacion(ponderacion);
				}
				break;
				case 5:
				{
					clean();
					cout << "Observacion actual: " << detalle.getObservacion() << endl;
					cout << "Observacion nueva: ";
					cin >> observacion;
					detalle.setObservacion(observacion);
				}
				break;
				case 6:
				{
					clean();
					cout << "Id del criterio actual: " << criterio->getId() << endl;
					cout << "Id nuevo: ";
					cin >> id;
					criterio->setId(id);
				}
				break;
				case 7:
				{
					Criterio nuevo;
					listaCriterios.push_back(nuevo);
					cout << "Nuevo criterio agregado" << endl;
				}
				break;
				case 8:
				{
					stop = false;
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
	criterio->setDetalle(detalle);
	return listaCriterios;
}

string modificarObservacionGeneral(string observacion_general)
{
	bool stop = true;
	int general=1,opcion,selector,indice;
	string observacion;
	clean();
	cout << "Observacion general actual: " << endl;
	cout << observacion_general << endl;
	cout << "\n" << endl;
	
	while(stop)
	{
		cout << "1. Modificar observacion general" << endl;
		cout << "2. Ver observacion general" << endl;
		cout << "3. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;

		cout << "\n" << endl;
		try{
			if ((selector >= 4) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
					cout << "Observacion general actual: " << endl;
					cout << observacion_general << endl;
					cout << "Observacion general nueva: ";
					getline(cin,observacion);
					getline(cin,observacion);
				}
				break;
				case 2:
				{
					clean();
					cout << "Observacion general actual: " << endl;
					cout << observacion << endl;
				}
				break;
				case 3:
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
	return observacion;
}

string modificarObservacionAprovacion(string observacion_aprobacion)
{
	bool stop = true;
	int general=1,aprovacion=2,opcion,selector,indice;
	string observaciones;
	clean();
	cout << "Observacion de aprovacion actual: " <<endl;
	cout << observacion_aprobacion << endl;
	cout << "\n" << endl;
	
	while(stop)
	{
		cout << "1. Modificar observacion de aprovacion" << endl;
		cout << "2. Ver observacion de aprovacion" << endl;
		cout << "3. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;

		cout << "\n" << endl;
		try{
			if ((selector >= 4) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
					cout << "Observacion de aprovacion general actual: " << endl;
					cout << observaciones << endl;
					cout << "Observacion de aprovacion general nueva: ";
					getline(cin,observaciones);
					getline(cin,observaciones);
				}
				break;
				case 2:
				{
					clean();
					cout << "Observacion de aprovacion actual: " <<endl;
					cout << observacion_aprobacion << endl;
				}
				break;
				case 3:
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
	return observaciones;
}

int modificarNumeroActa(int numero_acta)
{
	bool stop = true;
	int nuevo=numero_acta,selector;
	clean();
	
	while(stop)
	{
		
		cout << "Numero de acta actual: ";
		cout << nuevo << endl;
		cout << "\n" << endl;
		cout << "1. Modificar Numero de Acta" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;

		cout << "\n" << endl;
		try{
			if ((selector >= 4) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
					cout << "Numero de acta actual: " << endl;
					cout << nuevo << endl;
					cout << "Numero de acta nuevo: ";
					cin >> nuevo;
				}
				break;
				case 2:
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
	return nuevo;
}

string modificarFechaActa(string fecha)
{
	bool stop = true;
	string nuevo=fecha;
	int selector;
	clean();
	
	while(stop)
	{
		cout << "Fecha acta actual: " ;
		cout << nuevo << endl;
		cout << "\n" << endl;
		cout << "1. Modificar Fecha de Acta" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;

		cout << "\n" << endl;
		try{
			if ((selector >= 4) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
					cout << "Fecha de acta actual: " << endl;
					cout << nuevo << endl;
					cout << "Fecha de acta nuevo: ";
					cin >> nuevo;
				}
				break;
				case 2:
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
	return nuevo;
}

string modificarPeriodoActa(string periodo)
{
	bool stop = true;
	int selector;
	string nuevo=periodo;
	clean();
	
	while(stop)
	{
		
		cout << "Periodo acta actual: " <<endl;
		cout << nuevo << endl;
		cout << "\n" << endl;
		cout << "1. Modificar Periodo de Acta" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;

		cout << "\n" << endl;
		try{
			if ((selector >= 3) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
					cout << "Periodo de acta nuevo: ";
					cin >> nuevo;
				}
				break;
				case 2:
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
	return nuevo;
}

string modificarEnfasisActa(string enfasis)
{
	bool stop = true;
	int selector;
	string nuevo=enfasis;
	
	while(stop)
	{
		clean();
		cout << "Enfasis acta actual: " <<endl;
		cout << nuevo << endl;
		cout << "\n" << endl;
		cout << "1. Modificar Enfasis de Acta" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;

		cout << "\n" << endl;
		try{
			if ((selector >= 3) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
					cout << "Enfasis de acta nuevo: ";
					cin >> nuevo;
				}
				break;
				case 2:
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
	return nuevo;
}

bool modificarModalidadActa(bool modalidad)
{
	bool stop = true, nuevo=modalidad;
	int selector;
	string mod;

	string aplicado = "Aplicado", investigado = "Investigado", nd = "No determinada";
	
	while(stop)
	{
		if (nuevo == 1)
		{
			mod = aplicado;
		}
		else if (nuevo == 0)
		{
			mod = aplicado;
		}
		else
		{
			mod = nd;
		}

		clean();
		cout << "Modalidad acta actual: " <<endl;
		cout << mod << endl;
		cout << "\n" << endl;
		cout << "1. Modificar Modalidad de Acta" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;

		cout << "\n" << endl;
		try{
			if ((selector >= 3) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
					cout << "1.Aplicada - 0.Investigado";
					cout << "Modalidad nueva: ";
					cin >> nuevo;
				}
				break;
				case 2:
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
	return nuevo;
}

bool modificarEstadoActa(bool estado)
{
	bool stop = true, nuevo=estado;
	int selector;
	string mod;

	string activa = "Activa", cerrada = "Cerrada", nd = "No determinada";
	
	while(stop)
	{
		if (nuevo == 1)
		{
			mod = activa;
		}
		else if (nuevo == 0)
		{
			mod = cerrada;
		}
		else
		{
			mod = nd;
		}

		clean();
		cout << "Estado del acta actual: " <<endl;
		cout << mod << endl;
		cout << "\n" << endl;
		cout << "1. Modificar Estado de Acta" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;

		cout << "\n" << endl;
		try{
			if ((selector >= 3) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
					cout << "Recuerde que si el acta esta Activa puede modificarse,";
					cout << "una vez esta se cierre solo se podra visulizar.";
					cout << "1.Activa - 0.Cerrada";
					cout << "Modalidad nueva: ";
					cin >> nuevo;
				}
				break;
				case 2:
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
	return nuevo;
}

list<Acta> modificarActa(list<Acta> actas)
{
	int opcion,indice=1,selector=0;

	bool stop = true,modalidad,estado;
	Acta acta_modificar;
	int numero_acta,aprovacion,count_jurados=0,count_criterios=0;
	float nota_final;
	string fecha,periodo,enfasis;
	Persona estudiante,codirector,director,jurado1,jurado2;
	string observacion_general,observacion_aprobacion;
	list<Criterio> listaCriterios;
	list<string> listaObservaciones;

	list<Acta>::iterator acta = actas.begin();
	for (acta ; acta != actas.end() ; acta++)
	{
		if ( acta->getEstadoBin() == 1)
		{
			Persona estudiante = acta->getEstudiante();
			cout << indice++ << "." << "Numero de acta: " << acta->getNumeroActa() << "     " << "Nombre de autor: " << estudiante.getNombre() << "     " << "Estado: " << acta->getEstado() << endl;
		}
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
		cout << "1.  Modificar Estudiente" << endl;
		cout << "2.  Modificar Director" << endl;
		cout << "3.  Modificar Codirector" << endl;
		cout << "4.  Modificar Jurado 1" << endl;
		cout << "5.  Modificar Jurado 2" << endl;
		cout << "6.  Modificar Criterios" << endl;
		cout << "7.  Modificar Observacion general" << endl;
		cout << "8.  Modificar Observacion aprovacion" << endl;
		cout << "9.  Modificar Numero del acta" << endl;
		cout << "10. Modificar Fecha del acta" << endl;
		cout << "11. Modificar Periodo del acta" << endl;
		cout << "12. Modificar Enfasis del acta" << endl;
		cout << "13. Modificar Modalidad del acta" << endl;
		cout << "14. Calcular nota final" << endl;
		cout << "15. Modificar Estado del acta" << endl;
		cout << "16. Salir" << endl;
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
					observacion_general = modificarObservacionGeneral(acta->getObservacion());
					acta->setObservacion(observacion_general);
				}
				break;
				case 8:
				{
					observacion_aprobacion = modificarObservacionAprovacion(acta->getObservacionAprobacion());
					acta->setObservacionAprobacion(observacion_aprobacion);
				}
				break;
				case 9:
				{
					numero_acta = modificarNumeroActa(acta->getNumeroActa());
					acta->setNumeroActa(numero_acta);
				}
				break;
				case 10:
				{
					fecha = modificarFechaActa(acta->getFecha());
					acta->setFecha(fecha);
				}
				break;
				case 11:
				{
					periodo = modificarPeriodoActa(acta->getPeriodo());
					acta->setPeriodo(periodo);
				}
				break;
				case 12:
				{
					enfasis = modificarEnfasisActa(acta->getEnfasis());
					acta->setEnfasis(enfasis);
				}
				break;
				case 13:
				{
					modalidad = modificarModalidadActa(acta->getModalidadBin());
					acta->setModalidad(modalidad);
				}
				break;
				case 14:
				{
					acta->calcularNotaFinal();
					cout << "Nota final: " << acta->getNotaFinal() << endl;
					cout << "\n" << endl;
				}
				break;
				case 15:
				{
					estado = modificarEstadoActa(acta->getEstadoBin());
					acta->setEstado(estado);
					
				}
				break;
				case 16:
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
	Acta restore;
	list<Acta> actas;

	ifstream carga("db.dat",ios::binary);
	if(carga.is_open())
    {
    	while(carga)
    	{
    		carga.read((Acta*)&restore, sizeof(Acta));
    	}
    }
    carga.close();



	clean();
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