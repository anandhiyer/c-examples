
#include <conio.h>

int main(void)
{
   int i, j;

   clrscr();
   clrscr();
   for (i=0; i<9; i++)
   {
       for (j=0; j<80; j++)
	  cprintf("C");
       cprintf("\r\n");
       textcolor(i+1);
       textbackground(i);

   }


   gotoxy(5,5);
   /*
   textbackground(BLACK);
   textcolor(BLUE+BLINK);
   */
   getch();
   return 0;
}
