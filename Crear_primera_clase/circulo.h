//#ifndef CIRCULO_H
//Guarda
//#define CIRCULO_H

class Circulo
{
	private:
		float RADIO, PI=3.14;

	public:
		Circulo();
		Circulo(float);
		float getRadio();
		void setRadio(float);
		float calcularArea();
		float calcularPerimetro();

};

//#endif /* !CIRCULO_H */