#ifndef AUTOROJO_H
#define AUTOROJO_H
#include "Objetos.h"
class AutoRojo : public Objetos
{
public:
	AutoRojo(int x0,int y0,int vel);
	AutoRojo(){};	
	bool update();		
};
#endif
