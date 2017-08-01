#include <stdio.h> 

int main () 
{
/*  pointer example */
	int x = 4; 
	int *p = &x;
	
	printf ( " x is %d %d ", x, *p);
	printf( " Enter a value ::" ); 
	scanf ( "%d", &x);
	printf( " %d \n", *p);
	getchar();
	return 0;
}