#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 200
#define NUMBER_OF_STRING 10



//==========================================================================STRUCTS====================================================================
// Estrutura nó da arvore
struct No {
  char nome[MAX];
  char vacinas[NUMBER_OF_STRING][MAX];
  char datalimite[NUMBER_OF_STRING][MAX];
  struct No *esq;
  struct No *dir;
  int alt;
  int n_vacinas;
};




//==========================================================================AUX FUNCTIONS===============================================================
//Retorna o MAX entre dois int
int max(int n1, int n2){
	if(n1>n2){
		return n1;
	}
	else if(n2>n1){
		return n2;
	}
	else{
		return n1;
	}

}


// Retorna altura do nó
int getAlt(struct No *N) {
  if (N == NULL){
    return 0;
  }
  return N->alt;
}

// Retorna FE(t)
int getEquilibrio(struct No *N) {
  if (N == NULL){
    return 0;
  }
  int FE = getAlt(N->esq) - getAlt(N->dir);
  return FE;
}

//Atualiza a altura de um no
int UpdateAlt(struct No *N){
	int n_alt=max(getAlt(N->esq),getAlt(N->dir))+1;
	return n_alt;
}


// Criar nó
struct No *novo(char nome[20],char vacina[20], char datalimite[20]) {
	struct No *no = (struct No *) malloc(sizeof(struct No));
	strcpy(no->nome, nome);
	/*
	memset(no->vacinas,0,NUMBER_OF_STRING*sizeof(char)*MAX);
	memset(no->datalimite,0,NUMBER_OF_STRING*sizeof(char)*MAX);
	*/
	strcpy(no->vacinas[0],vacina);
	for(int i=1;i<NUMBER_OF_STRING;i++){
		strcpy(no->vacinas[i],"");
	}
	strcpy(no->datalimite[0],datalimite);
	for(int i=1;i<NUMBER_OF_STRING;i++){
		strcpy(no->datalimite[i],"");
	}
	no->esq = NULL;
 	no->dir = NULL;
	no->alt = 1;
	no->n_vacinas = 1;
	printf("NOVO UTENTE CRIADO\n");
	return (no);
}

//Se nome ja existe, adiciona vacina ou atualiza datalimite
struct No *adicionavacina(struct No *no, char vacina[MAX], char datalimite[MAX]){
	int i=0;
	while(strcmp(no->vacinas[i],vacina)!=0){
		//Para no primeiro elemento vazio para adicionar vacina nova porque ela ainda nao existe
		//Caso contrario continua ate encontrar uma igual para atualizar data
		if(strcmp(no->vacinas[i],"")==0){
			printf("NOVA VACINA INSERIDA\n");
			break;
		}
		//Numero maximo de vacinas a armazenar
		if(i==NUMBER_OF_STRING){
			break;
		}

		i++;
	}
	//Ciclo While parou porque vacina ja exuste e atualiza data
	if(strcmp(no->vacinas[i],vacina)==0){
		printf("VACINA ATUALIZADA\n");
	}
	strcpy(no->vacinas[i],vacina);
	strcpy(no->datalimite[i],datalimite);
	no->n_vacinas+=1;
	return (no);
}



 //=======================================================ROTACOES================================================================================


//Atualiza a altura dos nós rodados
//WithLeftChild(EE)
struct No *WithLeftChild(struct No *norotate)
{
	struct No *no= (struct No *) malloc(sizeof(struct No));
	no=norotate->esq;
	norotate->esq=no->dir;
	no->dir=norotate;
	norotate->alt=UpdateAlt(norotate);
	no->alt=UpdateAlt(no);
	return no;
}
 
//Atualiza a altura dos nós rodados
//WithRightChild(DD)
struct No *WithRightChild(struct No *norotate)
{
	struct No *no= (struct No *) malloc(sizeof(struct No));
	no=norotate->dir;
	norotate->dir=no->esq;
	no->esq=norotate;
	norotate->alt=UpdateAlt(norotate);
	no->alt=UpdateAlt(no);
	return no;
}

//Rotacao a direita, o novo elemento Y e inserido na subárvore Direita da subárvore Direita de N.
struct No *DD(struct No *N){
	N=WithRightChild(N);
	return N;
}

//Rotacao a esqeurda, o novo elemento Y é inserido na subárvore Esquerda da subárvore Esquerda de N.
struct No *EE(struct No *N){
	N=WithLeftChild(N);
	return N;
}
 
//Rotacao Esquerda Direita, o novo elemento Y é inserido na subárvore Direita da subárvore Esquerda de N.
struct No *ED(struct No *N){
	N->esq=WithRightChild(N->esq);
	N=WithLeftChild(N);
	return N;
}
 
//Rotacao Direita Esquerda, o novo elemento Y é inserido na subárvore Esquerda da subárvore Direita de M.
struct No *DE(struct No *N){
	N->dir=WithLeftChild(N->dir);
	N=WithRightChild(N);
	return N;
}


//=======================================================ADICIONA,ELIMINA,PESQUISA===========================================================
// Inserir no na arvore
struct No *inserir(struct No *N,char nome[20],char vacina[20], char datalimite[20]) {
	// Inserir o nó no local correto
  	if (N == NULL){
    	return (novo(nome,vacina,datalimite));
  	}
  	//Atravessa a arvore
  	//Se for menor lexicograficamente vai para a esquerda
  	if (strcmp(nome,N->nome)<0){
    	N->esq = inserir(N->esq,nome,vacina,datalimite);
  	}
  	//Se for maior lexicograficamente vai para a direita
  	else if (strcmp(nome,N->nome)>0){
    	N->dir = inserir(N->dir,nome,vacina,datalimite);
    	
  	}
  	//Se for igual adiciona vacina ou atualiza data
  	else{
    	adicionavacina(N,vacina,datalimite);
  	}

