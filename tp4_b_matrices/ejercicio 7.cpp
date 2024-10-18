#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
	srand(time(0));
	
	int M=0, N=0;
	//pedimos los datos 
	printf("Ingresa el orden M de la matriz: ");
	scanf("%d", &M);
	printf("Ingresa el orden N de la matriz: ");
	scanf("%d", &N);
	
	//generamos la matriz y la imprimimos para corroborar los valores
	int Matriz[M][N];
	for(int i=0; i<M; i++){
		printf("\n");
		for(int j=0; j<N; j++){
			Matriz[i][j]= 1 + rand()%100;
			printf("\t%d",Matriz[i][j] );
		}
	}
	
	//buscamos el mayor y lo almacenamos en auxiliares para imprimir
	int Mayor=0, PosI=0, PosJ=0;
	for(int i=0; i<M; i++){
		
		for(int j=0; j<N; j++){
			if(Matriz[i][j] > Mayor){
				Mayor=Matriz[i][j];
				PosI=i;
				PosJ=j;
			}
			
		}
		printf("\nFila %d el mayor elemento es %d en la columna %d", PosI, Mayor, PosJ);
		Mayor=0;
	}
}