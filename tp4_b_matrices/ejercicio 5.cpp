#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
	srand(time(0));
	//1 + rand()%10 
	
	int M=0, N=0;
	
	printf("Ingresa la cantidad de sucursales M: ");
	scanf("%d", &M);
	
	printf("Ingresa la cantidad de vendedores N: ");
	scanf("%d", &N);
	
	//creamos la matriz y la rellenamos de manera automatica
	float Matriz[M][N];
	
	for(int i=0; i<M; i++){
		printf("\n");
		for(int j=0; j<N; j++){
			Matriz[i][j]= 1 + rand()%10000;
			printf("\t%.2f", Matriz[i][j]);
		}
	}
	
	//trabajamos con la matriz para tener la sumatoria (en pesos) de lo vendido y calcular la comision
	float Sumatoria=0, Comisiones=0;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			Sumatoria+=Matriz[i][j];
		}
	}
	//calculo las comisiones y las imprimo
	
	Comisiones= Sumatoria * 0.075;
	printf("\nEl total a pagar en comisiones es de: %.2f", Comisiones);
}