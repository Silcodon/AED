#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define MAX 1000000

void printArray(int array[MAX],int n){
	for(int i=0;i<n;i++){
		printf("%d\n", array[i]);
	}
}


//BSS com regra de incremento de potencias de 2 (2^n)
void BaseShellSort(int array[MAX], int n){
	int intervalo=1;
	while(intervalo<n){
		intervalo=intervalo*2;
	}
	//intervalo=128;
	int aux;
	//Por cada elemento no array
	while(intervalo>0){
		//Insertion sort por cada subarray
		for(int j=intervalo;j<n;j++){
			int k;
			aux=array[j];
			for(k=j;k>=intervalo && array[k-intervalo] > aux;k-=intervalo){
				
					array[k]=array[k-intervalo];
				
			}
			array[k]=aux;
		}
		//atualiza intervalo
		intervalo=intervalo/2;
	}
	//printArray(array,n);
}


//ISS com regra de incremento N/2 com inicio em N-1 (para trocar o primeiro com ultimo elemento)
void ImprovedShellSortI(int array[MAX], int n){
	int intervalo=n-1;
	//intervalo=128;
	//int swaps=0;
	int aux;


	//Por cada elemento no array
	while(intervalo>0){
		//Insertion sort por cada subarray
		for(int j=intervalo;j<n;j++){
			int k;
			aux=array[j];
			for(k=j;k>=intervalo && array[k-intervalo] > aux;k-=intervalo){
				
					array[k]=array[k-intervalo];
					
				
			}
			array[k]=aux;
		}
		//atualiza intervalo
		intervalo=intervalo/2;
	}
	//printArray(array,n);
	//printf("%d\n", swaps);
	//printArray(array,n);
}


//ISS com regra de incremento a dividir por 2.2 e com valor inicial N/2
void ImprovedShellSortII(int array[MAX], int n){
	int intervalo=n/2.2;
	//intervalo=128;
	
	//int swaps=0;
	int aux;
	//Por cada elemento no array
	while(intervalo>0){
		//Insertion sort por cada subarray
		for(int j=intervalo;j<n;j++){
			int k;
			aux=array[j];
			for(k=j;k>=intervalo && array[k-intervalo] > aux;k-=intervalo){
				
					array[k]=array[k-intervalo];
					
				
			}
			array[k]=aux;
		}
		//atualiza intervalo
		intervalo=intervalo/2.2;
	}
	//printArray(array,n);
	//printf("%d\n", swaps);
}



//ISS com regra de incremento sequencia de Sedgewick I
void ImprovedShellSortIII(int array[MAX], int n){
	int intervalo=1;
	int *incrementos=(int*) malloc(n * sizeof(int));;
	int i=1;
	int j=0;
	incrementos[0]=0;
	incrementos[1]=1;
	//intervalo=128;
	while(incrementos[i] < n){
		i++;
		incrementos[i]= pow(4,(j+1)) + 3*pow(2,j) + 1;	
		j++;
		
	}
	intervalo=incrementos[i];
	int aux;
	//Por cada elemento no array
	while(intervalo>0){
		//Insertion sort por cada subarray
		for(int j=intervalo;j<n;j++){
			int k;
			aux=array[j];
			for(k=j;k>=intervalo && array[k-intervalo] > aux;k-=intervalo){
				array[k]=array[k-intervalo];
			}
			array[k]=aux;
		}
		//atualiza intervalo
		i--;
		//printf("%d\n", intervalo);
		intervalo=incrementos[i];
	}
	//printArray(array,n);
}



//ISS com regra de incremento baseado na sequencia de Knuth, valor inicial é o maior valor antes de N/3 com a sequencia de incremento 3*h+1.
void ImprovedShellSortIV(int array[MAX], int n){
	int intervalo=1;
	while(intervalo<n){
		intervalo=intervalo*3+1;
	}
	//intervalo=128;
	int aux;
	//Por cada elemento no array
	while(intervalo>0){
		//Insertion sort por cada subarray
		for(int j=intervalo;j<n;j++){
			int k;
			aux=array[j];
			for(k=j;k>=intervalo && array[k-intervalo] > aux;k-=intervalo){
				
					array[k]=array[k-intervalo];
				
			}
			array[k]=aux;
		}
		//atualiza intervalo
		//printf("%d\n", intervalo);
		intervalo=intervalo/3;
	}
	//printArray(array,n);
}








