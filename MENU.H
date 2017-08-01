#include <sys/stat.h>
void readFile(char[]);
void createFile(char[],char[][MAXCOLS]);
void copyFile(char*,char*); 

void readFile(char fileName[])
{

	FILE *fp = fopen(fileName, "r");
	char s[501];

	if ( fp != NULL )
	{
		fseek(fp,0,SEEK_SET);
		printf(" ======== Contents of File %s ==========",fileName);
		printf (" is printed below ======\n");
		while ( fgets(s,500,fp) != NULL )
		{
			puts(s);
		}

	    fclose(fp);
	}
	else
	{
		printf( "\n File could not be opened to read... check fileName ..\n");
	}
	return;
}

void createFile(char fileName[],char buffer[MAXROWS][MAXCOLS])
{
	FILE *fp = fopen(fileName, "w");
	char c,*buf = malloc(sizeof(char*) * 500);
	int i=0;
	if ( fp != NULL )
	{
		for ( i = 0 ; i < MAXROWS && buffer[i][0] != '\0'; i++)
		{
			fputs(buffer[i],fp);
		}
		fclose(fp);
	}
	else
	{
		printf( "\n File could not be written ... check if u have permission  to write file..\n");
	}
}

void copyFile(char* srcFile, char* destFile) 
{
	FILE* src = fopen(srcFile, "r");
	if (src != NULL) 
	{	
		FILE* dest = fopen(destFile,"w");
		if ( dest != NULL ) 
		{
			char buf[81];
			while (fgets(buf,sizeof(buf), src) != NULL) {
				fputs(buf,dest);
			}
		
			if (feof(src))
				puts("\n File Copied done.");
			fclose(dest);
		}
		else 
		{ 
			printf( "\n ====== Unable to open destination file %s\n",destFile);
		}
		fclose(src);
	}
	else 
	{ 
			printf( "\n ====== Unable to open source file %s\n",srcFile);
	}
}