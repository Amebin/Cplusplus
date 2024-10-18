#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
	srand(time(0));
	int M=0, N=30, P=0; 
	
	printf("Ingresa M del multi: ");
	scanf("%d", &M);
	
	printf("Ingresa P del multi: ");
	scanf("%d", &P);
	
	int Multi[M][N][P],i,j,z;
	
	for(z=0; z<P; z++){
		printf("\nHamburlance: %d", z);
		for(i=0; i<M; i++){
			printf("\nSector%d: ", i);
			for(j=0; j<N; j++){
				Multi[i][j][z]=  rand()%5;
				printf("\t%d", Multi[i][j][z]);
			}			
		}
	}
	
	int Movil=0, Emergencias=0;
	printf("Ingresa el movil para consultar del mes: ");
	scanf("%d", &Movil);
	
	for(z=0; z<P; z++){

		if(z==Movil){
			for(i=0; i<M; i++){
			
				for(j=0; j<N; j++){
					Emergencias+=Multi[i][j][z];
				}			
			}
		}
	}
	printf("Las emergencias atendidas por el movil %d en el mes fueron de: %d", Movil, Emergencias);
	
	
}