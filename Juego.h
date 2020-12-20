#ifndef JUEGO_H
#define JUEGO_H
#include "Objetos.h"
#include "AutoAmarillo.h"
#include "AutoRojo.h"
#include "Player.h"
#include "Obstaculo.h"
#include "Level.h"

class Juego{
	
protected: 	
	int teclas[4];	
	int checkCollision();
	int puntos;	
	int nivel;
	Player *player;
	Objetos *auto_amarillo;
	Objetos *auto_rojo;		
	Objetos *obstaculo;
	Level *level;
public:	
	Juego();
	void play();
	void set_puntos(int _puntos);
	void set_nivel(int _nivel);
	int get_puntos();	
	void mostrar_puntos();
	void aumentar_puntos();
	void aumentar_velocidad();
	void mostrar_nivel();
	void aumentar_nivel();
	bool menu();
};

#endif


