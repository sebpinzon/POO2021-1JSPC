#include "postgrado.h"

Postgrado::Postgrado(){}


void Postgrado::clean()
{
	system("clear");
	system("cls");
}

void Postgrado::archivoTexto(list<Acta>::iterator acta) 
{
	clean();
	Persona estudiante,codirector,director,jurado1,jurado2;
	int opcion,indice=1,selector;
	string numero_acta = to_string(acta->getNumeroActa());
	estudiante = acta->getEstudiante();
	codirector = acta->getCodirector();
	director = acta->getDirector();
	jurado1 = acta->getJurado1();
	jurado2 = acta->getJurado2();
	list<Criterio> criterios = acta->getListaCriterios();
	DetalleCriterio detalle;
	int numero_criterio=1;

    ofstream fs("Acta"+numero_acta+".txt",ios::app);
    
    fs << "Facultad de Ingenieria"<< endl;
    fs << "Maestria en Ingenieria\n"<< endl;
    fs << "Numero de Acta: " << acta->getNumeroActa() << "		"<< "Fecha: " << acta->getFecha() <<endl;
	fs << "\n"<< endl;
    fs << "Nombre del proyecto: "<< acta->getNombre()<< "\n" << endl;
    fs << "Autor: " << estudiante.getNombre()   << "		" << "ID: " << estudiante.getId() << endl;
	fs << "Periodo: " << acta->getPeriodo() << endl;
	fs << "Director: " << director.getNombre() << endl;
	fs << "Codirector: " << codirector.getNombre() << endl;
	fs << "Enfasis: " << acta->getEnfasis() << endl;
	fs << "Modalidad: " << acta->getModalidad() << endl;
	fs << "Jurado 1: " << jurado1.getNombre() << endl;
	fs << "Jurado 2: " << jurado2.getNombre() << endl;
	fs << "\n" << endl;
	fs << "Criterios: " << endl;

	list<Criterio>::iterator criterio = criterios.begin();
	for (criterio ; criterio != criterios.end() ; criterio++)
	{
		if ( acta->getEstadoBin() == 0)
		{
			detalle = criterio->getDetalle();
			fs << numero_criterio++ << "." << endl;
			fs << "Criterio: " << criterio->getNombre() << endl;
			fs << "Calificacion Jurado 1: " << detalle.getCalificacionJurado1() << endl;
			fs << "Calificacion Jurado 2: " << detalle.getCalificacionJurado2() << endl;
			fs << "Ponderacion: " << criterio->getPonderacion()*100 << "%" << endl;
			fs << "Observacion: " << detalle.getObservacion() << endl;
			
		}
	}
	fs << "\n" << endl;
	fs << "Como reultado de estas calificaciones parciales y sus ponderaciones, la calificacional es:" << endl;
	acta->calcularNotaFinal();
	fs << "Nota Final: " << acta->getNotaFinal() << endl;
	fs << "\n" << endl;
	fs << "Obervaciones: " << endl;
	fs << acta->getObservacion() << endl;
	fs << "\n" << endl;
	fs << "Obervaciones para aprovacion: " << endl;
	fs << acta->getObservacionAprobacion() << endl;
	fs << "\n" << endl;
	fs << "Aprovacion: ";
	fs << acta->aprobacionFinal() << endl;

    fs.close();
}

