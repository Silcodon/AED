#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


#define RAND_MAX 25

int main() {
	int n_total=10000;
	float insertratio=0.9;
	int ninserir=n_total*insertratio;
	int nconsulta=n_total-ninserir;
	char filename[100]="input";
   	char buff[3000]="";
	char Sizee[400]="";
	char number[400]="";
	char nome[50]="";
	
	int r;
	srand(time(NULL));   // Initialization, should only be called once.
	
	for(int j=0;j<10;j++){
		sprintf(filename,"%d.txt",j);
		FILE *f = fopen(filename, "w+");
		for(int i=0; i<ninserir;i++){
				sprintf(nome, "%d", i);
				strcat(buff,"ACRESCENTA ");
				strcat(buff,nome);
				strcat(buff," covid 18/02/1999");
				fputs(buff,f);
			
			fputs("\n",f);
			strcpy(buff,"");
			strcpy(nome,"");
		}
		for(int i=0; i<nconsulta;i++){
				int r= i%(ninserir-1);
				sprintf(nome, "%d",r);
				strcat(buff,"CONSULTA ");
				strcat(buff,nome);
				fputs(buff,f);
			fputs("\n",f);
			strcpy(buff,"");
			strcpy(nome,"");
		}
		
		fclose(f);
		ninserir+=ninserir;
		nconsulta+=nconsulta;
	}
	

	return 0;
}