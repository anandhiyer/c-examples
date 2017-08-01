
#include <conio.h>

int main(void)
{
   struct text_info ti;
   unsigned char a;
   clrscr();

/*window(10,10,40,11);
textcolor(BLACK);
textbackground(WHITE);
cprintf("This is a test\r\n");
 _setcursortype(_SOLIDCURSOR);
*/

   gettextinfo(&ti);
   cprintf("window left      %2d\r\n",ti.winleft);
   cprintf("window top       %2d\r\n",ti.wintop);
   cprintf("window right     %2d\r\n",ti.winright);
   cprintf("window bottom    %2d\r\n",ti.winbottom);
   cprintf("attribute        %2d\r\n",ti.attribute);
   cprintf("normal attribute %2d\r\n",ti.normattr);
   cprintf("current mode     %2d\r\n",ti.currmode);
   cprintf("screen height    %2d\r\n",ti.screenheight);
   cprintf("screen width     %2d\r\n",ti.screenwidth);
   cprintf("current x        %d\r\n",ti.curx);
   cprintf("current y        %2d\r\n",ti.cury);

   scanf("%c",&a);
   printf( " char is :%d , %c ",a, a);
   getch();
   return 0;
}
