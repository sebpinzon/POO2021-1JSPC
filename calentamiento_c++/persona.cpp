#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int res_cod()
{
	ofstream log;
    log.open ("registry.txt",ios::app);
    if(log.is_open())
    {
    	while()
    }
    log.close()
	return 0;
}


int main()
{
	int ed, cod=0;
	float alt;
	string sx;
	bool stop=true;
	while(stop)
		cout << "Ingrese los datos: \n 1.Edad";
		cin >> ed;
		cout << "\n2.Sexo";
		cin >> sx;
		cout << "\n3.Altura";
		cin >> alt;
		cout << "\nEdad: " << ed << " Sexo: " << sx << " Altura: " << alt << endl;
		cod++;
		cout << "Codigo de identificacion: " << cod << endl; 
		cout << "Guardado...\n";

	return 0;
}