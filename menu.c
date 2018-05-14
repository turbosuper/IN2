/*
 * =====================================================================================
 *
 *       Filename:  menu.c
 *
 *    Description: Funktionen der Menu 
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "menu.h"

/* 
 *getMenu - erstellt die Menu bezueglich den Menu Array,
 * 	listet der letzte Element als '0', Ruckwert ist
 * 	der Nummer der gewahlte Element (int).
 *
 * getMenu(MenuTitel, Elemente, Anzahl der Elemente)
 *	MenuTitel - pointer auf der char
 *	Elemente - pointer auf Array von vielen chars
 *	Anzahl der Elemente - Anzalh der dargestellte 
 *	Elemente.
 */
int getMenu(char *titel, char **menuItem, int numberOfItems){
	int input=0, i, asciiVal;

	do{	
	cls();
	gotoXY(1,1); //Menu an Anfang der Leere Bildschirm stellen

	/* Menutitel darstellen */
	printf("%s\n", titel);
	printf("\n");

	/*Menu aus der Array auflisten*/
	for (i = 0; i < numberOfItems; i++){
		if(i == numberOfItems-1){
			printf("00. %s\n", *(menuItem+i));
	}else{	
			printf("%02d. %s\n", i+1, *(menuItem+i));
				   };
		  };

	gotoXY(1,16); // An der Zeile 16 der Wahl zeigen
	printf("\nIhrer Wahl: ");
	kbclr(); //Tasttur Puffer Entleeren
	asciiVal = getch(); //Taste speichern
	input = asciiVal - 48; //Taste ins Nummer aus der Wahlliste umwandeln
	if (input > numberOfItems-1 || input < 0) { //Eine Meldung senden, wenn die Angabe stimmt nicht	
		printf("Keine gueltige Angabe. Bitte versuchen sie es erneut.\n\n\n");
		sleep(2); //Warten mit der Meldung
		}
	else {
	printf(" %d \n", input);
		}
	} while ( input > numberOfItems || input < 0 || input == 0);// So lange Menu wiederholen, bis eine Gultigie Angabe kommt vor
	return input;
}

