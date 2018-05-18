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
int addShip();
void printShip(Ship*);
void printPosition(Coordinates*);
Ship* createShip();
Coordinates* createPosition();

#endif   /* ----- #ifndef ships_INC  ----- */