int Postgrado::crearArchivoTexto()
{
	int indice=1,opcion=0;
	list<Acta>::iterator acta = listaActas.begin();
	try{
		clean();
		cout << "Si ninguna acta esta cerrada, selecciona 0 para volver al menu principal." << endl;
		for (acta ; acta != listaActas.end() ; acta++)
		{
			if ( acta->getEstadoBin() == 0)
			{
				Persona estudiante = acta->getEstudiante();
				cout << indice++ << ". " << "Numero de acta: " << acta->getNumeroActa() << "     " << "Nombre de autor: " << estudiante.getNombre() << "     " << "Estado: " << acta->getEstado() << endl;
			}
		}
		cout << "Acta: ";
		cin >> opcion;
	
		
		if ( opcion > indice )
		{
			throw(opcion);
		}
	}
	catch(int opcion)
	{
		cout << "Seleccione una acta valida..." << endl;
	}

	if (opcion == 0)
	{
		return 0;
	}	

	indice=1;

	acta = listaActas.begin();
	while(acta != listaActas.end())
	{
		if (indice == opcion)
		{
			break;
		}
		indice++;
		acta++;
	}

	archivoTexto(acta);
}

list<Acta> Postgrado::getlistaActas()
{
	return listaActas;
}

void Postgrado::setlistaActas(list<Acta> listaActas)
{
	this->listaActas = listaActas;
}

list<string> Postgrado::getlistaDirectores()
{
	return listaDirectores;
}

void Postgrado::setlistaDirectores(list<string> listaDirectores)
{
	this->listaDirectores = listaDirectores;
}

list<string> Postgrado::getlistaJurados()
{
	return listaJurados;
}

void Postgrado::setlistaJurados(list<string> listaJurados)
{
	this->listaJurados = listaJurados;
}

