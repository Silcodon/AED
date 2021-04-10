#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


#define RAND_MAX 25

int main() {
	int n_total=100000;
	float insertratio=0.2;
	int ninserir=n_total*insertratio;
	int nconsulta=n_total-ninserir;
	//percentagem das consultas, 0.9 para 90% das consultas terem x consultas.
	float consultaratio=0.9;
	//=0.05 para 5%, =1 para todos terem o mesmo acesso
	float ratioconsultas=1;
	int percentagemconsultas=nconsulta*consultaratio;
	int consulta2=ninserir*ratioconsultas;
	char filename[100]="input";
   	char buff[3000]="";
	char Sizee[400]="";
	char number[400]="";
	char nome[50]="";
	int r;
	srand(time(NULL));   // Initialization, should only be called once.
	
	for(int j=0;j<10;j++){
		percentagemconsultas=nconsulta*consultaratio;
		consulta2=ninserir*ratioconsultas;
		sprintf(filename,"%d.txt",j);
		FILE *f = fopen(filename, "w+");
		for(int i=0; i<ninserir;i++){
				sprintf(nome, "%d", i);
				strcat(buff,"ACRESCENTA ");
				strcat(buff,nome);
				strcat(buff," Rua Dourada 19");
				fputs(buff,f);
			
			fputs("\n",f);
			strcpy(buff,"");
			strcpy(nome,"");
		}
		for(int i=0; i<percentagemconsultas;i++){
			int r=i%consulta2;
				sprintf(nome, "%d",r);
				strcat(buff,"CONSULTA ");
				strcat(buff,nome);
				fputs(buff,f);
			
			fputs("\n",f);
			strcpy(buff,"");
			strcpy(nome,"");
		}
		for(int i=0; i<nconsulta-percentagemconsultas;i++){
			int r=i%ninserir;
				sprintf(nome, "%d",r);
				strcat(buff,"CONSULTA ");
				strcat(buff,nome);
				fputs(buff,f);
			
			fputs("\n",f);
			strcpy(buff,"");
			strcpy(nome,"");
		}
		
		fclose(f);
		ninserir+=ninserir/2;
		nconsulta+=nconsulta/2;
	}
	

	return 0;
}