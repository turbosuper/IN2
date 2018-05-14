/*
 * =====================================================================================
 *
 *       Filename:  tools.c
 *
 *    Description:  Werkzeuge
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

/* Clear Screen - leert den Bildschirm */

void clearScreen(){
	#ifdef __unix__
		#define clrscreen() system("clear") //Linux Kommando fuer ClearScreen
	#else
		#define clrscreen() system("CLS") //Windows Kommando fuer ClearScreen
	#endif 

	clrscreen(); //Aufruf der o.g. Funktion
	}
