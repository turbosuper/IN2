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

typedef struct{
	float x;
	float y;
	float z;
}position;

typedef struct{
	char Name[26];
//	position Cooridanates;
	float Speed;
	char Notes[40];
	struct Ship* Next;
}Ship;

#endif   /* ----- #ifndef datastructure_INC  ----- */
