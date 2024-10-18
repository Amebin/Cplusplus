#include<stdio.h>

main(){
	int N, M, Z;
	
	printf("Ingresa el orden M de la matriz a generar: ");
	scanf("%d", &M);
	
	printf("Ingresa el orden N de la matriz a generar: ");
	scanf("%d", &N);
	
	printf("Ingresa el orden z de la matriz a generar: ");
	scanf("%d", &Z);
	
	int Matriz[M][N][Z], p=1, s=1, t=0;
	
	
	for(int k=0; k<Z; k++){
		printf("\nPlano %d", k);
		for(int i=0; i<M; i++){
			printf("\n");
			for(int j=0; j<N; j++){
				if(i==0 && j==0 && k==0){
					Matriz[i][j][k]= p;
				}else{
					if(i==0 && j==1 && k==0){
						Matriz[i][j][k]=s;
					}else{
						t=p+s;
						Matriz[i][j][k]=t;
						p=s;
						s=t;
					}
				}
				printf("\t%d", Matriz[i][j][k]);				
			}					
		}
	}
}