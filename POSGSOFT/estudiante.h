#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>

using std::string;

class Estudiante
{
	private:
		string nombre,enfasis,email;
		int id;
	public:
		Estudiante();
		Estudiante(string,int,string,string);
		string getNombre();
		void setNombre(string);
		int getId();
		void setId(int);
		string getEnfasis();
		void setEnfasis(string);
		string getEmail();
		void setEmail(string);

};



#endif