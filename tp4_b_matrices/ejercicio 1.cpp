#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
	int M=0, N=0; 
	srand(time(0));
	printf("Ingresa la cantidad de filas M: ");
	scanf("%d", &M);
	printf("Ingresa la cantidad de columnas N: ");
	scanf("%d", &N);
	
	int Matriz[M][N];
	
	for(int i=0; i<M; i++){
		
		for(int j=0; j<N; j++){
			Matriz[i][j]= 1 + rand()%10;
		}
	}
	
	for(int i=0; i<M; i++){
		
		for(int j=0; j<N; j++){
			if(Matriz[i][j]==(i+j)){
				printf("\nel elemento Matriz[%d][%d] es igual a la suma i + j: %d", i, j, Matriz[i][j] );
			}
		}
	}
}