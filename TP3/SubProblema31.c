#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

//==========================================================================HASH FUNCTIONS====================================================================
long hashcode(long long int x) {
	return x % 1000000007;
}


long hashcode2(long x, long y) {
	int mod = 1000000007;
	return ((x % mod) + (y % mod)) % mod;
}


//==========================================================================AUX====================================================================

void printArvore(long long int HashTree[100],int nodes){
	for(int i=0; i<nodes; i++) {
      printf("%lld\n",HashTree[i]);
    }
}



//==========================================================================MAIN====================================================================
int main() {
	FILE *fp;
   	char buff[255]="";
	char Time[50];
	char Sizee[12];
	int tam;
	scanf("%d", &tam);
	long long int *numbers;

	numbers = (long long int*) malloc(tam * sizeof(long long int));
	for (int i = 0; i < tam; i++) {
        scanf("%lld ", &numbers[i]);
    	//printf("numbers[%d] %lld\n",i,numbers[i]);
    }
	clock_t begin = clock();
	int maxDepth=log2(tam);
	int n_nodes=pow(2,maxDepth+1)-1;
	long long int *HashTree;
	HashTree = (long long int*) malloc(n_nodes * sizeof(long long int));
	int n_lastnodes=n_nodes-tam;
	int k=0;
	//Preencher base da arvore
	//Os últimos "tam" nós
	//O(n)
	for(int i=n_lastnodes; i<n_nodes; i++) {
      HashTree[i] = hashcode(numbers[k]);
      /*
      printf("ola %lld %d\n",numbers[k],i);
      printf("ola %lld %lld\n",HashTree[i],hashcode(numbers[k]));
      */
      k++;
    }
    free(numbers);

    //Preencher os niveis superiores
    //Por cada nivel, preenche os nós de cada nivel com o valor dos filhos que estao na posicao (2*i + 1) e (2*i + 2)
    //O(log N)
    for(int l=maxDepth-1; l>=0; l--) {
    	//Numero de nos em cada nivel, desde o inicio do nivel ate ao inicio do nivel seguinte
    	//O(2^log(N)-2^(log(N)+1))
    	for(int n=pow(2, l)-1; n<pow(2, l+1)-1; n++) {
    		HashTree[n] = hashcode2(HashTree[2*n+1], HashTree[2*n+2]);
      		//printf("ola %lld %d\n",HashTree[n],n);
    	}
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printArvore(HashTree,n_nodes);
    free(HashTree);
    snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", tam);
	fp = fopen("31Times.txt","a");
	strcat(buff,"\nSize: ");
	strcat(buff,Sizee);
	strcat(buff," ,Time: ");
	strcat(buff,Time);
	fputs(buff, fp);
   	fclose(fp);

	return 0;
}