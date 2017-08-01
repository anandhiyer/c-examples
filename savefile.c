
#include <stdio.h> 
#include <stdlib.h>
#include "menu.h" 


int main(int argc, char* argv[]) 
{
	char* filename = "testfile.txt";
	char* destFile = "destfile.txt";

	int count=0,i=0;
	char *buf = malloc(sizeof(char*) * 80);
	
	print_menu();

	
	return 0; 
}