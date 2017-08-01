#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

struct BitMap
{
	char b_type[2];
	unsigned long b_size;
	unsigned long b_reserved;
	unsigned long b_offset;
	unsigned long b_headerSize;
	unsigned long b_width;
	unsigned long b_height;
	int b_planes;
	int b_bitsPerPixel;
	unsigned long b_compression;
	unsigned long b_dataSize;
	unsigned long b_XpixelsHorizontal;
	unsigned long b_YpixelsVertical;
	unsigned long b_paletteColor;
	unsigned long b_colorsData;
};

int main()
{
	int gd= VGA, gm = VGAHI,a,b,in;
	int x = 320, y = 240, radius=20;
	FILE *fp;
	struct BitMap bmp;
	unsigned char c;
	char *buf = calloc(sizeof(char*), sizeof(char)*81);
	unsigned char* Datas;
	initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");
	/*
	circle(x,y,radius);
	getchar();
	*/
	cleardevice();
	fp = fopen("C:\\TURBOC3\\IMAGES\\GPS.BMP", "rb");
	/*
	sprintf(buf, " fp is %d", (fp == NULL));
	outtext( buf);
	*/
	getchar();
	if(fp != NULL)
	{
		fread(&bmp, sizeof(bmp),1,fp);
		sprintf(buf,"The type of bitmap is %s", bmp.b_bitsPerPixel);
		outtext(buf);
		fseek(fp,bmp.b_offset,SEEK_SET);
		Datas=(unsigned char*) calloc(bmp.b_width+1, sizeof(unsigned char));
		for(b=bmp.b_height;b>=0;b--)
		{
			fread(Datas, sizeof(unsigned char), bmp.b_width, fp);
			c=0;
			in=0;
			for(a=0;a<=bmp.b_width;a+=1)
			{
				/*
				c = (Datas[in] | 0x00) >>4;
				*/
				c = Datas[in];
				putpixel(a+x,b+y,c);
				/*
				c = (Datas[in] | 0xF0) & 0x0F;
				*/
				c = Datas[in];
				putpixel(a+1+x,b+y,c);
				in++;
			}
		}
    free (Datas);

	}
	fclose(fp);
	getchar();
	closegraph();

}

