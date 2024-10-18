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
	//imprimimos la matriz
	for(int i=0; i<M; i++){
		printf("\n");
		for(int j=0; j<N; j++){
			printf("\t%d", Matriz[i][j]);
		}
	}
	
	//A produccion mensual total
	int Acumulador=0;
	for(int i=0; i<M; i++){
		
		for(int j=0; j<N; j++){
			Acumulador+= Matriz[i][j];
		}
	}
	
	printf("\nla cantidad total de prendas producidas en el mes fue de: %d", Acumulador);
	
	//total por modelo
	for(int i=0; i<M; i++){
	int Sumatoria=0;
		
		for(int j=0; j<N; j++){
			Sumatoria+= Matriz[i][j];
		}
		printf("\nla cantidad total de prendas del modelo %d producidas en el mes fue de: %d",i, Sumatoria);
	}
	
	//mayor produccion del primer talle
	int Mayor= 0;
	for(int j=0; j<1; j++){
		
		for(int i=0; i<M; i++){
			if(Matriz[i][j]>Mayor)
				Mayor=Matriz[i][j];
		}
	}
	printf("\nLa mayor produccion del primer talle es de: %d", Mayor);
}