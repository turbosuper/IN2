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
		"Neues Shiff hinzufuegen",
		"Vorhandenes Shiff loeschen",
		"Alle Shiffe auflisten",
		"NICHT FERTIG Sortieren",
		"Shiff suchen",
		"Geschwindigkeit",
		"LuftlinieNICHT FERTIG",
		"Beenden"};

//	Coordinates* position1; //test Koordinaten initialisiern
//	Coordinates* position2; //test Koordinaten initialisiern
//	position1 = (Coordinates*)malloc(sizeof(Coordinates));
//	position1->x = 2.3; //test Koordineten erstellen
//	position1->y = 2.3;
//	position1->z = 2.3;
//	strcpy(shipone->Name, "Anna Maria"); //Test shif erstellen
//	shipone->Speed = 4.5;
//	strcpy(shipone->Notes, "Sehr sehr");	
//	position2 = createPosition();
//	shipone->Position = position1;
//	shiptwo = createShip();


	Ship* shipone = NULL; //test Shiff initialisieren 

//	Ship* shiptwo = NULL;
//	shipone = (Ship*)malloc(sizeof(Ship));
//	shipone->Next = NULL;
//	shiptwo = (Ship*)malloc(sizeof(Ship));


	gotoXY(1,21);
 	while ((input = getMenu(menuTitel, menuItems, 8)) != 0){ ;
		switch(input){
			case 1: shipone = appendShip(shipone); break; //dummyFunc(); sleep(2); //shiptwo = createShip();  break;
			case 2: shipone = deleteShip(shipone); break;
			case 3: showAll(shipone); sleep(3); break;
			case 4: dummyFunc(); sleep(2); break; //shipone = appendShip(shipone);  break;
			case 5: findShip(shipone); sleep(2); break; //showAll(shipone); sleep(3); break;
			case 6: compareSpeed(shipone); sleep(3); break;
			case 7: showDistance(shipone); sleep(2); break;
			}
	}

	return EXIT_SUCCESS;
}
