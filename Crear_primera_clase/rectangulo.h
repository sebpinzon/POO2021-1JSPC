//#ifndef RECTANGULO_H
//Guarda
//#define RECTANGULO_H

class Rectangulo
{
	private:
		float largo, ancho;
	
	public:
		Rectangulo();
		Rectangulo(float, float);
		float calcularPerimetro();
		float calcularArea();
		void setLargo(float);
		void setAncho(float);
		float getLargo();
		float getAncho();

};

//#endif /* !RECTANGULO_H */