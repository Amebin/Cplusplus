#include<stdio.h>

main(){
	int M=0, N=0, P=0;
	
	printf("Ingresa el M del multi dimensional: ");
	scanf("%d", &M);
	
	printf("Ingresa el N del multi dimensional: ");
	scanf("%d", &N);
	
	printf("Ingresa el P del multi dimensional: ");
	scanf("%d", &P);
	
	int Multi[M][N][P], T=0, F=1, S=1;
	
	for(int z=0; z<P; z++){
		printf("\n");
		for(int i=0; i<M; i++){
			printf("\n");
			for(int j=0; j<N; j++){
				if(i==0 && j==0 && z==0){
					Multi[i][j][z]=F;
				}else{
					if(i==0 && j==2 && z==0){
						Multi[i][j][z]=S;
					}else{
						T=F+S;
						Multi[i][j][z]=T;
						F=S;
						S=T;
					}
				}
				printf("\t%d", Multi[i][j][z]);
			}
		}
	}
}