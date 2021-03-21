#include <iostream>
#include <fstream>
#include "postgrado.h"

using std::ifstream;
using std::ofstream;
using std::getline;
using std::ios;
using std::to_string;

int menu()
{
	int opcion;
	cout << "1. Modificar acta" << endl;
	cout << "2. Crear acta" << endl;
	cout << "3. Listar actas" << endl;
	cout << "4. Generar archivo de texto" << endl;
	cout << "5. Salir" << endl;
	cout << "Opcion: ";
	cin >> opcion;
	return opcion;
}


int main()
{
	Postgrado postgrado;
	int opcion,selector_acta;
	bool stop=true;
	Acta restore;
	int cout_restore=0;
	list<Acta> actas;
/*
	// CARGANDO DATOS DEL ARCHIVO AL PROGRAMA
	ifstream file("db.txt",ios::out | ios::in | ios::binary);
	if(file.is_open())
    {

    	while(file)
    	{
    		file.seekg(cout_restore*sizeof(Acta));
    		file.read((char*)&restore, sizeof(Acta));
    		actas.push_back(restore);
    		cout_restore++;
    	}
    }
    file.close();
*/
	while(stop)
	{
		postgrado.clean();
		opcion = menu();
		cout << "\n" << endl;
		try{
			if ((opcion >= 6) || (opcion == 0))
			{
				throw (opcion);
			}
			
			switch (opcion)
			{
			case 1:
			{
				postgrado.modificarActa();
			}
			break;
			case 2:
			{
				postgrado.crearActa();
			}
			break;
			case 3:
			{
				postgrado.listarActas();
			}
			break;
			case 4:
			{
				postgrado.crearArchivoTexto();
			}
			break;
			case 5:
			{
				stop = false;
			}
			break;
			}
		}
		catch(int opcion)
		{
			cout << "Seleccione una opcion valida\n" << endl;
		}
		
	}
/*
	// CARGANDO DATOS DEL ARCHIVO AL PROGRAMA
	cout_restore=0;
	list<Acta>::iterator acta = actas.begin();
	ofstream filee("db.txt",ios::out | ios::in | ios::binary);
	if(filee.is_open())
	{
		for(acta; acta != actas.end(); acta++)
		{
			//filee.seekp(cout_restore*sizeof(Acta));
    		filee.write((char*)&acta, sizeof(Acta));
    		cout_restore++;
		}
	}
	
    filee.close();
	*/
	return 0;
}