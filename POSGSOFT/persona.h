#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Persona
{
	private:
		string nombre,email,celular;
		bool ubicacion=0;
		int id;
	public: 
		Persona();
		Persona(string,string,string,bool,int);
		string getNombre();
		void setNombre(string);
		string getUbicacion();
		void setUbicacion(bool);
		string getEmail();
		void setEmail(string);
		string getCelular();
		void setCelular(string);
		int getId();
		void setId(int);
		void mostrarPersona();
};


#endif