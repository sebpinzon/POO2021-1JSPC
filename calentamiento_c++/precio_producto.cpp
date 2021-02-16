#include<iostream>
using namespace std;

int IVA(int precio)
{
	int z;
	float porcentaje=0.19;
	z=precio*porcentaje;

	return(z);
}

int main()
{
	int precio,s,m;
	cout << "Ingrese el precio del producto: ";
	cin >> precio;
	m=IVA(precio);
	s=precio+m;
	cout << "El precio del producto con IVA es " << s << endl;
	return 0;
}