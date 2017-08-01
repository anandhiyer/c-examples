#include <ctype.h>
#include <bios.h>
#include <conio.h>

#define RIGHT_ARROW   0x04d00
#define LEFT_ARROW 	  0x4b00
#define UP_ARROW      0x4800
#define DN_ARROW      0x5000
#define ENTER_KEY     0x1c0d
#define ALT_KEY       0x0800
#define BACKSPACE     0xe08
#define CTRLS         0x1f13
#define CTRLC		  0x2e03
#define F1			  0x3b00
#define F2			  0x3c00
#define F3 			  0x3d00
#define F4			  0x3e00
#define F5			  0x3f00
#define F6			  0x4000
#define F7			  0x4100
#define F8			  0x4200
#define F9			  0x4300
#define F10			  0x4400
#define F11			  0x4500
#define F12			  0x4600
#define ESC			  0x11b
#define DELETE		  0x5300
#define INSERT		  0x5200

int getkey();
void mapkey(int,char[MAXROWS][MAXCOLS]);
char buffer[4096];

int getkey()
{
    int key;

    key = bioskey(0);

    return key;
}

void mapkey(int key, char buf[MAXROWS][MAXCOLS])
{
   int x=1,y=2,count=0,i=0;
   char choice;
   x = wherex();
   y = wherey();
   switch(key)
   {
	case LEFT_ARROW:
		gotoxy (x-1,y);
		break;
	case UP_ARROW:
		gotoxy (x,y-1);
		break;
	case DN_ARROW:
		gotoxy (x,y+1);
		break;
	case RIGHT_ARROW:
		gotoxy (x+1,y);
		break;

	case ENTER_KEY:
		buf[y-2][x-1] = key & 0xFF;
		gotoxy (1,++y);
		break;

	case BACKSPACE:
		 buf[y-2][x-2] = ' ';
		 gotoxy(x-1,y);
		 /*
		 * save original cursor position
		 */
		 x=wherex();
		 putc(' ',stdout);
		 gotoxy(x,y);
		 break;

	case CTRLS:
		 createFile("C:\\TURBOC3\\PROJECTS\\tmp.txt", buf);
		 break;

	case CTRLC:
		exit(0);
		break;

	case DELETE:
		/* delete the current character */
		putc(' ',stdout);
		gotoxy(x,y);
		buf[y-2][x-1] = ' ';

	/*
	*  TODO
	*/
	case F1:
	case F2:
	case F3:
	case F4:
	case F5:
	case F6:
	case F7:
	case F8:
	case F9:
	case F10:
	case F11:
	case F12:
	case ESC:
			break;

	default:
		 key = key &0xFF;
		 /**
		  if empty string then make sure
		  fill with space if char is in middle
		  */
		 if ( buf[y-2][0] == '\0')
		 {
		   for ( i = 0 ; i < x-1; i++)
			  buf[y-2][i] = ' ';
		 }
		 buf[y-2][x-1] = key;
		 buf[y-2][MAXCOLS-1]='\0';
		 putc(buf[y-2][x-1],stdout);
		 break;
    }

    #ifdef _DEBUG_
	if (isalnum(key & 0xFF))
      printf("'%c'\n", key);
   else
      printf("%c %#02x\n", key&0xFF, key);
   #endif
}