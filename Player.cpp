#include "Player.h"
#include <cstdlib>
#include <conio2.h>
#include <windows.h>
#include <iostream>
#include <cstdio>

using namespace std;

Player::Player(int vel, int x0, int y0) : Objetos(vel,x0,y0)
{
	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad; //cada cuanto se permite mover la pelotita 16 veces por segundo
	tempo=clock(); //inicializamos tempo con el reloj	
	
	int Color = 1;	
	
	matriz[0][0]=0;  color[0][0] = Color;
	matriz[0][1]=219; color[0][1] = Color ;
	matriz[0][2]=0; color[0][2] = Color;
	matriz[0][3]=219; color[0][3] = Color;
	matriz[1][0]=0;  color[1][0] = Color;
	matriz[1][1]=254; color[1][1] = Color;
	matriz[1][2]=00; color[1][2] = Color;
	matriz[1][3]=254; color[1][3] = Color;
	matriz[2][0]=219; color[2][0] = Color;
	matriz[2][1]=219; color[2][1] = Color;
	matriz[2][2]=219;  color[2][2] = Color;
	matriz[2][3]=219; color[2][3] = Color;
	matriz[3][0]=0;  color[3][0] = Color;
	matriz[3][1]=254; color[3][1] = Color;
	matriz[3][2]=0; color[3][2] = Color;
	matriz[3][3]=254; color[3][3] = Color;
	matriz[4][0]=0;  color[4][0] = Color;
	matriz[4][1]=219; color[4][1] = Color;
	matriz[4][2]=0; color[4][2] = Color;
	matriz[4][3]=219; color[4][3] = Color;
	
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


bool Player::update()
{
	if (_kbhit()){
		int tecla = getch();
		bool moves = false;
		
		switch(tecla){
		case (72): { // arriba
			if (y - alto > minLimitY ){borrar(); y = y - pasoY; moves = true;} break;
		}
		case (80):{ // abajo
			if (y < maxLimitY){borrar(); y = y + pasoY; moves = true;} break;
		}
		case (77):{ // derecha
			if (x + ancho < maxLimitX){borrar(); x = x + pasoX; moves = true;} break;
		}
		case (75):{ // izquierda
			if (x - ancho > minLimitX){borrar(); x = x - pasoX; moves = true;} break;
		}
		}
		
		if(moves) {
			dibujar();
		}
	}	
}


