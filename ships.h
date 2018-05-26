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
void showDistance (Ship* shipone );
Coordinates* getPosition(Ship* ship);
float calculateDistance(Coordinates* position1, Coordinates* position2);
Ship* sortShips(Ship* shipone);
Ship* swapShips(Ship* ship1, Ship* ship2);
	
#endif   /* ----- #ifndef ships_INC  ----- */
