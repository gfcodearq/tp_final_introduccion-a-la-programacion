#include "Level.h"
#include <cstdlib>
#include <conio2.h>

#include <iostream>
#include <cstdio>
using namespace std;


Level::Level(int x0,int y0){
	int Color = 14;
	ancho = 130;
	alto = 45;
	x = x0;
	y =y0;
	
};

void Level::set_limit(int x0, int x1,int y0, int y1)
{
	maxLimitX = x1;
	maxLimitY = y1;
	minLimitX = x0;
	minLimitY = y0;
}

void Level::dibujar_level()
{
	for (int i=3;i<=maxLimitY;i++)
	{
		gotoxy(1,i);printf("*");	
		gotoxy(140,i);printf("*");
	}
}

void Level::borrar_level()
{
	for (int i=0;i<maxLimitX;i++)
	{
		textcolor(8);	
		putchxy(x+i,0,' '); 	
	}	
	for (int j=0;j<maxLimitX;j++)
	{
		textcolor(8);	
		putchxy(x+j,45,' '); 	
	}	
	for (int k=0;k<maxLimitY;k++)
	{
		textcolor(8);	
		putchxy(1,y+k,' '); 
	}
	for (int l=0;l<maxLimitY;l++)
	{
		textcolor(8);	
		putchxy(130,y+l,' '); 
	}
}
