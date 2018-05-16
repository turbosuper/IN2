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
 * ===  FUNCTION  ======================================================================
 *         Name: getMenu  
 *  Description: Erstellt die Menu bezueglich den Menu Array,und liefert Nummer der 
 *  		 ausgewehlte Element.Funktion kann auch ganzes Program schliessen.
 * 		-listet der letzte Element als '0'. 
 * 		-Ruckwert ist der Nummer der geweahlte Element (int).
 *
 * int getMenu(MenuTitel*, Elemente**, int Anzahl der Elemente)
 *		MenuTitel - pointer auf der char
 *		Elemente - pointer auf Array von vielen chars
 *		Anzahl der Elemente - Anzalh der dargestellte Elemente.
 * =====================================================================================
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
		if(i == numberOfItems-1){ //besonder Fall - letzte Postiion mit "00" darstellen
			printf("00. %s\n", *(menuItem+i));
	   }else{	
			printf("%02d. %s\n", i+1, *(menuItem+i));
				   };
		  };
	
	   // An der Zeile 16 der Wahl zeigen
           gotoXY(1,16); 
	   printf("\nIhrer Wahl: ");
	
	   //Tasttur Puffer Entleeren
	   kbclr();	
	
	   //Taste speichern
	   asciiVal = getch();	
	
	   //Taste ins Nummer aus der Wahlliste umwandeln
	   input = asciiVal - 48;
	
	   //Eine Meldung senden, wenn die Angabe stimmt nicht	
	   if (input > numberOfItems-1 || input < 0) { 
		printf("Keine gueltige Angabe. Bitte versuchen sie es erneut.\n\n\n");
		
	       	//Warten mit der Meldung
		sleep(2);
	       }
	
	   //Abprufen ob Program nicht beendet sein soll
	  // else if(input == 0 ){
	    //   printf("\n");
	//	_exit(0);	
	//	}
	   else {
		printf(" %d \n", input);
		}


	// So lange Menu wiederholen, bis eine Gultigie Angabe kommt vor
	} while ( input > numberOfItems-1 || input < 0); //|| input == 0);
	
	return input;
}

