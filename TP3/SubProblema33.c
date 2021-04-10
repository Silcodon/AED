#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 200



//==========================================================================STRUCTS====================================================================
// Estrutura nó da arvore
struct No {
  char nome[MAX];
  char morada[MAX];
  int volume_compras;
  struct No *esq;
  struct No *dir;
  struct No *pai;
};




//==========================================================================AUX FUNCTIONS===============================================================

// Criar nó
struct No *novo(char nome[MAX],char morada[MAX], int volume_compras,struct No* pai) {
	struct No *no = (struct No *) malloc(sizeof(struct No));
	strcpy(no->nome, nome);
	/*
	memset(no->moradas,0,NUMBER_OF_STRING*sizeof(char)*MAX);
	memset(no->volume_compras,0,NUMBER_OF_STRING*sizeof(char)*MAX);
	*/
	strcpy(no->morada,morada);
	no->volume_compras=volume_compras;
	no->esq = NULL;
 	no->dir = NULL;
	no->pai = pai;
	printf("NOVO CLIENTE INSERIDO\n");
	return (no);
}

//Se nome ja existe, adiciona morada ou atualiza volume_compras
struct No *adicionacompras(struct No *no, int volume_compras){
	no->volume_compras+=volume_compras;
	printf("AQUISICAO INSERIDA\n");
	return no;
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


//Rotacao zig
//slide 269
struct No *ZIG(struct No *N){
	struct No *pai = N->pai;
    if (pai->esq == N)
    {
        struct No *B = N -> dir; 
        N->pai = pai->pai;
        N->dir = pai;
       //printf("%s\n",N->pai->nome);
        pai->pai = N;
        pai->esq = B;
        //printf("%s\n",N->dir->pai->nome);
       //printf("%s\n",pai->pai->nome);

        
        if (B != NULL){
        	B->pai = pai;
        } 
    }
    else
    {
        struct No *B = N->esq;        
        N->pai = pai->pai;
        N->esq = pai;
       //printf("%s\n",N->esq->nome);
       //printf("%s\n",N->pai->nome);
        pai->pai = N;
        pai->dir = B;
        //printf("%s\n",N->esq->pai->nome);
        //printf("%s\n",pai->pai->nome);
        if (B != NULL){
        	B->pai = pai;
        }
    }
    return N;
}

//Rotacao zig-zig
//slide 270
struct No *ZIGZIG(struct No *N){
	struct No *pai = N->pai;
	struct No *avo = N->pai->pai;
	if(pai->esq == N){
		struct No *B = N->dir;
		struct No *C = pai->dir;
		N->pai=avo->pai;
		N->dir=pai;

		pai->pai=N;
		pai->esq=B;
		pai->dir=avo;

		avo->pai=pai;
		avo->esq=C;

		if(B != NULL){
			B->pai=pai;
		}
		if(C != NULL){
			C->pai=avo;
		}
		if(N->pai!=NULL){
			if(N->pai->esq==avo){
				N->pai->esq=N;
			}
			else{
				N->pai->dir=N;
			}
		}
	}
	else{
        struct No *B = pai -> esq;
        struct No *C = N -> esq;     
        N->pai=avo->pai;
        N->esq=pai;

        pai->pai=N;
		pai->esq=avo;
		pai->dir=C;
        
        avo->pai=pai;
		avo->dir=B;
        
        if(B != NULL){
			B->pai=avo;
		}
		if(C != NULL){
			C->pai=pai;
		}
		if(N->pai!=NULL){
			if(N->pai->esq==avo){
				N->pai->esq=N;
			}
			else{
				N->pai->dir=N;
			}
		}
	}

