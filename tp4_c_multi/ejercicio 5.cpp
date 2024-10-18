#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
	srand(time(0));
	int M=0, N=0, P=0; 
	
	printf("Ingresa M del multi: ");
	scanf("%d", &M);
	
	printf("Ingresa N del multi: ");
	scanf("%d", &N);
	
	printf("Ingresa P del multi: ");
	scanf("%d", &P);
	
	int Multi[M][N][P],i,j,z, Mayor=0, Col=0, Fil=0;
	
	for(z=0; z<P; z++){
		Mayor=0;
		printf("\n");
		for(i=0; i<M; i++){
			printf("\n");
			for(j=0; j<N; j++){
				Multi[i][j][z]= 1 + rand()%100;
				printf("\t%d", Multi[i][j][z]);
				if(Multi[i][j][z]>Mayor){
					Mayor=Multi[i][j][z];
					Col=j;
					Fil=i;
				}
			}			
		}
		printf("\nEl mayor elemento del plano %d es el %d de la fila %d columna %d", z, Mayor, Fil, Col);
	}
}