/*
 * =====================================================================================
 *
 *       Filename:  datastructure.h
 *
 *    Description:  Datenstrukturen
 * =====================================================================================
 */

#ifndef  DATASTRUCTRE_H
#define  DATASTRUCTRE_H
#define MAXNAME 26
#define MAXNOTES 40
typedef struct{
	float x;
	float y;
	float z;
}Coordinates;

typedef struct Ship{
	char Name[MAXNAME];
	Coordinates* Position;
	float Speed;
	char Notes[MAXNOTES];
	struct Ship* Next;
}Ship;

#endif   /* ----- #ifndef datastructure_INC  ----- */
