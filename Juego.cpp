#include "Juego.h"
#include <cstdlib>
#include <conio2.h>
#include <iostream>
#include <cstdio>


using namespace std;


Juego::Juego(){
	

	player = new Player(10,45,45);
	player->setLimit(1,130,0,45);
	auto_amarillo = new AutoAmarillo(10,3,5);
	auto_amarillo->setLimit(3,130,0,45);
	auto_rojo = new AutoRojo(15,20,5);
	auto_rojo->setLimit(3,130,0,45);	
	obstaculo = new Obstaculo(10,10,5);
	obstaculo->setLimit(3,130,0,45);
	set_puntos(0);
	set_nivel(1);
	level = new Level(0,0);
	level->set_limit(0,135,0,50);
	
	
}

bool Juego::menu()
{
	auto_rojo->borrar();
	auto_amarillo->borrar();
	player->borrar();
	int opcion;	
	cout<<"STREET RACER - INTRODUCCION A LA PROGRAMACION "<<endl;
	cout<<"        Alumno:Fernandez, Guillermo"<<endl<<endl;
	cout<<"Las teclas de este juego son las direccionales del teclado izq-derecha-arriba-abajo"<<endl<<endl;
	cout<<"---------------------MENU---------------------"<<endl<<endl;
	cout<<"Ingrese por teclado una opcion"<<endl;
	cout<<"1)Jugar "<<endl;	
	
	cin>>opcion;
	
	switch(opcion)
	{
	case 1: 
		system("cls");
		level->dibujar_level();
		break;
	}
}

int Juego::checkCollision(){
	
	int x1 = player->getX();
	int y1 = player->getY();
	
	int x2 = auto_amarillo->getX();
	int y2 = auto_amarillo->getY();
	
	int x3 = auto_rojo->getX();
	int y3 = auto_rojo->getY();
	
	int x4 = obstaculo->getX();
	int y4 = obstaculo->getY();
	
	int ancho = 3;
	int alto = 4;
	
	
	if(x1 > (x2 - ancho) && x1 < (x2 + ancho) && 
	   y1 > (y2 - alto) && y1 < (y2 + alto))
	{return 2;}
	   
	   if(x1 > (x3 - ancho) && x1 < (x3 + ancho) && 
		  y1 > (y3 - alto) && y1 < (y3 + alto))
	   {return 3;}
		  
		  if(x1 > (x4 - ancho) && x1 < (x4 + ancho) && 
			 y1 > (y4 - alto) && y1 < (y4 + alto))
		  {return 4;}
		  
		  
		  return 0;
}

void Juego::set_puntos(int _puntos)
{
	puntos = _puntos;
}

void Juego::set_nivel(int _nivel)
{
	nivel = _nivel;
}

int Juego::get_puntos(){
	return puntos;
}

void Juego::aumentar_puntos()
{
	int y1 = player->getY();	
	int y2 = auto_amarillo->getY();
	int y3 = auto_rojo->getY();
	int y4 = obstaculo->getY();
	
	if (y3==45)
	{
	auto_rojo->borrar();
	puntos++;		
	}
	if (y2==45)
	{
		auto_amarillo->borrar();
		puntos++;		
	}
	if (y4==45)
	{
		obstaculo->borrar();
		puntos++;
	}
	
}

void Juego::aumentar_nivel()
{
		if(puntos>20 && puntos <40)
		{
			nivel = 2;
			aumentar_velocidad();
		}
		if(puntos>40 && puntos <60)
		{
			nivel = 3;
		}
		if(puntos>60 && puntos <80)
		{
			nivel = 4;
		}
}

void Juego::mostrar_puntos()
{
	textcolor(8);	
	gotoxy(1,1);
	cout<<"Puntos: "<<puntos<<endl;
}

void Juego::mostrar_nivel()
{
	textcolor(8);
	gotoxy(15,1);
	cout<<"Nivel: "<<nivel<<endl;
}

void Juego::aumentar_velocidad()
{
	switch(nivel)
	{
	case 2:		
		auto_rojo->set_velocidad(20);	
		auto_amarillo->set_velocidad(20);
		obstaculo->set_velocidad(20);
		break;
	case 3:
		auto_rojo->set_velocidad(30);	
		auto_amarillo->set_velocidad(30);
		obstaculo->set_velocidad(30);
		break;
	case 4: 
		auto_rojo->set_velocidad(40);	
		auto_amarillo->set_velocidad(40);
		obstaculo->set_velocidad(40);
		break;
	}
}



void Juego::play(){
	
	/**
	aca de debe ir una condicion de corte que finalice el juego
	en un juego con interacciones se suele hacer un while true y corta
	alguna accion en el juego: vida = 0; alguna tecla, etc.
	En este ejemplo el metodo update dira cuando cortar cuando
	el contador llegue a 0 lanzara un false
	**/
	
	
	menu();
	
	
	bool flag = true;
	while(flag) {
		
		mostrar_puntos();	
		mostrar_nivel();
		player->update();		
		auto_amarillo->update();
		auto_rojo->update();
		obstaculo->update();	
		aumentar_puntos();		
		aumentar_nivel();		
		auto_amarillo->desaparecer();
		auto_rojo->desaparecer();
		obstaculo->desaparecer();
		aumentar_velocidad();
		
				
		if (checkCollision() == 2){ // si choco con el auto amarillo se cierra el juego
			flag = false;
		}
		
		if (checkCollision() == 3){ // si choco con el auto rojo se cierra el juego
			flag = false;
		}	
		
		if (checkCollision() == 4){ // si choco con el obstaculo se cierra el juego
			flag = false;
		}	
		
		
		
		
	}
	//cuando termina el juego

	system ("cls");
	gotoxy (65,44);
	cout<<"game over"<<endl;
	gotoxy(65,45);
	cout<<"puntos: "<<puntos<<endl;
	
}
