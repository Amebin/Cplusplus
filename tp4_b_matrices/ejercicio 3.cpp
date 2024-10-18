#include<stdio.h>

main(){
	int N, Contador=1;
	
	printf("Ingresa el orden N de la matriz a generar: ");
	scanf("%d", &N);
	
	int Matriz[N][N];
	
	for(int i=0; i<N; i++){
		
		for(int j=0; j<N; j++){
			printf("\t%d", Contador);
			Contador++;
		}
		printf("\n");
	}
}