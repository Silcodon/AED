#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define MAX 1000000

void QuickSort(int array[MAX], int low, int high);
void QuickSortInsertionSortI(int array[MAX], int low, int high);
void QuickSortInsertionSortII(int array[MAX], int low, int high);
void QuickSortInsertionSortIII(int array[MAX], int low, int high);
void QuickSortInsertionSortIV(int array[MAX], int low, int high);

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

void insertionSort(int array[MAX], int low, int high) {
	int num,j;
  	for (int i=low+1;i<high+1;i++) {
    	num = array[i];
    	j = i;

    	while (num<array[j-1] && j>low) {
     		array[j] = array[j-1];
      		j--;
    	}
    	array[j] = num;
  	}
}


void QuickSort(int array[MAX], int low, int high){
	if(low<high){
		// Sort low, middle, high
		int middle = ( low + high ) / 2;
		if( array[ middle ] < ( array[ low ] ) )
			swap( &array[low], &array[middle] );
		if( array[ high ] < ( array[ low ] ) )
			swap( &array[low], &array[high] );
		if( array[ high ] < ( array[ middle ] ) )
			swap( &array[middle], &array[high] );
		// Place pivot at position high - 1
		swap( &array[middle], &array[high - 1] );
		int pivot = array[ high - 1 ];
		// Begin partitioning
		int i, j;
		for( i = low, j = high - 1; ; )
		{
		while( array[ ++i ] < ( pivot ) )
		;
		while( pivot < ( array[ --j ] ) )
		;
		if( i < j )
			swap( &array[i], &array[j] );
		else
			break;
		}
		// Restore pivot
		swap( &array[i], &array[high - 1] );
		QuickSort( array, low, i - 1 ); // Sort small elements
		QuickSort( array, i + 1, high ); // Sort large elements
	}
}


void QuickSortInsertionSortI(int array[MAX], int low, int high){
	int CUTOFF = 10;
	if( low + CUTOFF > high )
		insertionSort( array, low, high );
	else
	{
	// Sort low, middle, high
	int middle = ( low + high ) / 2;
	if( array[ middle ] < ( array[ low ] ) )
		swap( &array[low], &array[middle] );
	if( array[ high ] < ( array[ low ] ) )
		swap( &array[low], &array[high] );
	if( array[ high ] < ( array[ middle ] ) )
		swap( &array[middle], &array[high] );
	// Place pivot at position high - 1
	swap( &array[middle], &array[high - 1] );
	int pivot = array[ high - 1 ];
	// Begin partitioning
	int i, j;
	for( i = low, j = high - 1; ; )
	{
	while( array[ ++i ] < ( pivot ) )
	;
	while( pivot < ( array[ --j ] ) )
	;
	if( i < j )
		swap( &array[i], &array[j] );
	else
		break;
	}
	// Restore pivot
	swap( &array[i], &array[high - 1] );
	QuickSortInsertionSortI( array, low, i - 1 ); // Sort small elements
	QuickSortInsertionSortI( array, i + 1, high ); // Sort large elements
	}

}


void QuickSortInsertionSortII(int array[MAX], int low, int high){
	int CUTOFF = 100;
	if( low + CUTOFF > high )
		insertionSort( array, low, high );
	else
	{
	// Sort low, middle, high
	int middle = ( low + high ) / 2;
	if( array[ middle ] < ( array[ low ] ) )
		swap( &array[low], &array[middle] );
	if( array[ high ] < ( array[ low ] ) )
		swap( &array[low], &array[high] );
	if( array[ high ] < ( array[ middle ] ) )
		swap( &array[middle], &array[high] );
	// Place pivot at position high - 1
	swap( &array[middle], &array[high - 1] );
	int pivot = array[ high - 1 ];
	// Begin partitioning
	int i, j;
	for( i = low, j = high - 1; ; )
	{
	while( array[ ++i ] < ( pivot ) )
	;
	while( pivot < ( array[ --j ] ) )
	;
	if( i < j )
		swap( &array[i], &array[j] );
	else
		break;
	}
	// Restore pivot
	swap( &array[i], &array[high - 1] );
	QuickSortInsertionSortII( array, low, i - 1 ); // Sort small elements
	QuickSortInsertionSortII( array, i + 1, high ); // Sort large elements
	}
}


