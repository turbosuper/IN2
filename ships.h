/*
 * =====================================================================================
 *
 *       Filename:  ships.h
 *
 *    Description:  Header Datei fuer die Funktionen der Shiff Verwaltung
 * =====================================================================================
 */

#ifndef SHIPS_H 
#define SHIPS_H 
#include "datastructure.h"


void dummyFunc();
Ship* appendShip(Ship*);
void printShip(Ship*);
void printPosition(Coordinates*);
Ship* createShip();
Coordinates* createPosition();
void showAll(Ship*);
//Ship* findShip(Ship*);
void findShip(Ship*);
Ship* getShip (Ship* shipone, char keyword[MAXNAME]);
Ship* deleteShip(Ship*);
void compareSpeed (Ship* shipone);
void printName (Ship* ship);
	
#endif   /* ----- #ifndef ships_INC  ----- */
