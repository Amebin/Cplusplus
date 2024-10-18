#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
	
	//generamos la matriz
	srand(time(0));
	int M=4, N=5, Matriz[M][N];
	
	for(int i=0; i<M; i++){
		printf("\n", i+1);
		for(int j=0; j<N; j++){
			Matriz[i][j]= 1 + rand()%100;
			printf("\t%d", Matriz[i][j]);
		}
	}
	
	//cantidad de alumnos dependiendo la carrera 
	int Carrera=0, Suma=0;
	printf("\nIngresa la carrera que requeris sumar los alumnos del 0 al 3: ");
	scanf("%d", &Carrera);
	
	for(int i=0; i<M; i++){
		if(i==Carrera){
			for(int j=0; j<N; j++){
				Suma+= Matriz[i][j];			
			}			
		}
	}
	printf("\nel total de alumnos de la carrera %d es de: %d: ", Carrera, Suma);
	
	//cantitdad total de alumnos en el curso 5
	int Ultimos=0;
	for(int j=0; j<N; j++){
		if(j==4){
			for(int i=0; i<M; i++){
				Ultimos+= Matriz[i][j];			
			}			
		}
	}
	printf("\nalumnos del ultimo año son: %d", Ultimos);
	
	//cantidad total de alumnos
	int Total=0;
	for(int i=0; i<M; i++){	
		for(int j=0; j<N; j++){
			Total+=Matriz[i][j];	
		}
	}
	printf("\nel total de alumnos son: %d", Total);
}