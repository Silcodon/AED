#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


#define RAND_MAX 999999999999

int main() {
	int n;
	int* array;
	char filename[100]="input";
	char Sizee[400]="";
	char number[400]="";
	srand(time(NULL));   // Initialization, should only be called once.
	
	n=1000000;
	for(int j=0;j<10;j++){
		sprintf(Sizee, "%d\n", n);
		sprintf(filename,"%d.txt",j);
		FILE *f = fopen(filename, "w+");
		fputs(Sizee, f);

		array = (int*) malloc(n * sizeof(int));
		for(int i=0; i<n;i++){
			sprintf(number,"%lld ",rand());
			fputs(number,f);
		}
		
		fclose(f);
		n+=500000;
		free(array);
		memset(Sizee,0,sizeof(Sizee));
		memset(filename,0,sizeof(filename));
	}
	

	return 0;
}