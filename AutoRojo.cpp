#include "AutoRojo.h"
#include <cstdlib>
#include <conio2.h>
#include <windows.h>
#include <iostream>
#include <cstdio>
using namespace std;

AutoRojo::AutoRojo(int vel, int x0, int y0) : Objetos(vel,x0,y0)
{
	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad; //cada cuanto se permite mover la pelotita 16 veces por segundo
	tempo=clock(); //inicializamos tempo con el reloj	
	
	int Color = 4;
	
	matriz[0][0]=219;  color[0][0] = Color;         
	matriz[0][1]=0; color[0][1] = Color ;
	matriz[0][2]=219; color[0][2] = Color;
	matriz[0][3]=0; color[0][3] = Color;
	matriz[1][0]=254;  color[1][0] = Color;
	matriz[1][1]=0; color[1][1] = Color;
	matriz[1][2]=254; color[1][2] = Color;
	matriz[1][3]=0; color[1][3] = Color;
	matriz[2][0]=219; color[2][0] = Color;
	matriz[2][1]=219; color[2][1] = Color;
	matriz[2][2]=219;  color[2][2] = Color;
	matriz[2][3]=219; color[2][3] = Color;
	matriz[3][0]=254;  color[3][0] = Color;
	matriz[3][1]=0; color[3][1] = Color;
	matriz[3][2]=254; color[3][2] = Color;
	matriz[3][3]=0; color[3][3] = Color;
	matriz[4][0]=219;  color[4][0] = Color;
	matriz[4][1]=0; color[4][1] = Color;
	matriz[4][2]=219; color[4][2] = Color;
	matriz[4][3]=0; color[4][3] = Color;
	
	
	ancho = 5;
	alto = 4;
	pasoX = 3;
	pasoY = 3;
	x = x0;
	y = y0;
	xnueva = x0;
	ynueva = y0;
	
	
	dibujar();
	
}


bool AutoRojo::update(){
	
	if (y<45){
		
		if(tempo+paso<clock()){
			
			// borro
			borrar();
			// muevo
			y++;
			// dibujo
			dibujar();
			
			borrar();
			x++;
			dibujar();
			
			tempo=clock(); // tomamos el tiempo para saber la proxima vez que movemos la pelotita
		}
		return true;
	}
	if (x>130)
	{
		borrar();
	}
	if (x<2)
	{
		borrar();
	}
	
	else{return false;};
	
}