Persona Postgrado::modificarPersona(Persona persona)
{
	bool stop = true;
	string nombre,email,celular;
	bool ubicacion;
	int id,selector;
	
	while(stop)
	{
		clean();
		cout << "Nombre: " << persona.getNombre() << endl;
		cout << "Ubicacion: " << persona.getUbicacion() << endl;
		cout << "Email: " << persona.getEmail() << endl;
		cout << "Celular: " << persona.getCelular() << endl;
		cout << "Id: " << persona.getId() << endl;
		cout << "\n" << endl;
		cout << "1. Modificar Nombre" << endl;
		cout << "2. Modificar Ubicacion" << endl;
		cout << "3. Modificar Email" << endl;
		cout << "4. Modificar Celular" << endl;
		cout << "5. Modificar Id" << endl;
		cout << "6. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;
		try{
			if ((selector >= 7) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
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
					cout << "Ubicacion actual: " << persona.getUbicacion() << endl;
					cout << "Ubicacion nuevo(1.Extreno 0.Interno): ";
					cin >> ubicacion;
					persona.setUbicacion(ubicacion);
				}
				break;
				case 3:
				{
					clean();
					cout << "Email actual: " << persona.getEmail() << endl;
					cout << "Email nuevo: ";
					cin >> email;
					persona.setEmail(email);
				}
				break;
				case 4:
				{
					clean();
					cout << "Celular actual: " << persona.getCelular() << endl;
					cout << "Celular nuevo: ";
					cin >> celular;
					persona.setCelular(celular);
				}
				break;
				case 5:
				{
					clean();
					cout << "Id actual: " << persona.getId() << endl;
					cout << "Id nuevo: ";
					cin >> id;
					persona.setId(id);
				}
				break;
				case 6:
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

list<Criterio> Postgrado::modificarCriterios(list<Criterio> listaCriterios)
{
	bool stop = true;
	int indice;
	string nombre;
	DetalleCriterio detalle;
	float calificacionJurado1,calificacionJurado2,ponderacion;
	string observacion;
	int opcion,selector;
	Criterio nuevo;

	while(stop)
	{

		clean();
		indice=1;
		cout << "Seleccione el criterio a modificar(si no hay,seleccione 0):" <<endl;
		cout << "\n" << endl;
		list<Criterio>::iterator criterio = listaCriterios.begin();
		for (criterio ; criterio != listaCriterios.end() ; criterio++)
		{
			cout << indice++ << ". " << criterio->getNombre();		
			cout << "\n" << endl;
		}
		try{
			cout << "Criterio: ";
			cin >> opcion;
			if (opcion > indice)
			{
				throw(opcion);
			}
			
		}
		catch(int opcion)
		{
			cout << "Seleccione un criterio valido." <<endl;
		}
		

		if (opcion == 0)
		{
			cout << "Agrege un criterio, se recomienda seleccionar la opcion 6." <<endl;
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

		cout << "1. Modificar Nombre" << endl;
		cout << "2. Modificar calificacion jurado 1" << endl;
		cout << "3. Modificar calificacion jurado 2" << endl;
		cout << "4. Modificar ponderacion del criterio" << endl;
		cout << "5. Modificar observacion" << endl;
		cout << "6. Agregar criterio" << endl;
		cout << "7. Eliminar criterio" << endl;
		cout << "8. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;
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
					cout << "Calificacion del jurado 1 nueva(valor entre 0.0 y 5.0): ";
					cin >> calificacionJurado1;
					detalle.setCalificacionJurado1(calificacionJurado1);
				}
				break;
				case 3:
				{
					clean();
					cout << "Calificacion del jurado 2 actual: " << detalle.getCalificacionJurado2() << endl;
					cout << "Calificacion del jurado 2 nueva(valor entre 0.0 y 5.0): ";
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
					getline(cin,observacion);
					getline(cin,observacion);
					detalle.setObservacion(observacion);
				}
				break;
				case 6:
				{
					listaCriterios.push_back(nuevo);
					cout << "Nuevo criterio agregado" << endl;
				}
				break;
				case 7:
				{
					listaCriterios.erase(criterio);
					cout << "Criterio eliminado..." << endl;
				}
				break;
				case 8:
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


		if (opcion != 0)
		{
			criterio->setDetalle(detalle);
		}
		
	}
	
	
	return listaCriterios;
}

string Postgrado::modificarObservacionGeneral(string observacion_general)
{
	bool stop = true;
	int general=1,opcion,selector,indice;
	string observacion=observacion_general;
	
	while(stop)
	{
		clean();
		cout << "Observacion general actual: " << endl;
		cout << observacion << endl;
		cout << "\n" << endl;
		cout << "1. Modificar observacion general" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;
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
					cout << "Observacion general nueva: ";
					getline(cin,observacion);
					getline(cin,observacion);
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
	return observacion;
}

string Postgrado::modificarObservacionAprobacion(string observacion_aprobacion)
{
	bool stop = true;
	int general=1,aprovacion=2,opcion,selector,indice;
	string observaciones=observacion_aprobacion;
	
	
	while(stop)
	{
		clean();
		cout << "Observacion de aprobacion actual: " <<endl;
		cout << observaciones << endl;
		cout << "\n" << endl;
		cout << "1. Modificar observacion de aprobacion" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;
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
					cout << "Observacion de aprobacion general actual: " << endl;
					cout << observaciones << endl;
					cout << "Observacion de aprobacion general nueva: ";
					getline(cin,observaciones);
					getline(cin,observaciones);
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
	return observaciones;
}

int Postgrado::modificarNumeroActa(int numero_acta)
{
	bool stop = true;
	int nuevo=numero_acta,selector;
	
	while(stop)
	{
		clean();
		cout << "Numero de acta actual: ";
		cout << nuevo << endl;
		cout << "\n" << endl;
		cout << "1. Modificar Numero de Acta" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;
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

string Postgrado::modificarFechaActa(string fecha)
{
	bool stop = true;
	string nuevo=fecha;
	int selector;
	
	while(stop)
	{
		clean();
		cout << "Fecha acta actual: " ;
		cout << nuevo << endl;
		cout << "\n" << endl;
		cout << "1. Modificar Fecha de Acta" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;
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
					cout << "Fecha de acta actual: " << endl;
					cout << nuevo << endl;
					cout << "Fecha de acta nuevo: ";
					getline(cin,nuevo);
					getline(cin,nuevo);
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

string Postgrado::modificarPeriodoActa(string periodo)
{
	bool stop = true;
	int selector;
	string nuevo=periodo;
		
	while(stop)
	{
		clean();
		cout << "Periodo acta actual: " <<endl;
		cout << nuevo << endl;
		cout << "\n" << endl;
		cout << "1. Modificar Periodo de Acta" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;
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
					cout << "Periodo acta actual: " <<endl;
					cout << nuevo << endl;
					cout << "Periodo de acta nuevo: ";
					getline(cin,nuevo);
					getline(cin,nuevo);
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

string Postgrado::modificarEnfasisActa(string enfasis)
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
					getline(cin,nuevo);
					getline(cin,nuevo);
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

bool Postgrado::modificarModalidadActa(bool modalidad)
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
			mod = investigado;
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
					cout << "1.Aplicada - 0.Investigado" << endl;
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

bool Postgrado::modificarEstadoActa(bool estado)
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
					cout << "Recuerde que si el acta esta Activa puede modificarse," << endl;
					cout << "una vez esta se cierre solo se podra visulizar." << endl;
					cout << "1.Activa - 0.Cerrada" << endl;
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
			if (nuevo == 0)
			{
				stop == false;
			}
		}
		catch(int selector)
		{
			cout << "Seleccione una opcion valida\n" << endl;
		}
	}
	return nuevo;
}

string Postgrado::modificarNombreActa(string nombre)
{
	bool stop = true;
	int selector;
	string nuevo=nombre;
	
	while(stop)
	{
		clean();
		cout << "Nombre del proyecto actual: " <<endl;
		cout << nuevo << endl;
		cout << "\n" << endl;
		cout << "1. Modificar Nombre del proyecto" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;
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
					cout << "Nombre del proyecto nuevo: ";
					getline(cin,nuevo);
					getline(cin,nuevo);
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

int Postgrado::modificarActa()
{
	int opcion,indice=1,selector;
	clean();
	bool stop = true,modalidad,estado;
	Acta acta_modificar;
	int numero_acta,aprovacion,count_jurados=0,count_criterios=0;
	float nota_final;
	string fecha,periodo,enfasis,nombre;
	Persona estudiante,codirector,director,jurado1,jurado2;
	string observacion_general,observacion_aprobacion;
	list<Criterio> listaCriterios;
	list<string> listaObservaciones;

	cout << "Seleccione el indice del acta que se desea modificar" << endl;
	cout << "Seleccione 0 si desea regresar" << endl;

	list<Acta>::iterator acta = listaActas.begin();
	for (acta ; acta != listaActas.end() ; acta++)
	{
		if ( acta->getEstadoBin() == 1)
		{
			Persona estudiante = acta->getEstudiante();
			cout << indice++ << ". " << "Numero de acta: " << acta->getNumeroActa() << "     " << "Nombre de autor: " << estudiante.getNombre() << "     " << "Estado: " << acta->getEstado() << endl;
		}
	}
	cout << "Acta: ";
	cin >> opcion;

	if (opcion == 0)
	{
		return 0;
	}

	indice=1;

	acta = listaActas.begin();
	while(acta != listaActas.end())
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
		clean();
		cout << "1.  Modificar Estudiente" << endl;
		cout << "2.  Modificar Director" << endl;
		cout << "3.  Modificar Codirector" << endl;
		cout << "4.  Modificar Jurado 1" << endl;
		cout << "5.  Modificar Jurado 2" << endl;
		cout << "6.  Modificar Criterios" << endl;
		cout << "7.  Modificar Observacion general" << endl;
		cout << "8.  Modificar Observacion aprobacion" << endl;
		cout << "9.  Modificar Numero del acta" << endl;
		cout << "10. Modificar Fecha del acta" << endl;
		cout << "11. Modificar Periodo del acta" << endl;
		cout << "12. Modificar Enfasis del acta" << endl;
		cout << "13. Modificar Modalidad del acta" << endl;
		cout << "14. Calcular nota final" << " Actual: " << acta->getNotaFinal()  << endl;
		cout << "15. Modificar Estado del acta" << endl;
		cout << "16. Modificar Nombre del proyecto en el acta" << endl;
		cout << "17. Eliminar acta" << endl;
		cout << "18. Actualizar aprobacion" << " Actual: " << acta->aprobacionFinal()  << endl;
		cout << "19. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;
		try{
			if ((selector >= 20) || (selector == 0))
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
					observacion_aprobacion = modificarObservacionAprobacion(acta->getObservacionAprobacion());
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
					stop = false;
				}
				break;
				case 16:
				{
					nombre = modificarNombreActa(acta->getNombre());
					acta->setNombre(nombre);
					
				}
				break;
				case 17:
				{
					listaActas.erase(acta);
					stop = false;
				}
				break;
				case 18:
				{
					acta->calcularAprobacion();

				}
				break;
				case 19:
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

}

void Postgrado::crearActa()
{
	Acta nueva;
	listaActas.push_back(nueva);
	cout << "Nueva acta creada...\n" << endl;
	
}

void Postgrado::listarporDirector()
{
	int selector,indice,opcion;
	bool stop = true;
	string director_nombre;

	while(stop)
	{
		indice=1;
		clean();
		cout << "Diferentes directores en base de datos" << endl;
		cout << "Seleccione el director de las actas que desea ver:" << endl;
		list<string>::iterator director_it = listaDirectores.begin();
		for (director_it ; director_it != listaDirectores.end() ; director_it++)
		{
			cout << indice << ". " << *director_it << endl;
			indice++;
		}
		cout << "Opcion:";
		cin >> opcion;
		cout << "\n" << endl;

		director_it = listaDirectores.begin();
		indice=1;
		while(director_it != listaDirectores.end())
		{
			if (indice == opcion)
			{
				break;
			}
			indice++;
			director_it++;
		}

		list<Acta>::iterator acta = listaActas.begin();
		for (acta ; acta != listaActas.end() ; acta++)
		{
			Persona director = acta->getDirector();
			if (director.getNombre() == *director_it)
			{
				Persona estudiante = acta->getEstudiante();
				cout << indice++ << ". ";
				cout << "Numero de acta: " << acta->getNumeroActa();
				cout << "Fecha: " << acta->getFecha() << "   ";
				cout << "Nombre de autor: " << estudiante.getNombre() << "   ";
				cout << "Estado: " << acta->getEstado() << "   ";
				cout << "Nota final: " << acta->getNotaFinal() << endl;
			}
			
		}
		cout << "\n"<< endl;
		cout << "1. Buscar acta con otro director"<< endl;
		cout << "2. Salir"<< endl;
		cout << "Opcion:";
		cin >> selector;

		try{
			if (selector >= 3 || selector == 0)
			{
				throw(selector);
			}
			switch(selector)
			{
				case 1:
				{
					stop = true;
				}
				break;
				case 2:
				{
					stop = false;
				}
				break;
			}
		}
		catch(int selector){
			cout << "Seleccione una opcion valida" << endl;
		}
	}
}

void Postgrado::listarporJurado()
{
	int selector,indice=1,opcion;
	bool stop = true;
	string jurado_nombre;

	while(stop)
	{
		clean();
		cout << "Diferentes jurados en base de datos" << endl;
		cout << "Seleccione el jurado de las actas que desea ver:" << endl;
		list<string>::iterator jurado_it = listaJurados.begin();
		for (jurado_it ; jurado_it != listaJurados.end() ; jurado_it++)
		{
			cout << indice << ". " << *jurado_it << endl;
			indice++;
		}
		cout << "Opcion:";
		cin >> opcion;
		cout << "\n" << endl;

		jurado_it = listaJurados.begin();
		indice=1;
		while(jurado_it != listaJurados.end())
		{
			if (indice == opcion)
			{
				break;
			}
			indice++;
			jurado_it++;
		}

		list<Acta>::iterator acta = listaActas.begin();
		for (acta ; acta != listaActas.end() ; acta++)
		{
			Persona jurado1 = acta->getJurado1();
			Persona jurado2 = acta->getJurado2();
			if ((jurado1.getNombre() == *jurado_it) || (jurado2.getNombre() == *jurado_it))
			{
				Persona estudiante = acta->getEstudiante();
				cout << indice++ << ". ";
				cout << "Numero de acta: " << acta->getNumeroActa();
				cout << "Fecha: " << acta->getFecha() << "   ";
				cout << "Nombre de autor: " << estudiante.getNombre() << "   ";
				cout << "Estado: " << acta->getEstado() << "   ";
				cout << "Nota final: " << acta->getNotaFinal() << endl;
			}
			
		}
		cout << "\n"<< endl;
		cout << "1. Buscar acta con otro jurado"<< endl;
		cout << "2. Salir"<< endl;
		cout << "Opcion:";
		cin >> selector;

		try{
			if (selector >= 3 || selector == 0)
			{
				throw(selector);
			}
			switch(selector)
			{
				case 1:
				{
					stop = true;
				}
				break;
				case 2:
				{
					stop = false;
				}
				break;
			}
		}
		catch(int selector){
			cout << "Seleccione una opcion valida" << endl;
		}
	}	
}

void Postgrado::listarActas()
{
	int indice=1,selector;
	bool stop = true;
	string pause,nombre_director,nombre_jurado1,nombre_jurado2;
	Persona estudiante,director,jurado1,jurado2;
	list<string> vacio;

	setlistaDirectores(vacio);
	setlistaJurados(vacio);


	list<Acta>::iterator acta = listaActas.begin();
	for (acta ; acta != listaActas.end() ; acta++)
	{
		director = acta->getDirector();
		nombre_director = director.getNombre();
		listaDirectores.push_back(nombre_director);

		jurado1 = acta->getJurado1();
		nombre_jurado1 = jurado1.getNombre();
		listaJurados.push_back(nombre_jurado1);

		jurado2 = acta->getJurado2();
		nombre_jurado2 = jurado2.getNombre();
		listaJurados.push_back(nombre_jurado2);
		++numero_actas;
	}


	listaDirectores.sort();
	listaDirectores.unique();

	this->numero_directores = listaDirectores.size();

	listaJurados.sort();
	listaJurados.unique();

	this->numero_jurados = listaJurados.size();

	while(stop)
	{
		clean();		
		indice=1;
		list<Acta>::iterator acta = listaActas.begin();
		cout << "Seleccione el indice del criterio para listar" << endl;
		cout << "1.  Listar todas las actas" << endl;
		cout << "2.  Listar actas abiertas" << endl;
		cout << "3.  Listar actas cerradas" << endl;
		cout << "4.  Listar por modalidad Aplicada" << endl;
		cout << "5.  Listar por modalidad Investigacion" << endl;
		cout << "6.  Listar por Director" << endl;
		cout << "7.  Listar por Jurado" << endl;
		cout << "8.  Listar actas pendientes" << endl;
		cout << "9.  Listar actas rechazadas" << endl;
		cout << "10. Listar jurados internos" << endl;
		cout << "11. Listar jurados externos" << endl;
		cout << "12. Salir" << endl;
		cout << "Opcion: ";
		cin >> selector;
		try{
			if ((selector >= 13) || (selector == 0))
			{
				throw (selector);
			}
			
			switch (selector)
			{
				case 1:
				{
					clean();
					for (acta ; acta != listaActas.end() ; acta++)
					{
						Persona estudiante = acta->getEstudiante();
						cout << indice++ << ". ";
						cout << "Numero de acta: " << acta->getNumeroActa();
						cout << "Fecha: " << acta->getFecha() << "   ";
						cout << "Nombre de autor: " << estudiante.getNombre() << "   ";
						cout << "Estado: " << acta->getEstado() << "   ";
						cout << "Nota final: " << acta->getNotaFinal() << endl;
					}
					cout << "Seleccione 0 y presione la tecla Enter para volver..." << endl;
					cin >> pause;
				}
				break;
				case 2:
				{
					clean();
					for (acta ; acta != listaActas.end() ; acta++)
					{
						if ( acta->getEstadoBin() == 1)
						{
							Persona estudiante = acta->getEstudiante();
							cout << indice++ << ". ";
							cout << "Numero de acta: " << acta->getNumeroActa();
							cout << "Fecha: " << acta->getFecha() << "     ";
							cout << "Nombre de autor: " << estudiante.getNombre() << "     ";
							cout << "Estado: " << acta->getEstado() << "     ";
							cout << "Nota final: " << acta->getNotaFinal() << endl;
						}
					}
					cout << "Seleccione 0 y presione la tecla Enter para volver..." << endl;
					cin >> pause;
				}
				break;
				case 3:
				{
					clean();
					for (acta ; acta != listaActas.end() ; acta++)
					{
						if ( acta->getEstadoBin() == 0)
						{
							Persona estudiante = acta->getEstudiante();
							cout << indice++ << ". ";
							cout << "Numero de acta: " << acta->getNumeroActa();
							cout << "Fecha: " << acta->getFecha() << "     ";
							cout << "Nombre de autor: " << estudiante.getNombre() << "     ";
							cout << "Estado: " << acta->getEstado() << "     ";
							cout << "Nota final: " << acta->getNotaFinal() << endl;
						}
					}
					cout << "Seleccione 0 y presione la tecla Enter para volver..." << endl;
					cin >> pause;
				}
				break;
				case 4:
				{
					clean();
					for (acta ; acta != listaActas.end() ; acta++)
					{
						if ( acta->getModalidadBin() == 1)
						{
							Persona estudiante = acta->getEstudiante();
							cout << indice++ << ". ";
							cout << "Numero de acta: " << acta->getNumeroActa();
							cout << "Fecha: " << acta->getFecha() << "     ";
							cout << "Nombre de autor: " << estudiante.getNombre() << "     ";
							cout << "Estado: " << acta->getEstado() << "     ";
							cout << "Nota final: " << acta->getNotaFinal() << endl;
						}
					}
					cout << "Seleccione 0 y presione la tecla Enter para volver..." << endl;
					cin >> pause;
				}
				break;
				case 5:
				{
					clean();
					for (acta ; acta != listaActas.end() ; acta++)
					{
						if ( acta->getModalidadBin() == 0)
						{
							Persona estudiante = acta->getEstudiante();
							cout << indice++ << ". ";
							cout << "Numero de acta: " << acta->getNumeroActa();
							cout << "Fecha: " << acta->getFecha() << "     ";
							cout << "Nombre de autor: " << estudiante.getNombre() << "     ";
							cout << "Estado: " << acta->getEstado() << "     ";
							cout << "Nota final: " << acta->getNotaFinal() << endl;
						}
					}
					cout << "Seleccione 0 y presione la tecla Enter para volver..." << endl;
					cin >> pause;
				}
				break;
				case 6:
				{
					clean();
					listarporDirector();
				}
				break;
				case 7:
				{
					clean();
					listarporJurado();
				}
				break;
				case 8:
				{
					clean();
					for (acta ; acta != listaActas.end() ; acta++)
					{
						if ( acta->getAprovacion() == 2)
						{
							Persona estudiante = acta->getEstudiante();
							cout << indice++ << ". ";
							cout << "Numero de acta: " << acta->getNumeroActa();
							cout << "Fecha: " << acta->getFecha() << "     ";
							cout << "Nombre de autor: " << estudiante.getNombre() << "     ";
							cout << "Estado: " << acta->getEstado() << "     ";
							cout << "Nota final: " << acta->getNotaFinal() << endl;
						}
					}
					cout << "Seleccione 0 y presione la tecla Enter para volver..." << endl;
					cin >> pause;
				}
				break;
				case 9:
				{
					clean();
					for (acta ; acta != listaActas.end() ; acta++)
					{
						if ( acta->getAprovacion() == 1)
						{
							Persona estudiante = acta->getEstudiante();
							cout << indice++ << ". ";
							cout << "Numero de acta: " << acta->getNumeroActa() << "     ";
							cout << "Fecha: " << acta->getFecha() << "     ";
							cout << "Nombre de autor: " << estudiante.getNombre() << "     ";
							cout << "Estado: " << acta->getEstado() << "     ";
							cout << "Nota final: " << acta->getNotaFinal() << endl;
						}
					}
					cout << "Seleccione 0 y presione la tecla Enter para volver..." << endl;
					cin >> pause;
				}
				break;
				case 10:
				{
					clean();
					list<string>::iterator jurado_interno = listaJurados.begin();
					acta = listaActas.begin();
					for (acta;acta != listaActas.end();acta++) 
					{
						jurado_interno = listaJurados.begin();
						jurado1 = acta->getJurado1();
						jurado2 = acta->getJurado2();
						nombre_jurado1 = jurado1.getNombre();
						nombre_jurado2 = jurado2.getNombre();

						for (jurado_interno;jurado_interno != listaJurados.end();jurado_interno++)
						{
							if ( *jurado_interno == nombre_jurado1)
							{
								if (jurado1.getUbicacionBin() == 0)
								{
									cout << indice++ << ". ";
									cout << "Nombre: " << jurado1.getNombre() << "     ";
									cout << "Ubicacion: " << jurado1.getUbicacion() << "     ";
									cout << "Email: " << jurado1.getEmail() << endl;
								}
								
							}
							else if (*jurado_interno == nombre_jurado2) 
							{
								if (jurado2.getUbicacionBin() == 0)
								{
									cout << indice++ << ". ";
									cout << "Nombre: " << jurado2.getNombre() << "     ";
									cout << "Ubicacion: " << jurado2.getUbicacion() << "     ";
									cout << "Email: " << jurado2.getEmail() << endl;
								}
							}
						}
						
					}
					cout << "Seleccione 0 y presione la tecla Enter para volver..." << endl;
					cin >> pause;
				}
				break;
				case 11:
				{
					clean();
					list<string>::iterator jurado_interno;
					acta = listaActas.begin();
					for (acta;acta != listaActas.end();acta++) 
					{
						jurado_interno = listaJurados.begin();
						jurado1 = acta->getJurado1();
						jurado2 = acta->getJurado2();
						nombre_jurado1 = jurado1.getNombre();
						nombre_jurado2 = jurado2.getNombre();

						for (jurado_interno;jurado_interno != listaJurados.end();jurado_interno++)
						{
							if ( *jurado_interno == nombre_jurado1)
							{
								if (jurado1.getUbicacionBin() == 1)
								{
									cout << indice++ << ". ";
									cout << "Nombre: " << jurado1.getNombre() << "     ";
									cout << "Ubicacion: " << jurado1.getUbicacion() << "     ";
									cout << "Email: " << jurado1.getEmail() << endl;
								}
								
							}
							else if (*jurado_interno == nombre_jurado2) 
							{
								if (jurado2.getUbicacionBin() == 1)
								{
									cout << indice++ << ". ";
									cout << "Nombre: " << jurado2.getNombre() << "     ";
									cout << "Ubicacion: " << jurado2.getUbicacion() << "     ";
									cout << "Email: " << jurado2.getEmail() << endl;
								}
							}
						}
						
					}
					cout << "Seleccione 0 y presione la tecla Enter para volver..." << endl;
					cin >> pause;
				}
				break;
				case 12:
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

}

