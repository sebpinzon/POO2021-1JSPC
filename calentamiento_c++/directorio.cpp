#include <iostream>
#include <fstream>
#include <string>
using namespace std;

 
int agregar()
{
	string nom,apl,line,file_name;
	int tel, count;

	ofstream dir;
    dir.open (file_name);

    if (dir.is_open()) 
    {
    	while (dir)
    	{
    		count++;
    	}
    }

	cout << "Nombre: ";
	cin >> nom;
	cout << "Apellido: ";
	cin >> apl;
	cout << "Telefono: ";
	cin >> tel;

	dir << nom << "," << apl << "," << tel << endl;

    dir.close();
	return 0;
}

int nuevo()
{
	string file_name;

	cout << "Ingrese el nombre del directorio nuevo: ";
	cin >> file_name;

	ofstream dir;
    dir.open (file_name);
    dir << "Writing this to a file.\n";
    dir.close();

	agregar();
	return 0;
}

int visualizar()
{
	string line;

	ifstream file ("directorio.txt");
	if (file.is_open()) 
	{
		getline (file,line);
   		while ( file ) 
   		{
   			cout << line << endl;
      		getline (file,line);
      	}
   	}
  	file.close(); 
	return 0;
}

int salir()
{

	return 0;
}

int main()
{
	while(true)
	{
		int opc;
		cout << "Escoja una de las opciones: \n 1.Crear directorio \n 2.Agregar contacto \n 3.Visualizar contactos \n 4.Salir";
		cin >> opc;

		switch(opc)
		{
			case 1: nuevo();
			case 2: agregar();
			case 3: visualizar();
			case 4: salir();
			//default: cout << "Opcion incorrecta"; 
		}	
	}
	
	return 0;
}