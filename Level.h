#ifndef LEVEL_H
#define LEVEL_H

class Level 
{	
private:
	int alto;
	int ancho;
	int x;
	int y;
	int maxLimitX;
	int maxLimitY;
	int minLimitX;
	int minLimitY;
public: 
	Level(int _ancho,int _alto);
	Level(){};		
	void set_limit(int,int,int,int);
	void dibujar_level();
	void borrar_level();
};
#endif
