
#include <conio.h>
#include <graphics.h>
#include<dos.h>

int main()
{
	char str[10];
	union REGS i, o;
	int gd = DETECT, gm,poly[10];
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	poly[0] = 10;
	poly[1] = 10;
	poly[2] = getmaxx()-10;
	poly[3] = 10;
	poly[4] = getmaxx()-10;
	poly[5] = getmaxy()-10;
	poly[6] = 10;
	poly[7] = getmaxy()-10;
	poly[8] = poly[9] = 10;
	drawpoly(5,poly);
	getchar();
	closegraph();
	return 0;
}
