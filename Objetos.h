#ifndef OBJETO_H
#define OBJETO_H
#include <ctime>


class Objetos{
protected:
	int x;
	int y;
	// hago matrices lo suficientemente grandes
	int matriz[5][4];
	int color[5][4]; // matriz de colores
	int ancho;
	int alto;
	int pasoX;
	int pasoY;
	int xnueva;
	int ynueva;
	int maxLimitX;
	int maxLimitY;
	int minLimitX;
	int minLimitY;
	
	clock_t tempo; //variable para ajustar la velocidad de movimiento de la pelotita
	clock_t paso; //variable para ajustar la velocidad de movimiento de la pelotita
	int velocidad;
	
public:
	Objetos(int vel, int x0,int y0);
	Objetos(){};
	void dibujar();
	void borrar(); // para dibujar, antes debemor borrar	
	void setLimit(int, int,int, int);	
	void set_velocidad(int);
	bool desaparecer();
	virtual bool update();
	int getX(){return x;}
	int getY(){return y;}
	
};
#endif
