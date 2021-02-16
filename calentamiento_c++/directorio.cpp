#include <iostream>
#include <fstream>
#include <string>
using namespace std;

 
int agregar()
{
	string nom,apl,file_name;
	int tel;

	cout << "Ingrese el nombre del directorio: ";
	cin >> file_name;

	ofstream dir;
    dir.open (file_name+".txt",ios::app);
    cout << "Nombre: ";
	cin >> nom;
	cout << "Apellido: ";
	cin >> apl;
	cout << "Telefono: ";
	cin >> tel;

	dir << "\n" << nom << "," << apl << "," << tel << endl;
    dir.close();

	return 0;
}

int nuevo()
{
	string nom,apl,file_name;
	int tel;

	cout << "Ingrese el nombre del directorio nuevo: ";
	cin >> file_name;

	ofstream dir;
    dir.open (file_name+".txt");
    
    dir.close();
    cout << "Directorio creado...\n\n";
	return 0;
}

int visualizar()
{
	string line, file_name;

	cout << "Ingrese el nombre del directorio nuevo: ";
	cin >> file_name;

	ifstream file (file_name+".txt");
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


int main()
{
	bool stop=true;
	while(stop)
	{
		int opc=0;
	cout << "Escoja una de las opciones: \n 1.Crear directorio nuevo \n 2.Agregar contacto \n 3.Visualizar \n 4.Salir ";
		cin >> opc;

		switch(opc)
		{
			case 1: nuevo();
			break;
			case 2: agregar();
			break;
			case 3: visualizar();
			break;
			case 4: stop=false;
			break;
			default: cout << "Seleccione de nuevo\n\n"; 
		}	
	}
	
	return 0;
}