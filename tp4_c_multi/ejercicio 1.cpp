#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
	srand(time(0));
	int M=0, N=0, P=0;
	
	printf("Ingrese el orden M de la matriz: ");
	scanf("%d", &M);
	
	printf("Ingrese el orden N de la matriz: ");
	scanf("%d", &N);
	
	printf("Ingrese el orden P de la matriz: ");
	scanf("%d", &P);
	
	int Multi[M][N][P];
	
	for(int i=0; i<M; i++){
		printf("\n");
		
		for(int j=0; j<N; j++){
			printf("\n");
			
			for(int z=0; z<P; z++){
				Multi[i][j][z]= 1 + rand()%10;
				printf("\t %d", Multi[i][j][z]);
			}
		}
	}
	
	for(int i=0; i<M; i++){
				
		for(int j=0; j<N; j++){
					
			for(int z=0; z<P; z++){
				if((Multi[i][j][z])==(i+j+z)){
					printf("\n%d", Multi[i][j][z]);
				}
			}
		}
	}
}