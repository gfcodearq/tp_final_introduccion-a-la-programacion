#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "Objetos.h"
class Obstaculo : public Objetos
{
public:
	Obstaculo(int x0,int y0,int vel);
	Obstaculo(){};	
	bool update();		
};
#endif