void QuickSortInsertionSortIII(int array[MAX], int low, int high){
	int CUTOFF = 1000;
	if( low + CUTOFF > high )
		insertionSort( array, low, high );
	else
	{
	// Sort low, middle, high
	int middle = ( low + high ) / 2;
	if( array[ middle ] < ( array[ low ] ) )
		swap( &array[low], &array[middle] );
	if( array[ high ] < ( array[ low ] ) )
		swap( &array[low], &array[high] );
	if( array[ high ] < ( array[ middle ] ) )
		swap( &array[middle], &array[high] );
	// Place pivot at position high - 1
	swap( &array[middle], &array[high - 1] );
	int pivot = array[ high - 1 ];
	// Begin partitioning
	int i, j;
	for( i = low, j = high - 1; ; )
	{
	while( array[ ++i ] < ( pivot ) )
	;
	while( pivot < ( array[ --j ] ) )
	;
	if( i < j )
		swap( &array[i], &array[j] );
	else
		break;
	}
	// Restore pivot
	swap( &array[i], &array[high - 1] );
	QuickSortInsertionSortIII( array, low, i - 1 ); // Sort small elements
	QuickSortInsertionSortIII( array, i + 1, high ); // Sort large elements
	}
}


void QuickSortInsertionSortIV(int array[MAX], int low, int high){
	int CUTOFF = 10000;
	if( low + CUTOFF > high )
		insertionSort( array, low, high );
	else
	{
	// Sort low, middle, high
	int middle = ( low + high ) / 2;
	if( array[ middle ] < ( array[ low ] ) )
		swap( &array[low], &array[middle] );
	if( array[ high ] < ( array[ low ] ) )
		swap( &array[low], &array[high] );
	if( array[ high ] < ( array[ middle ] ) )
		swap( &array[middle], &array[high] );
	// Place pivot at position high - 1
	swap( &array[middle], &array[high - 1] );
	int pivot = array[ high - 1 ];
	// Begin partitioning
	int i, j;
	for( i = low, j = high - 1; ; )
	{
	while( array[ ++i ] < ( pivot ) )
	;
	while( pivot < ( array[ --j ] ) )
	;
	if( i < j )
		swap( &array[i], &array[j] );
	else
		break;
	}
	// Restore pivot
	swap( &array[i], &array[high - 1] );
	QuickSortInsertionSortIV( array, low, i - 1 ); // Sort small elements
	QuickSortInsertionSortIV( array, i + 1, high ); // Sort large elements
	}
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
	strcpy(versao,"QS");
	//printf("BSS\n");
	begin = clock();

	QuickSort(arrayaux,0,n-1);
	//printArray(arrayaux,n);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("BTimes.txt","a");
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
   	strcpy(versao,"QS+IS-I");
	begin = clock();
	//printArray(arrayaux,n);
	QuickSortInsertionSortI(arrayaux,0,n-1);
	//printArray(arrayaux,n);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("BTimes.txt","a");
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
	strcpy(versao,"QS+IS-II");
	begin = clock();

	QuickSortInsertionSortII(arrayaux,0,n-1);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("BTimes.txt","a");
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
	strcpy(versao,"QS+IS-III");
	begin = clock();

	QuickSortInsertionSortIII(arrayaux,0,n-1);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("BTimes.txt","a");
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
	strcpy(versao,"QS+IS-IV");
	begin = clock();

	QuickSortInsertionSortIV(arrayaux,0,n-1);
	//printArray(arrayaux,n);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("BTimes.txt","a");
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