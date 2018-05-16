/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Haupt Datei der Program
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "lib.h"
#include "ships.h"
#include "datastructure.h"

int main(){
	int input;
	char *menuTitel = "Verwaltung der Schiffe";
	char *menuItems[] = {
		"Enizelnes Shiff zeigen",
		"Vorhandens Schiff loschen",
		"Alle Schiffe auflisten",
		"Beenden"};

	Ship* shipone; //test Shiff initialisieren 
	shipone = (Ship*)malloc(sizeof(Ship));

 	strcpy(shipone->Name, "Anna Maria"); //Test shif erstellen
	shipone->Speed = 4.5;
	strcpy(shipone->Notes, "Sehr sehr");	
	

	gotoXY(1,21);
 	input = getMenu(menuTitel, menuItems, 4) ;
		switch(input){
			case 1: showShip(shipone); break;
			case 2: dummyFunc(); break;
			case 3: dummyFunc(); break;
			}
		

	return EXIT_SUCCESS;
}
