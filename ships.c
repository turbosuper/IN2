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
 *         Name:  showShip
 *  Description:  Alle Daten zu einen Shiff zeigen
 *  Arguments:	  Zeiger auf der Struktur der beinhaltet einen Shiff
 *  Return value: Keine
 * =====================================================================================
 */
void showShip (Ship* Ship){
	printf("Name: %s, Geschwindigkeit %f, Notizen: %s \n", Ship->Name, Ship->Speed, Ship->Notes) ;
}		/* -----  end of function showShip  ----- */
