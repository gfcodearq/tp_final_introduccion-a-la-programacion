#ifndef PLAYER_H
#define PLAYER_H
#include "Objetos.h"
class Player : public Objetos
{
private:
	int vidas = 3;
public: 
	Player(int v, int x0,int y0);
	Player(){};		
	bool update();
	int getX(){return x;}
	int getY(){return y;}
};
#endif

