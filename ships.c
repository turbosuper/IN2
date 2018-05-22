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
#include <string.h>
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
	printf("X: %4.3f, Y %4.3f, Z: %4.3f \n", position->x, position->y, position->z) ;
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
 		printf("Name: %sGeschwindigkeit %4.3f \nNotizen: %s", Ship->Name, Ship->Speed, Ship->Notes) ;
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
		shipone = new; 
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
	Ship* ret = NULL;

	if (ship != NULL){
		while (ship != NULL && ret == NULL){
			if (strcmp(ship->Name,keyword)== 0){
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

	if (getShip(shipone, keyword)== NULL){
		printf("Shiff mit der Name:  \n %sist nicht gefunden geworden \n", keyword);
		}
	else{
		printShip(getShip(shipone, keyword));
		}
}	
/* -----  end of function findShip  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  printName
 *  Description:  Funkion der gibt Name der Gegebene struct
 *  Arguments:    Zeiger auf dem Strukt mit Shiff
 *  Return value: Keine
 * =====================================================================================
 */
void printName (Ship* ship){
	if (ship == NULL){
		printf("Fehler, keine Shiff gegeben\n");
	}else{
		printf("%s\n", ship->Name);
	}
}		/* -----  end of function printName  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  deletShip
 *  Description:  Findet einen Shiff, dann loescht es (wenn es gefunden ist)
 *  Arguments: 	  Zeiger auf anfang der Verkette Liste
 *  Return Value: Zeiger auf Anfang der Verkette Liste
 * =====================================================================================
 *
 *
 */
Ship* deleteShip(Ship* shipone){
	Ship* current = shipone;
	Ship* temp;
	Ship* p = NULL;
	char keyword[MAXNAME];

	printf("Bitte geben sie Name der Shiff, der geloescht sein soll: \n");
	fgets(keyword, MAXNAME, stdin); 
	printf("Sie wollten dieser Shiff loeschen: %s \n", keyword);

	if (getShip(shipone, keyword)== NULL){
		printf("Shiff mit der Name:  \n%sist nicht gefunden geworden, da kann er auch nicht geloescht sein! \n", keyword);
		sleep(4);
		return shipone;
		}
	else{  
		while( current != NULL) {
			if(strcmp(current->Name,keyword) == 0){
				if (current == shipone ){ //zu loeschen ist die 1. Komponente
	        			temp = shipone;
					shipone = shipone->Next;
		        	}else{ //zu loeshjcen ist NICHT der erste Element
					temp = current;
					p->Next = current->Next;
			        	}
			free(temp);
			current = NULL; //Aufhoeren zu suchen
                	}else{
				p = current;
		                current = current->Next;}
		 }
	 return shipone;
	}
}	/* -----  end of function findShip  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  compareSpeed
 *  Description:  Fragt nach der eingabe, und listet Namen aller Shiffe die shneller/gleich sind
 *  Arguments:    Zeiger auf der Anfang der Liste
 *  Retrun Wert:  keine
 * =====================================================================================
 */
void compareSpeed (Ship* shipone){
	float speed;
	Ship* current = shipone;
	int i = 1;

	if( shipone == NULL ){
		printf("Liste ist leer\n");
	}else{
		printf("Bitte geben sie eine Geschwindigkeit, mit denem Shiffe vergleichen sein sollten: \n");
		scanf("%f", &speed);
		printf("Diese Shiffe sind schneller als %.4f : \n", speed);
		while(current != NULL){
			if (current->Speed >= speed){
				printf("%2d: ", i++);
				printName(current);
				}
			current = current->Next;
			}
		}
	
}		/* -----  end of function compareSpeed  ----- */