int main() {
	int n;
	int* array, *arrayaux;
	FILE *fp;
   	char buff[255]="";
   	char Time[50];
   	char Sizee[12];
   	char versao[50];
   	clock_t begin;
	clock_t end;
	double time_spent;


	scanf("%d", &n);
	//Ler dados
	array = (int*) malloc(n * sizeof(int));
	arrayaux= (int*) malloc(n * sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d\n", &array[i]);
	}
	for(int i=0;i<n;i++){
		arrayaux[i]=array[i];
	}


	//Base Shell Sort
	strcpy(versao,"BSS");
	//printf("BSS\n");
	begin = clock();

	BaseShellSort(arrayaux,n);
	//printArray(array,n);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("ATimes.txt","a");
	strcat(buff,"\nSize: ");
	strcat(buff,Sizee);
	strcat(buff," ,Time: ");
	strcat(buff,Time);
	strcat(buff," ,Versao: ");
	strcat(buff,versao);
	fputs(buff, fp);
	strcpy(versao,"");
	strcpy(buff,"");
	strcpy(Sizee,"");
	strcpy(Time,"");
   	fclose(fp);

   	//reset
   	for(int i=0;i<n;i++){
		arrayaux[i]=array[i];
	}
   	//Improved Shell Sort - I
   	//printf("ISS-I\n");
   	strcpy(versao,"ISS-I");
	begin = clock();
	//printArray(arrayaux,n);
	ImprovedShellSortI(arrayaux,n);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("ATimes.txt","a");
	strcat(buff,"\nSize: ");
	strcat(buff,Sizee);
	strcat(buff," ,Time: ");
	strcat(buff,Time);
	strcat(buff," ,Versao: ");
	strcat(buff,versao);
	fputs(buff, fp);
	strcpy(versao,"");
	strcpy(buff,"");
	strcpy(Sizee,"");
	strcpy(Time,"");
   	fclose(fp);

   	//reset
   	for(int i=0;i<n;i++){
		arrayaux[i]=array[i];
	}
   	//Improved Shell Sort - II
   	//printf("ISS-II\n");
	strcpy(versao,"ISS-II");
	begin = clock();

	ImprovedShellSortII(arrayaux,n);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("ATimes.txt","a");
	strcat(buff,"\nSize: ");
	strcat(buff,Sizee);
	strcat(buff," ,Time: ");
	strcat(buff,Time);
	strcat(buff," ,Versao: ");
	strcat(buff,versao);
	fputs(buff, fp);
	strcpy(versao,"");
	strcpy(buff,"");
	strcpy(Sizee,"");
	strcpy(Time,"");
   	fclose(fp);

   	//reset
   	for(int i=0;i<n;i++){
		arrayaux[i]=array[i];
	}
   	//Improved Shell Sort - III
   	//printf("ISS-III\n");
	strcpy(versao,"ISS-III");
	begin = clock();

	ImprovedShellSortIII(arrayaux,n);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("ATimes.txt","a");
	strcat(buff,"\nSize: ");
	strcat(buff,Sizee);
	strcat(buff," ,Time: ");
	strcat(buff,Time);
	strcat(buff," ,Versao: ");
	strcat(buff,versao);
	fputs(buff, fp);
	strcpy(versao,"");
	strcpy(buff,"");
	strcpy(Sizee,"");
	strcpy(Time,"");
   	fclose(fp);

   	//reset
   	for(int i=0;i<n;i++){
		arrayaux[i]=array[i];
	}
   	//Improved Shell Sort - IV
   	//printf("ISS-IV\n");
	strcpy(versao,"ISS-IV");
	begin = clock();

	ImprovedShellSortIV(arrayaux,n);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("ATimes.txt","a");
	strcat(buff,"\nSize: ");
	strcat(buff,Sizee);
	strcat(buff," ,Time: ");
	strcat(buff,Time);
	strcat(buff," ,Versao: ");
	strcat(buff,versao);
	fputs(buff, fp);
	strcpy(versao,"");
	strcpy(buff,"");
	strcpy(Sizee,"");
	strcpy(Time,"");
   	fclose(fp);



	free(array);
	free(arrayaux);
	
	return 0;
}