#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXROW 10
#define MAXCOL 10

void read_file();
void print_matrix(int n, int m);
void print_matrix90(int n, int m);
void rotate_matrixto90(int n, int m);
void rotate_matrixto180(int n, int m);
void print_matrix180(int n, int m);
void rotate_matrixto270(int n, int m);
void print_matrix270(int n, int m);

int matrix[MAXROW][MAXCOL];
int matrix90[MAXROW][MAXCOL];





int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d ", &matrix[i][j]);
		}
	}
	rotate_matrixto90(n,m);
	print_matrix90(m,n);
	memset(matrix90, 0, sizeof(matrix90)); 
	rotate_matrixto180(n,m);
	print_matrix180(n,m);
	memset(matrix90, 0, sizeof(matrix90)); 
	rotate_matrixto270(n,m);
	print_matrix270(m,n);
	return 0;
}


void print_matrix(int n, int m){
	printf("Original\n");
	for(int i=0;i< n;i++){
        for(int j=0;j<m;j++){
        	if(j!=m-1)
            	printf("%d ",matrix[i][j]);
            else
            	printf("%d",matrix[i][j]);
        }
        printf("\n");   
    }
}

void print_matrix90(int n, int m){
	printf("90\n");
	for(int i=0;i< n;i++){
        for(int j=0;j<m;j++){
        	if(j!=m-1)
            	printf("%d ",matrix90[i][j]);
            else
            	printf("%d",matrix90[i][j]);
        }
        printf("\n");  
    }
}


void print_matrix180(int n, int m){
	printf("180\n");
	for(int i=0;i< n;i++){
        for(int j=0;j<m;j++){
        	if(j!=m-1)
            	printf("%d ",matrix90[i][j]);
            else
            	printf("%d",matrix90[i][j]);
        }
        printf("\n");   
    }
}

void print_matrix270(int n, int m){
	printf("270\n");
	for(int i=0;i< n;i++){
        for(int j=0;j<m;j++){
        	if(j!=m-1)
            	printf("%d ",matrix90[i][j]);
            else
            	printf("%d",matrix90[i][j]);
        }
        printf("\n"); 
    }
}

void rotate_matrixto90(int n, int m){
	for(int i=0;i< n;i++){
        for(int j=0;j<m;j++){
        	matrix90[j][n-1-i] = matrix[i][j];
        }
    }
}

void rotate_matrixto180(int n, int m){
	for(int i=0;i< n;i++){
        for(int j=0;j<m;j++){
        	matrix90[n-1-i][m-1-j] = matrix[i][j];
        }
    }
}
 

void rotate_matrixto270(int n, int m){
	for(int i=0;i< n;i++){
        for(int j=0;j<m;j++){
        	matrix90[m-1-j][i] = matrix[i][j];
        }
    }
}
