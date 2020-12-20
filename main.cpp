#include<iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "Juego.h"

using namespace std;

int main (int argc, char *argv[]) {
	srand(time(NULL));
	
	Juego  *J = new Juego;
	J->play();	
	
	return 0;
}


