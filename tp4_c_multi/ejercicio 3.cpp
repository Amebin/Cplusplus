#include<stdio.h>
#include<stdlib.h>

main(){
	int M=0, N=0, P=0;
	
	printf("Ingresa el M del arreglo multidimensional: ");
	scanf("%d", &M);
	
	printf("Ingresa el N del arreglo multidimensional: ");
	scanf("%d", &N);
	
	printf("Ingresa el P del arreglo multidimensional: ");
	scanf("%d", &P);
	
	int Multi[M][N][P], Contador=1;
	
	for(int z=0; z<P; z++){
		printf("\n");
		for(int i=0; i<M; i++){
			printf("\n");
			for(int j=0; j<N; j++){
				Multi[i][j][z]=Contador;
				Contador++;
				printf("\t%d", Multi[i][j][z]);
			}
		}
	}
}