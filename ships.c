/*
 * =====================================================================================
 *
 *       Filename:  ships.c
 *
 *    Description:  Funktione zur Shiffe Verwaltung
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ships.h"
#include "lib.h"
#include "datastructure.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  dummFunc
 *  Description:  
 * =====================================================================================
 */
void dummyFunc(){
	printf("Noch nicht Fertig.\n");
}		/* -----  end of function dummFunc  ----- */


/* NOCH NICHT FERTIG 
 * ===  FUNCTION  ======================================================================
 *         Name:  getCoorditanes
 *  Description:  Liferet drei Koordinaten der Shiff zurueck
 *  Arguments:	  Zeiger auf der Struktur des Shiffes, deren Kooridanten angezeigt sein
 *  		  sollen
 *  Return value: Zeiger auf der Struktur Coordinates
 * =====================================================================================
 *
void showShip (Ship* Ship){
	printf("Name: %s, Geschwindigkeit %f, Notizen: %s \n", Ship->Name, Ship->Speed, Ship->Notes) ;
}		* -----  end of function showShip  ----- *
*/


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  createCoordinates
 *  Description:  Liest von Tastutur ab, und spiechert die Angaben in eine Postion struct
 *  Arguments:	  keine 
 *  Return value: Zeiger auf der Adresse wo die Koordinen gespiechert sind
 *
 * =====================================================================================
 */
Coordinates* createPosition()
{
	Coordinates* coordinates;
	coordinates = (Coordinates*)malloc(sizeof(Coordinates));

	printf("Bitte geben sie der Position X des Shiffes ein: \n");
	scanf("%f", &coordinates->x);
	printf("Bitte geben sie der Position Y des Shiffes ein: \n");
	scanf("%f", &coordinates->y);
	printf("Bitte geben sie der Position Z des Shiffes ein: \n");
	scanf("%f", &coordinates->z);
	return coordinates;
}		/* -----  end of function createCoordinates  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  createShip
 *  Description:  Liest von Tastutur ab, und spiechert die Angaben in eine Ship struct
 *  Arguments:	  keine 
 *  Return value: Zeiger auf der Adresse wo die Shiff gemacht ist

 *
 * =====================================================================================
 */
Ship* createShip ()
{
	Ship* ship;
	ship = (Ship*)malloc(sizeof(Ship));
	if (ship == NULL){
		printf("Keine Speicher Reservierung moeglich\n");
		exit(-1);
		}
	printf("Bitte geben sie der Name des Shiffes ein: (langste moegliche name ist %d Zeichen gross)\n", MAXNAME);
//	scanf("%[^\n]s", ship->Name);
	fgets(ship->Name, MAXNAME, stdin);
	kbclr();
	printf("Bitte geben sie die Geschwindigketi des Schiffes: \n");
	scanf("%f", &ship->Speed);
	kbclr();
	printf("Bitte geben sie die Notizen bezueglich der Shiff ein: (langste moegliche ist %d)\n", MAXNOTES);
//	scanf("%[^\n]s", ship->Notes);
	fgets(ship->Notes, MAXNOTES, stdin);
	ship->Position = createPosition();
	ship->Next = NULL;
	return ship;
}		/* -----  end of function createShip  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  showShip
 *  Description:  Alle Daten zu einen Shiff zeigen
 *  Arguments:	  Zeiger auf der Struktur der beinhaltet einen Shiff
 *  Return value: Keine
 * =====================================================================================
 */
void printPosition(Coordinates* position){
	printf("X: %f, Y %f, Z: %f \n", position->x, position->y, position->z) ;
}		/* -----  end of function showShip  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  printShip
 *  Description:  Alle Daten zu einen Shiff zeigen
 *  Arguments:	  Zeiger auf der Struktur der beinhaltet einen Shiff
 *  Return value: Keine
 * =====================================================================================
 */
