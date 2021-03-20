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
	string aplicado = "Aplicado", investigado = "Investigado",nd = "No determinada";

	if (modalidad == 1)
	{
		return aplicado;
	}
	else if (modalidad == 0)
	{
		return investigado;
	}
	else
	{
		return nd;
	}
}

bool Acta::getModalidadBin()
{
	return modalidad;
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

bool Acta::getEstadoBin()
{
	return estado;
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
	DetalleCriterio detalle;
	float calificacion1=0, calificacion2=0,promedio,final,nota_final=0;
	for (list<Criterio>::iterator criterio = listaCriterios.begin() ; criterio != listaCriterios.end() ; criterio++)
	{
		detalle = criterio->getDetalle();
		calificacion1 = detalle.getCalificacionJurado1();
		calificacion2 = detalle.getCalificacionJurado2();

		promedio = (calificacion1+calificacion2)/2;

		final = promedio * criterio->getPonderacion();

		nota_final = nota_final + final;
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

list<Criterio> Acta::getListaCriterios()
{
	return listaCriterios;
}

void Acta::setListaCriterios(list<Criterio> listaCriterios)
{
	this->listaCriterios = listaCriterios;
}

void Acta::mostrarCriterio(int id)
{
	DetalleCriterio detalle;
	for (list<Criterio>::iterator criterio = listaCriterios.begin() ; criterio != listaCriterios.end() ; criterio++)
	{
		if (criterio->getId() == id)
		{
			detalle = criterio->getDetalle();
			cout << "\n" << endl;
			cout << "Criterio: " << criterio->getNombre() << endl;
			cout << "Calificacion Jurado 1: " << detalle.getCalificacionJurado1() << endl;
			cout << "Calificacion Jurado 2: " << detalle.getCalificacionJurado2() << endl;
			cout << "Ponderacion: " << criterio->getPonderacion()*100 << "%" << endl;
			cout << "Observacion: " << detalle.getObservacion() << endl;
			
		}
	}
}

string Acta::getObservacion()
{
	return observacion;
}
void Acta::setObservacion(string observacion)
{
	this->observacion = observacion;
}

string Acta::getObservacionAprobacion()
{
	return observacion_aprobacion;
}
void Acta::setObservacionAprobacion(string observacion_aprobacion)
{
	this->observacion_aprobacion = observacion_aprobacion;
}

string Acta::getNombre()
{
	return nombre;
}

void Acta::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Acta::calcularAprobacion()
{
	calcularNotaFinal();
	if (nota_final > 3.5 )
	{
		aprobacion = 3;
	}
	else
	{
		aprobacion = 1;
	}
}

string Acta::aprobacionFinal()
{
	string aprobado="Aprovado", pendiente = "Pendientes", rechazado = "Rechazado";
	if (aprobacion == 1)
	{
		return aprobado;
	}
	else if(aprobacion == 2)
	{
		return pendiente;
	}
	else if(aprobacion == 3)
	{
		return rechazado;
	}
}

int Acta::getAprovacion()
{
	return aprobacion;
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