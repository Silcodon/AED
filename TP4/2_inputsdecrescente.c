#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


#define RAND_MAX 10000000

int main() {
	int n;
	int r;
	int* array;
	char filename[100]="input";
	char Sizee[400]="";
	char number[400]="";
	char nome[400]="";
	char buff[400]="";
	srand(time(NULL));   // Initialization, should only be called once.
	
	n=500000;
	for(int j=0;j<20;j++){
		sprintf(Sizee, "%d\n", n);
		sprintf(filename,"%d.txt",j);
		FILE *f = fopen(filename, "w+");
		fputs(Sizee, f);

		array = (int*) malloc(n * sizeof(int));
		for(int i=n; i>0;i--){
			r=i%(RAND_MAX+1);
			sprintf(nome, "%d", r);
			strcat(buff,nome);
			strcat(buff,"\n");
			fputs(buff,f);
			strcpy(buff,"");
			strcpy(nome,"");
		}
		
		fclose(f);
		n+=500000;
		free(array);
		memset(Sizee,0,sizeof(Sizee));
		memset(filename,0,sizeof(filename));
	}
	

	return 0;
}