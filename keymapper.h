#define RIGHT_ARROW   0x04d00
#define LEFT_ARROW 	  0x4b00
#define UP_ARROW      0x4800
#define DN_ARROW      0x5000
#define ENTER_KEY     0x1c0d
#define ALT_KEY    0x0800

int getkey();
void mapkey(int);

int getkey() 
{
	/* function 1 returns 0 until a key is pressed */
    while (bioskey(1) == 0);

	key = bisokey(0); 
	
	return key;
}

void mapkey(int key) 
{
   int key, modifiers,x,y,count=0;
   struct text_info ti;
   clrscr();
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

	case ENTER_KEY:
		printf("ENTER ARROW KEY PRESSED");
		gotoxy (x+1,0);
		break;
    }
}