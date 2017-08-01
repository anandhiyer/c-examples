
#include <stdio.h> 
#include <stdlib.h>
#include "menu.h" 
void closeFile(FILE* fp) ;
FILE* openFile(char* filename) ;
int saveFile(FILE* fp, char* buf) ;
int copyFile(char*,char*); 

int main(int argc, char* argv[]) 
{
	char* filename = "testfile.txt";
	char* destFile = "destfile.txt";

	int count=0,i=0;
	char *buf = malloc(sizeof(char*) * 80);
	
	print_menu();
	/* scanf terminates after a space
	scanf ( "%s", buf);
	*/
	/*
	FILE *fp;
	
	gets(buf);
	
	printf( "%s" ,buf);
	
	
	fp = openFile(filename);
			printf( " Source file opened :: %d\n", fp);

	saveFile(fp,buf);
    char s[500];
	closeFile(fp);

	fp = fopen(filename, "r");
	*/
	/*
	fseek(fp,0,SEEK_SET);
	*/
	/*
	while ( fgets(s,500,fp) != NULL ) 
		printf( " file contents %s", s);
	
	closeFile(fp);
	
	free(buf);
	printf ( " Copy file called %s\n",filename );
	
	
	copyFile(filename,destFile);
	*/
	
	return 0; 
}

void closeFile(FILE* fp) 
{
	fclose(fp);

}

FILE* openFile(char* filename) 
{
	FILE *fp;
	
	fp = fopen(filename, "a");
	return fp;
}

int saveFile(FILE* fp, char* buf) 
{
	fputs(buf,fp);
}

int copyFile(char* srcFile, char* destFile) 
{
    printf ( " Copy file called %s \n",srcFile );
	
	FILE* src;
	src = fopen(srcFile, "r");
	FILE* dest = openFile(destFile);
	if (src != NULL) 
		printf( " Source file opened :: %d\n", src);
	int len = 10;
	
    char buf[80];
    while (fgets(buf,len, src) != NULL) {
		printf( " Files opened ::  %s \n",buf); 
		saveFile(dest,buf);
	
	}
	if (feof(src))
       puts("End of file was reached.");
	/*while( feof(src) != EOF)
	{	
		fgets(buf,len, src);
		printf("%s", buf);
		saveFile(dest,buf);
	}
	
	closeFile(src);
	closeFile(dest);
	*/
}