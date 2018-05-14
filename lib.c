/*
 * =====================================================================================
 *
 *       Filename:  lib.c
 *
 *    Description:  Allgemeine Werkzeuge
 *
 * =====================================================================================
 */
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include "lib.h"

#define K_ESC 27
#define K_ENTER 13


void kbclr(void)
{
    while ( kbhit() ) getch();
}

// return 0 or 1
int kbhit(void)
{
   struct termios term, oterm;
   int fd = 0;
   int c = 0;
   tcgetattr(fd, &oterm);
   memcpy(&term, &oterm, sizeof(term));
   term.c_lflag = term.c_lflag & (!ICANON);
   term.c_cc[VMIN] = 0;
   term.c_cc[VTIME] = 1;
   tcsetattr(fd, TCSANOW, &term);
   c = getchar();
   tcsetattr(fd, TCSANOW, &oterm);
   if (c != -1)
   ungetc(c, stdin);
   return ((c != -1) ? 1 : 0);
}
 
int getch(void)
{
  struct termios oldt, newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}

// clear screen
void cls(void)
{
    printf("\e[2J\eH");
}

// go to the point (X,Y) on the screen
void gotoXY(int x, int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

/****************************************/

