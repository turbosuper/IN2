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
#include <stdlib.h>
#include "ships.h"
#include "lib.h"
#include "datastructure.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  addShip
 *  Description:  Eine Neue Shiff addieren zu der letzter Platz in Verkette liste
 *  Arguments:	  Zeiger auf der Anfang der Verkette liste
 *  Return Value: Keine
 * =====================================================================================
 */
int addShip ()
{
	return 0;
}		/* -----  end of function addShip  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  dummFunc
 *  Description:  
 * =====================================================================================
 */
void dummyFunc(){
	printf("Noch nicht Fertig.\n");
}		/* -----  end of function dummFunc  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  printShip
 *  Description:  Alle Daten zu einen Shiff zeigen
 *  Arguments:	  Zeiger auf der Struktur der beinhaltet einen Shiff
 *  Return value: Keine
 * =====================================================================================
 */
void printShip (Ship* Ship){
	printf("Name: %s, Geschwindigkeit %f, Notizen: %s \n", Ship->Name, Ship->Speed, Ship->Notes) ;
	printf("Lage des Shiffes:");
	printPosition(Ship->Position);
}		/* -----  end of function showShip  ----- */

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
	printf("Bitte geben sie der Name des Shiffes ein: (langste moegliche name ist %d Zeichen gross)\n", MAXNAME);
	scanf("%[^\n]s", ship->Name);
	kbclr();
	printf("Bitte geben sie die Geschwindigketi des Schiffes: \n");
	scanf("%f", &ship->Speed);
	kbclr();
	printf("Bitte geben sie die Notizen bezueglich der Shiff ein: (langste moegliche ist %d)\n", MAXNOTES);
	scanf("%[^\n]s", ship->Notes);
	ship->Position = createPosition();
	return ship;
}		/* -----  end of function createShip  ----- */
