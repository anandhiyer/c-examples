
#include <conio.h>
#include <stdio.h>
#include <bios.h>
#include <ctype.h>

#define RIGHT_ARROW   0x04d00
#define LEFT_ARROW 0x4b00
#define UP_ARROW 0x4800
#define DN_ARROW 0x5000

#define ALT    0x0800

int main(void)
{
   int key, modifiers,x,y,count=0;
   struct text_info ti;
   clrscr();
   /* function 1 returns 0 until a key is pressed */
   while (bioskey(1) == 0);

   /* function 0 returns the key that is waiting */
   do {
   key = bioskey(0);
   printf( " key is :: %x \n",key);
   gettextinfo(&ti);
   x = ti.curx;
   y = ti.cury;
   switch(key)
   {
	case LEFT_ARROW:
		printf("LEFT ARROW PRESSED");
		gotoxy (x-1,y);
		break;
	case UP_ARROW:
		printf("UP ARROW PRESSED");
		gotoxy (x,y-1);
		break;
	case DN_ARROW:
		printf("DOWN ARROW KEY PRESSED");
		gotoxy (x,y+1);
		break;
	case RIGHT_ARROW:
		printf("RIGHT ARROW KEY PRESSED");
		gotoxy (x+1,y);
		break;

    }
    count++;
    } while (count < 4);
   /* use function 2 to determine if shift keys were used */
   /*modifiers = bioskey(2);
   if (modifiers)
   {
      printf("[");
      if (modifiers & RIGHT) printf("RIGHT");
      if (modifiers & LEFT)  printf("LEFT");
      if (modifiers & CTRL)  printf("CTRL");
      if (modifiers & ALT)   printf("ALT");
      printf("]");
   }
   */
   /* print out the character read */
   /*if (isalnum(key & 0xFF))
      printf("'%c'\n", key);
   else
      printf("%#02x\n", key);
   */
   getchar();
   return 0;
}
