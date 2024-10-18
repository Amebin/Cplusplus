#include<stdio.h>

int Perimetro(int Lado1, int Lado2);

main(){
	int Cantidad, Contador=0, DatoA, DatoB, Sumador; 
	
	printf("\nIngresa la cantidad de rectangulos a calcular su perimetro: ");
	scanf("%d", &Cantidad);
	while(Contador < Cantidad){  
		printf("Datos del rectangulo %d", Contador+1); 
		
		printf("\nIngresa lado 1: ");
		scanf("%d", &DatoA);
		printf("Ingresa lado 2: ");
		scanf("%d", &DatoB);
		
		Sumador= Perimetro(DatoA, DatoB);
		
		printf("%d", Sumador);
		Contador++;
	}
}

int Perimetro(int Lado1, int Lado2){ 
	int Resultado;
	Resultado=(Lado1 + Lado2) * 2;
	return Resultado;
}
