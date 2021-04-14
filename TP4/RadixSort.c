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

// This function swaps values pointed by xp and yp
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int getMax(int array[MAX], int n){
	int max = -1;
  	for(int i = 0; i < n; i++){
    	if(array[i] > max){
      		max = array[i];
  		}
  	}
  	return max;
}

int getDigito(int a, int digito_sig){
	return (a/digito_sig) % 10;
}

//RadixSort LSD
void RadixSort(int array[MAX], int n){
	int i;
	int *aux=(int*) malloc(n * sizeof(int));
	int count[10];
	int digito_significante = 1;
	int max = getMax(array, n);
	//printf("%d\n",max);
	// Ate chegar ao primeiro digito
	while (max > digito_significante){
		//printf("Digito: %d ", digito_significante);
	  	//printArray(array, n);    
	  	//Numeros de base 10
	  	for (i = 0; i < 10; i++){
	      count[i] = 0;
	    }
	    for (i = 0; i < n; i++){
	      count[getDigito(array[i] , digito_significante)]++;
	    }
	    //Numeros de base 10
	    for (i = 1; i < 10; i++){
	      count[i] += count[i - 1];
	    } 
	    for (i = n - 1; i >= 0; i--){
	      aux[count[getDigito(array[i] , digito_significante)]] = array[i];
	      count[getDigito(array[i] , digito_significante)]--;
	    }
	    for (i = 0; i < n; i++){
	      array[i] = aux[i];
	    }
	    
	    //Porximo digito
	    digito_significante *= 10;
	    
	    //printf("\nBucket: ");
	    //printArray(count, 10);
	}
	free(aux);

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
	for(int i=0;i<n;i++){
		scanf("%d\n", &array[i]);
	}

	//Base Shell Sort
	strcpy(versao,"RS");
	//printf("BSS\n");
	begin = clock();

	RadixSort(array,n);
	//printArray(array,n);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("CTimes.txt","a");
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