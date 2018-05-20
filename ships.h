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

#endif   /* ----- #ifndef ships_INC  ----- */
