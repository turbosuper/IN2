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
#include "ships.h"
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
	printPosition(Ship->Coordinates);
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
void printPosition(Position* position){
	printf("X: %f, Y %f, Z: %f \n", position->x, position->y, position->z) ;
}		/* -----  end of function showShip  ----- */
