/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Haupt Datei der Program
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "lib.h"

int main(){
	int input;
	char *menuTitel = "Verwaltung der Schiffe";
	char *menuItems[] = {
		"Neues Schiff hinzufgen",
		"Vorhandens Schiff loschen",
		"Alle Schiffe auflisten",
		"Beenden"};

	input = (getMenu(menuTitel, menuItems, 4));

	gotoXY(1,21);
	printf("Die von Ihnen gewahlet Menupoint ist: %s \n", menuItems[input-1] );
	
	
	return EXIT_SUCCESS;
}