	return N;
}

//Rotacao zig-zag
//slide 271
struct No *ZIGZAG(struct No *N){
	struct No *pai = N->pai;
	struct No *avo = N->pai->pai;
	struct No *B = N->esq;
	struct No *C = N->dir;
	if(pai->esq == N){
		N->pai=avo->pai;
		N->esq=avo;
		N->dir=pai;

		pai->pai=N;
		pai->esq=C;

		avo->pai=N;
		avo->dir=B;

		if(B != NULL){
			B->pai=avo;
		}
		if(C != NULL){
			C->pai=pai;
		}

		if(N->pai!=NULL){
			if(N->pai->esq==avo){
				N->pai->esq=N;
			}
			else{
				N->pai->dir=N;
			}
		}

	}
	else{
		N->pai=avo->pai;
		N->dir=avo;
		N->esq=pai;

		pai->pai=N;
		pai->dir=B;

		avo->pai=N;
		avo->esq=C;

		if(B != NULL){
			B->pai=pai;
		}
		if(C != NULL){
			C->pai=avo;
		}
		if(N->pai!=NULL){
			if(N->pai->esq==avo){
				N->pai->esq=N;
			}
			else{
				N->pai->dir=N;
			}
		}

	}

	return N;
}

//=======================================================ADICIONA,ELIMINA,PESQUISA,SPLAYING===========================================================
//Reestruturar a arvore com N na raiz 
struct No* splay(struct No *N){
    while (N->pai != NULL){
        struct No *pai = N->pai;
        struct No *avo = pai->pai;
        if (avo == NULL){
        	//printf("ZIG ");
        	N=ZIG(N);
        }
        else if((avo->esq==pai && pai->esq==N) || (avo->dir==pai && pai->dir==N)){
        	//printf("ZIGZIG ");
	  		N=ZIGZIG(N);
	  	}
        else {
        	//printf("ZIGZAG ");
        	N=ZIGZAG(N);
        }
    }
    //printf("\n");
    return N;
}

//Procurar o no nome na arvore para fazer splay e retorna a arvore
struct No *splaying(struct No *root,struct No *N,char nome[MAX]){
	//se arvore vazia
	if(N==NULL){
		return root;
	}
	while(N!=NULL){
		if (strcmp(nome,N->nome)<0){
    		N=N->esq;
  		}
  	//Se for maior lexicograficamente vai para a direita
  		else if (strcmp(nome,N->nome)>0){
    		N=N->dir;
  		}
  		else{
  			N=splay(N);
  			break;
  		}	
	}
	if(N==NULL){
		return root;
	}
	return N;

}


// Inserir no na arvore
struct No *inserir(struct No *N,char nome[MAX],char morada[MAX], int volume_compras, struct No* pai) {
	// Inserir o nó no local correto
  	if (N == NULL){
    	return (novo(nome,morada,volume_compras,pai));
  	}
  	//Atravessa a arvore
  	//Se for menor lexicograficamente vai para a esquerda
  	if (strcmp(nome,N->nome)<0){
    	N->esq = inserir(N->esq,nome,morada,volume_compras,N);
  	}
  	//Se for maior lexicograficamente vai para a direita
  	else if (strcmp(nome,N->nome)>0){
    	N->dir = inserir(N->dir,nome,morada,volume_compras,N);
  	}
  	//Se for igual adiciona morada ou atualiza data
  	else{
  		printf("CLIENTE JA EXISTENTE\n");
  	}
  	return N;
}


// Adicionar aquisicao
struct No *inseriraquisicao(struct No *N,char nome[MAX], int volume_compras) {
	// Inserir o nó no local correto
  	if (N == NULL){
    	printf("CLIENTE NAO REGISTADO\n");
    	return NULL;
  	}
  	//Atravessa a arvore
  	//Se for menor lexicograficamente vai para a esquerda
  	if (strcmp(nome,N->nome)<0){
    	N->esq = inseriraquisicao(N->esq,nome,volume_compras);
  	}
  	//Se for maior lexicograficamente vai para a direita
  	else if (strcmp(nome,N->nome)>0){
    	N->dir = inseriraquisicao(N->dir,nome,volume_compras);
    	
  	}
  	//Se for igual adiciona morada ou atualiza data
  	else{
    	return adicionacompras(N,volume_compras);
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
void printNodeInfo(struct No* N){
	printf("%s %s %d\n", N->nome,N->morada,N->volume_compras);
		
	return;
}

// Print Arvore
void printEmOrdem(struct No *root) {
  	if (root != NULL) {
		printEmOrdem(root->esq);
    	printNodeInfo(root);
    	printEmOrdem(root->dir);
  	}

}

//Pesquisa um nó
void search(struct No *N, char nome[MAX]) {
 	// Percorrer a arvore para encontrar o nó
  	if (N == NULL){
  		printf("CLIENTE NAO REGISTADO\n");
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
		printNodeInfo(N);
		printf("FIM\n");
	}
	return;
}




//=======================================================MAIN================================================================================

int main() {
	char str[MAX]; 
	FILE *fp;
   	char buff[255]="";
	char Time[50];
	char Sizee[12];
   	char delimitador[] = " ";
   	int contador=0;
   	int n=0;
	char nome[MAX];
	char volume_compras[MAX];
	char morada[MAX];
   	struct No *root=NULL;
   	int v_compras=0;
   	clock_t begin;
   	clock_t end;
   	double time_spent= (double)0;
    while (scanf("%[^\n]%*c", str)  != EOF) {
    	n++;
    	//printf("%s\n",str);
    	//Le cada frase do input
    	//Parte a string em bocados
    	char *ptr = strtok(str, delimitador);
    	//SE for comando acrescenta
    	if (strcmp(ptr,"CLIENTE")==0){
    		while(ptr != NULL){
				ptr = strtok(NULL, delimitador);
				//printf("'%s'\n", ptr);
				//nome
				if(contador==0){
					strcpy(nome,ptr);
				}
				//Morada
				else if(contador==1){
					strcpy(morada,ptr);
				}
				//Morada-cont
				else if(contador==2){
					strcat(morada," ");
					strcat(morada,ptr);
				}
				//volume compras
				else if(contador==3){
					strcpy(volume_compras,ptr);
					v_compras=atoi(volume_compras);
				}
				contador++;
			}
			begin=clock();
			root=inserir(root,nome,morada,v_compras,NULL);
			root=splaying(root,root,nome);
			end=clock();
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
			//printf("root:%s\n",root->nome);
			memset(nome,0,sizeof(char)*MAX);
			memset(morada,0,sizeof(char)*MAX);
			memset(volume_compras,0,sizeof(char)*MAX);
			contador=0;
    	}
    	else if (strcmp(ptr,"AQUISICAO")==0){
    		while(ptr != NULL){
				ptr = strtok(NULL, delimitador);
				//printf("'%s'\n", ptr);
				//nome
				if(contador==0){
					strcpy(nome,ptr);
				}
				//volume compras
				else if(contador==1){
					strcpy(volume_compras,ptr);
					v_compras=atoi(volume_compras);
				}
				contador++;
			}
			begin=clock();
			root=inseriraquisicao(root,nome,v_compras);
			//printf("root:%s\n",root->nome);
			root=splaying(root,root,nome);
			//printf("root:%s\n",root->nome);
			end=clock();
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
			//printf("root:%s\n",root->nome);
			memset(nome,0,sizeof(char)*MAX);
			memset(volume_compras,0,sizeof(char)*MAX);
			contador=0;
    	}
    	//SE for comando consulta
    	else if(strcmp(ptr,"CONSULTA")==0){
			while(ptr != NULL){
				ptr = strtok(NULL, delimitador);
				//printf("'%s'\n", ptr);
				if(contador==0){
					strcpy(nome,ptr);
					break;
				}
			}
			begin=clock();
			//printf("root:%s\n",root->nome);
			search(root,nome);
			////printf("root:%s\n",root->nome);
			root=splaying(root,root,nome);
			end=clock();
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
			//printf("root:%s\n",root->nome);
			memset(nome,0,sizeof(char)*MAX);
    	}
    	//SE for comando listagem
    	else if(strcmp(ptr,"LISTAGEM")==0){
    		printEmOrdem(root);
			printf("FIM\n");
    	}
    	//SE for comando apaga
    	else if(strcmp(ptr,"APAGA")==0){
    		deleteTree(root);
    		printf("LISTAGEM DE CLIENTES APAGADA\n");
    		root=NULL;
    	}
    	
    }
	snprintf(Time, 50, "%lf", time_spent);
	sprintf(Sizee, "%d", n);
	fp = fopen("33Times.txt","a");
	strcat(buff,"\nSize: ");
	strcat(buff,Sizee);
	strcat(buff," ,Time: ");
	strcat(buff,Time);
	fputs(buff, fp);
   	fclose(fp);
	return 0;
}