	//Atualizar as alturas dos nós
  	N->alt = UpdateAlt(N);
  	//Equilibrar a arvore depois de inserir o nó
  	int equilibrio = getEquilibrio(N);
   	/*     O
	//    /
	//   O
	//  /
	// O*/
	if (equilibrio > 1 && strcmp(nome,N->esq->nome)<0){
		return EE(N);
	}
	/*     O
	//    /
	//   O
	//    \ 
	//     O*/
	else if (equilibrio > 1 && strcmp(nome,N->esq->nome)>0) {
	  	return ED(N);
	}
	/* O    
	//  \   
	//   O
	//    \
	//     O*/
	else if (equilibrio < -1 && strcmp(nome,N->dir->nome)>0){
	  	return DD(N);
	}
	/* O
	//  \ 
	//   O
	//  /
	// O*/
	else if (equilibrio < -1 && strcmp(nome,N->dir->nome)<0) {
	 	return DE(N);
	}
  	return N;
}


//Apagar um nó
void deleteTree(struct No *N) {
 	// Percorrer a arvore para encontrar o nó
  	if (N == NULL){
    	return;
  	}
	deleteTree(N->esq);
	deleteTree(N->dir);
	free(N);
	return;
}


//Print No
void printNodeFullInfo(struct No* N){
	int i=0;
	while(i<N->n_vacinas){
		printf("%s %s %s ", N->nome, N->vacinas[i],N->datalimite[i]);
		i++;
	}
	printf("\n");
		
	return;

}

void printNodeConsultaInfo(struct No* N){
	int i=0;
	while(i<N->n_vacinas){
		printf("%s %s %s ", N->nome, N->vacinas[i],N->datalimite[i]);
		i++;
	}
	printf("\nFIM\n");
		
	return;
}

// Print Arvore
void printEmOrdem(struct No *root) {
  	if (root != NULL) {
		printEmOrdem(root->esq);
    	printNodeFullInfo(root);
    	printEmOrdem(root->dir);
  	}

}

//Pesquisa um nó
void search(struct No *N, char nome[20]) {
 	// Percorrer a arvore para encontrar o nó
  	if (N == NULL){
  		printf("NÃO ENCONTRADO\n");
    	return;
  	}
	//Se for menor lexicograficamente vai para a esquerda
  	if (strcmp(nome,N->nome)<0){
    	search(N->esq,nome);
  	}
  	//Se for maior lexicograficamente vai para a direita
  	else if (strcmp(nome,N->nome)>0){
   		search(N->dir,nome);
  	}
  	//Encontrou o nó
	else {
		printNodeConsultaInfo(N);
	}
	return;
}




//=======================================================MAIN================================================================================

int main() {
	char str[MAX]; 
	FILE *fp;
   	char buff[255]="";
	char Time[50];
	char Ratio[50];
	char Sizee[12];
   	char delimitador[] = " ";
   	int contador=0;
   	int n=0;
   	double insert=0,consultar=0;
	char nome[MAX];
	char vacina[MAX];
	char datalimite[MAX];
   	struct No *root=NULL;
   	clock_t begin;
   	clock_t end;
   	double time_spent=(double)0;
    while (scanf("%[^\n]%*c", str)  != EOF) {
    	n++;
    	//Le cada frase do input
    	//Parte a string em bocados
    	char *ptr = strtok(str, delimitador);
    	//SE for comando acrescenta
    	if (strcmp(ptr,"ACRESCENTA")==0){
    		while(ptr != NULL){
				ptr = strtok(NULL, delimitador);
				//printf("'%s'\n", ptr);
				//nome
				if(contador==0){
					strcpy(nome,ptr);
				}
				//vacina
				else if(contador==1){
					strcpy(vacina,ptr);
				}
				//Data limite
				else if(contador==2){
					strcpy(datalimite,ptr);
				}
				contador++;
			}
			begin = clock();
			root=inserir(root,nome,vacina,datalimite);
			end = clock();
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
			memset(nome,0,sizeof(char)*MAX);
			memset(vacina,0,sizeof(char)*MAX);
			memset(datalimite,0,sizeof(char)*MAX);
			contador=0;
			insert++;
    	}
    	else if(strcmp(ptr,"CONSULTA")==0){
			while(ptr != NULL){
				ptr = strtok(NULL, delimitador);
				//printf("'%s'\n", ptr);
				if(contador==0){
					strcpy(nome,ptr);
					break;
				}
			}
			begin = clock();
			search(root,nome);
			end = clock();
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
			memset(nome,0,sizeof(char)*MAX);
			consultar++;
    	}
    	//SE for comando listagem
    	else if(strcmp(ptr,"LISTAGEM")==0){
    		printEmOrdem(root);
			printf("FIM\n");
    	}
    	//SE for comando apaga
    	else if(strcmp(ptr,"APAGA")==0){
    		deleteTree(root);
    		printf("LISTAGEM DE NOMES VAZIA\n");
    		root=NULL;
    	}
    	
    }
    double ratio=(double)(insert/(consultar+insert))*100;
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	snprintf(Ratio,50,"%lf", ratio);
	fp = fopen("32Times.txt","a");
	strcat(buff,"\nSize: ");
	strcat(buff,Sizee);
	strcat(buff," ,Time: ");
	strcat(buff,Time);
	strcat(buff," ,InsertRatio: ");
	strcat(buff,Ratio);
	fputs(buff, fp);
   	fclose(fp);
	return 0;
}