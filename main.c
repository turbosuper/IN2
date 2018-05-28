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
#define SLEEPTIME 3

int main(){
	int input;
	char *menuTitel = "Verwaltung der Schiffe";
	char *menuItems[] = {
		"Neues Shiff hinzufuegen",
		"Vorhandenes Shiff loeschen",
		"Alle Shiffe auflisten",
		"Sortieren",
		"Shiff suchen",
		"Geschwindigkeit",
		"Luftlinie",
		"Beenden"};



	Ship* shipone = NULL; //Kopf der Liste herstellen

	gotoXY(1,21);
 	while ((input = getMenu(menuTitel, menuItems, 8)) != 0){ ;
		switch(input){
			case 1: shipone = appendShip(shipone); break; //dummyFunc(); sleep(2); //shiptwo = createShip();  break;
			case 2: shipone = deleteShip(shipone); break;
			case 3: showAll(shipone); sleep(SLEEPTIME); break;
			case 4: shipone = sortShips(shipone); break; //shipone = appendShip(shipone);  break;
			case 5: findShip(shipone); sleep(SLEEPTIME); break; //showAll(shipone); sleep(3); break;
			case 6: compareSpeed(shipone); sleep(SLEEPTIME); break;
			case 7: showDistance(shipone); sleep(SLEEPTIME); break;
			}
	}

	return EXIT_SUCCESS;
}
