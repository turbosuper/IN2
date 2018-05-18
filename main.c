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
#include <unistd.h>
#include <string.h>
#include "menu.h"
#include "lib.h"
#include "ships.h"
#include "datastructure.h"

int main(){
	int input;
	char *menuTitel = "Verwaltung der Schiffe";
	char *menuItems[] = {
		"Neues Shif anlegen",
		"Die gespeichrte Shiff Zeigen",
		"Alle Schiffe auflisten",
		"Beenden"};

//	Coordinates* position1; //test Koordinaten initialisiern
//	Coordinates* position2; //test Koordinaten initialisiern
//	position1 = (Coordinates*)malloc(sizeof(Coordinates));


//	position1->x = 2.3; //test Koordineten erstellen
//	position1->y = 2.3;
//	position1->z = 2.3;

//	Ship* shipone; //test Shiff initialisieren 
	Ship* shiptwo;
//	shipone = (Ship*)malloc(sizeof(Ship));
	shiptwo = (Ship*)malloc(sizeof(Ship));

 //	strcpy(shipone->Name, "Anna Maria"); //Test shif erstellen
//	shipone->Speed = 4.5;
//	strcpy(shipone->Notes, "Sehr sehr");	
	
//	position2 = createPosition();
//	shipone->Position = position1;

//	shiptwo = createShip();

	gotoXY(1,21);
 	while ((input = getMenu(menuTitel, menuItems, 4)) != 0){ ;
		switch(input){
			case 1: shiptwo = createShip();  break;
			case 2: printShip(shiptwo); sleep(2); break;
			case 3: dummyFunc(); break;
			}
	}

	return EXIT_SUCCESS;
}
