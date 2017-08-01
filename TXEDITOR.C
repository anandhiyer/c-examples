#include <stdio.h>
#include <conio.h>

#define MAXROWS 25
#define MAXCOLS 81

#include "menu.h"
#include "keymap.h"

int ycoord = 2, xcoord = 1,row,col;
char buf[MAXROWS][MAXCOLS];

int setmenu()
{
	window(0,0,0,11);
	textcolor(WHITE);
	textbackground(BLACK);
	cprintf("Enter Text in Editor Space ...\r\n");
	_setcursortype(_NORMALCURSOR);
}


int getline()
{
  int c = 0;
  c = bioskey(0);
  if (c == '\n'&& row < MAXROWS )
	row++;
  if (c == '\b'&& col > 0)
	col--;
  if ( c == '-1')
	return 0;

  if (isalnum(c & 0xFF))
      printf("'%c'\n", c);
   else
      printf("%#02x\n", c);
  buf[row][col] = c;
  return 0;
}

int main()
{
	int count = 0,i;
	for (  i = 0 ; i < MAXROWS ; i ++ )
		buf[i][0] = '\0';
	clrscr();
	setmenu();
	gotoxy(xcoord,ycoord);
	do
	{
	  mapkey(getkey(), buf);
	} while (1);
}

