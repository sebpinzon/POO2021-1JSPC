#include "acta.h"

Acta::Acta(){}

int Acta::getNumeroActa()
{
	return numero_acta;
}

void Acta::setNumeroActa(int numero_acta)
{
	this->numero_acta = numero_acta;
}

string Acta::getFecha()
{
	return fecha;
}

void Acta::setFecha(string fecha)
{
	this->fecha = fecha;
}

string Acta::getPeriodo()
{
	return periodo;
}

void Acta::setPeriodo(string periodo)
{
	this->periodo = periodo;
}

string Acta::getEnfasis()
{
	return enfasis;
}

void Acta::setEnfasis(string enfasis)
{
	this->enfasis = enfasis;
}
		
int Acta::getAprovacion()
{
	return aprovacion;
}

void Acta::setAprovacion(int aprovacion)
{
	this->aprovacion = aprovacion;
}

Persona Acta::getEstudiante()
{
	return estudiante;
}

void Acta::setEstudiante(Persona estudiante)
{
	this->estudiante = estudiante;
}

Persona Acta::getDirector()
{
	return director;
}

void Acta::setDirector(Persona director)
{
	this->director = director;
}

Persona Acta::getCodirector()
{
	return codirector;
}

void Acta::setCodirector(Persona codirector)
{
	this->codirector = codirector;
}

string Acta::getModalidad()
{
	string aplicado = "Aplicado", investigado = "Investigado";

	if (modalidad == 1)
	{
		return aplicado;
	}
	else
	{
		return investigado;
	}
}

void Acta::setModalidad(bool modalidad)
{
	this->modalidad = modalidad;
}

string Acta::getEstado()
{
	string activa = "Activa", cerrada = "Cerrada";

	if (estado == 1)
	{
		return activa;
	}
	else
	{
		return cerrada;
	}
}

void Acta::setEstado(bool estado)
{
	this->estado = estado;
}

float Acta::getNotaFinal()
{
	return nota_final;
}

void Acta::calcularNotaFinal()
{
	float calificacion1=0, calificacion2=0,promedio,nota_final;
	for (list<Criterio>::iterator criterio = listaCriterios.begin() ; criterio != listaCriterios.end() ; criterio++)
	{
		calificacion1 = criterio->getCalificacionJurado1();
		calificacion2 = criterio->getCalificacionJurado2();

		promedio = (calificacion1+calificacion2)/2;

		nota_final = nota_final + promedio;
	}

	this->nota_final = nota_final;
}

Persona Acta::getJurado1()
{
	return jurado1;
}

void Acta::setJurado1(Persona jurado1)
{
	this->jurado1 = jurado1;
}

Persona Acta::getJurado2()
{
	return jurado2;
}

void Acta::setJurado2(Persona jurado2)
{
	this->jurado2 = jurado2;
}

void Acta::mostrarCriterio(int id)
{
	for (list<Criterio>::iterator criterio = listaCriterios.begin() ; criterio != listaCriterios.end() ; criterio++)
	{
		if (criterio->getId() == id)
		{
			cout << "Criterio: " << criterio->getNombre() << endl;
			cout << "Calificacion Jurado 1: " << criterio->getCalificacionJurado1() << endl;
			cout << "Calificacion Jurado 2: " << criterio->getCalificacionJurado2() << endl;
			cout << "Ponderacion: " << criterio->getPonderacion()*100 << "%" << endl;
			cout << "Observacino Jurado 1: " << criterio->getObservacionJurado1() << endl;
			cout << "Observacino Jurado 2: " << criterio->getObservacionJurado2() << endl;
		}
	}
}
void Acta::agregarCriterio(Criterio criterio)
{
	listaCriterios.push_back(criterio);
	this->count_criterios = count_criterios++;
}

list<Criterio> getListaCriterios()
{
	return listaCriterios;
}

void setListaCriterios(list<Criterio> listaCriterios)
{
	this->listaCriterios = listaCriterios;
}

void Acta::mostrarObservaciones()
{
	cout << listaObservaciones[0] << endl;
	cout << listaObservaciones[1] << endl;
}
void Acta::agregarObservacion(int indice)
{
	string observacion;
	cout << "Escriba la observacion: " << endl;
	getline(cin,observacion);
	listaObservaciones[indice] = observacion;
}

void Acta::mostrarActa()
{
	int numero_criterio=1;
	cout << "Numero de Acta: " << numero_acta << endl;
	cout << "Fecha: " << fecha << endl;
	cout << "Autor: " << estudiante.getNombre() << endl;
	cout << "ID: " << estudiante.getId() << endl;
	cout << "Periodo: " << periodo << endl;
	cout << "Director: " << director.getNombre() << endl;
	cout << "Codirector: " << codirector.getNombre() << endl;
	cout << "Enfasis: " << enfasis << endl;
	cout << "Modalidad: " << getModalidad() << endl;
	cout << "Jurado 1: " << jurado1.getNombre() << endl;
	cout << "Jurado 2: " << jurado2.getNombre() << endl;
	cout << "\n" << endl;
	cout << "Creiterios: " << endl;
	for ( int i=0 ; i == count_criterios ; i++ )
	{
		cout << numero_criterio++ << "." << endl;
		mostrarCriterio(i);
		cout << "\n" << endl;
	}
	calcularNotaFinal();
	cout << "Nota Final: " << nota_final << endl;
	cout << "\n" << endl;

	cout << "Estado del acta: " << getEstado() << endl;

}