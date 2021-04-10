#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100000





int compara(const void *a, const void *b) {
   return ( *(int*)b - *(int*)a );
}

int main() {
	int n;
	int* array;
	FILE *fp;
   	char buff[255]="";
	char Time[50];
	char Sizee[12];
	scanf("%d", &n);
	array = (int*) malloc(n * sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d ", &array[i]);
	}
	clock_t begin = clock();
	//Algoritmo
	/*
	for(int i=0;i<n;i++){
		//j=0 ou j=i+1
		for(int j=0;j<n;j++){
			if(array[i]>array[j]){
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
	}
	*/
	qsort(array, n, sizeof(int), compara);
	printf("%d\n",array[0]+array[1]);
	free(array);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("BTimes.txt","a");
	strcat(buff,"\nSize: ");
	strcat(buff,Sizee);
	strcat(buff," ,Time: ");
	strcat(buff,Time);
	fputs(buff, fp);
   	fclose(fp);
	return 0;
}