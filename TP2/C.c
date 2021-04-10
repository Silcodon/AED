#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100000





int main() {
	int n;
	int max1=-1;
	int max2=-1;
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
	for(int i=0;i<n;i++){
		if(array[i]>max1){
			max2=max1;
			max1=array[i];
		}
		else if(array[i]>max2){
			max2=array[i];
		}
	}
	
	printf("%d\n",max1+max2);
	free(array);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("CTimes.txt","a");
	strcat(buff,"\nSize: ");
	strcat(buff,Sizee);
	strcat(buff," ,Time: ");
	strcat(buff,Time);
	fputs(buff, fp);
   	fclose(fp);
	return 0;
}