#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int cod=0;

int res_cod()
{
	string line;
	int count=0;
    ifstream log ("registry.txt");
    if(log.is_open())
    {
    	while(log)
    	{
    		getline (log,line);
    		count++;
    	}
    }
    log.close();
	return count;
}

int write(int cod, int ed, string sx, float alt)
{
	ofstream log;
	log.open("registry.txt", ios::app);
	log << cod << "," << "Edad: " << ed << "," << "Sexo: " << sx << "," << "Altura: " << alt << endl;
	log.close();
}

int visualize()
{
	int count=1,cod;
	cout << "Digite el codigo de identificacion: ";
	cin >> cod;
	string line;
	ifstream log;
	log.open("registry.txt");
	if (log.is_open())
	{
		while (log)
		{
			getline(log, line);
			if (count == cod)
			{
				cout << line <<endl;
				break;
			}
			count++;
		}

	}
	return 0;
}

int menu()
{
	int opc;
	cout << "Desea: \n1.Agregar otro \n2.Visualizar\n3.Salir\n: ";
	cin >> opc;
	return opc;
}

int add()
{
	int ed;
	float alt;
	string sx;
	cout << "Ingrese los datos: \n 1.Edad: ";
	cin >> ed;
	cout << "\n2.Sexo(M/F): ";
	cin >> sx;
	cout << "\n3.Altura: ";
	cin >> alt;
	cout << "Codigo de identificacion: " << cod << endl;
	write(cod,ed,sx,alt);
	cod++; 
	cout << "Guardado...\n";
}


int main()
{
	int opc;
	bool stop=true;
	cod=res_cod();
	while(stop)
	{
		opc=menu();
		switch(opc)
		{
			case 1: add();
			break;
			case 2: visualize();
			break;
			case 3: stop=false;
			break;
		}
		
		
		
	}

	return 0;
}