//#ifndef TRIANGULO_H
//Guarda
//#define TRIANGULO_H

class Triangulo
{
	private:
		float LADO_A, LADO_B, LADO_C;
		float ANGU_A_B, ANGU_B_C, ANGU_C_A;
	public:
		Triangulo();
		Triangulo(float, float, float,float,float,float);
		float calcularArea();
		float calcularPerimetro();
		float getLado();
		void setLado(float);
		float getAngulo();
		void setAngulo(float);
};

//#endif /* !TRIANGULO_H */