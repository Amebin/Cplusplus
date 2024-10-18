#include<stdio.h>

main(){
	int M=0;
	printf("Ingresa el orden de la matriz cuadrada: ");
	scanf("%d", &M);
	
	int Matriz[M][M];
	
	for(int i=0; i<M; i++){
		for(int j=0; j<M; j++){
			//condicion para la diagonal principal
			if(j==i){
				Matriz[i][j]=j+1;
			}else{
				Matriz[i][j]=i+j+2;
			}
		}
	}
	
	
	//imprimimos
	for(int i=0; i<M; i++){
		printf("\n");
		for(int j=0; j<M; j++){
			printf("\t%d", Matriz[i][j]);
		}
	}
}