void printShip (Ship* Ship){
	if (Ship != NULL){
 		printf("==================\n");
 		printf("Name: %sGeschwindigkeit %f \nNotizen: %s", Ship->Name, Ship->Speed, Ship->Notes) ;
		printf("Lage des Shiffes:");
		printPosition(Ship->Position);
		printf("\n");
		}
	else{
		printf("Keine Shiff zum Ausdruck (NULL POINTER)\n");
	}	
}		/* -----  end of function showShip  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  showAll
 *  Description:  Ziegt Alle Shiffe aus der Verkette Liste
 *  Arguments:	  Zeiger auf Anfang der Liste
 *  Return value: Keine
 * =====================================================================================
 */
void showAll (Ship* shipone)
{
	Ship* current = shipone;

	if (current == NULL){
		printf("Liste ist leer\n");
	}

	while(current != NULL){
		printShip(current);
		current = current->Next;
	}
}		/* -----  end of function showAll  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  appendShip
 *  Description:  Eine Neue Shiff addieren zu der letzter Platz in Verkette liste
 *  Arguments:	  Zeiger auf der Anfang der Verkette liste
 *  Return Value: Zeiger auf der erster Element 
 * =====================================================================================
 */
Ship* appendShip(Ship* shipone)
{
	Ship* new;
	
	Ship* current;
	Ship* prev;

	new = createShip();
	if (shipone == NULL){
		shipone = new; //das wird nicht gespiechert!!! bei Verlassen der Funktion es geht verloren :(
		}
	else {
		current = shipone;
		while(current != NULL){
			prev = current;
			current = current->Next;
			}
		prev->Next = new;
		}
	return shipone;
}		/* -----  end of function appendShip  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  getShip
 *  Description:  Liefert den Strukt Shiff zurueck
 *  Arguments:	  Zeiger auf Anfang der Liste, gesuchte Name des Shiffes
 *  Retunr Value: Zeiger auf dem Strukt mit der Shiff
 * =====================================================================================
 */

Ship* getShip (Ship* shipone, char keyword[MAXNAME])
{
	Ship* ship = shipone;
	Ship* ret = shipone;

	if (ship != NULL){
		while (ship != NULL && ret == NULL){
			if (ship->Name == keyword){
				ret = ship;
				}
			ship = ship->Next;
			}
		return ret;
	}
	else{
		printf("Liste ist leer\n");
		return NULL;
	}
}	
/* -----  end of function getShip  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  findShip
 *  Description:  Druck aus der gesuchte Shiff
 *  Arguments: 	  Zeiger auf Anfang der Liste
 *  Return value: Keine
 * =====================================================================================
 */
void findShip (Ship* shipone)
{
	
	char keyword[MAXNAME];

	printf("Bitte geben sie den gesuchte name in: \n");
	fgets(keyword, MAXNAME, stdin); 
	printf("Sie wollten dieser Shiff finden: %s \n", keyword);

	printShip(getShip(shipone, keyword));

}	
/* -----  end of function findShip  ----- */

/* ALTE VERSION FUNKTIONMIERT NICHT GUT
 * ===  FUNCTION  ======================================================================
 *         Name:  findShip
 *  Description:  Findet einen Shiff, mit die gegebene Name in eine Verkette Liste
 *  Arguments: 	  Zeiger auf anfang der Verkette Liste
 *  Return Value: Zeiger auf den Strukt mit den Shiff
 * =====================================================================================
 *
Ship* findShip(Ship* shipone)
{	
	Ship* ship = shipone;
	Ship* ret = shipone;
	char lookingfor[MAXNAME];

	if (ship != NULL){
		printf("Bitte geben sie den gesuchte name in: \n");
		fgets(lookingfor, MAXNAME, stdin); 
		printf("Sie wollten dieser Shiff finden: %s \n", lookingfor);
		while (ship != NULL && ret == NULL){
			if (ship->Name == lookingfor){
				ret = ship;
				}
			ship = ship->Next;
			}
		printShip(ret);
		return ret;
/  		else{
			printf("Tut mir leid,Schiff mti der gesuchte Name existiert nicht! \n");
			}
		return ship;
/
		}

	else{
		printf("List ist leer \n");
		return NULL;
		}
}	/ -----  end of function findShip  ----- */
