#include<stdio.h>

void Operadora(float Numerin, int Totalidad, float &Acumulador, float &Promediar);

main(){
	int Contador, Cantidad;
	float  Numero, Suma, Promedio;
	
	printf("ingresa la cantidad de numeros a trabajar: ");
	scanf("%d", &Cantidad);
	
	while(Contador < Cantidad){
		printf("Ingresa el numero %d: ", Contador+1);
		scanf("%f", &Numero);
		
		Operadora(Numero, Cantidad, Suma, Promedio);
		
		Contador++;
	}
	
	printf("El resultado final de la Suma es: %.2f, y del promedio es %.2f", Suma, Promedio);
}

void Operadora(float Numerin, int Totalidad, float &Acumulador, float &Promediar){
	Acumulador= Acumulador + Numerin;
	
	Promediar= Acumulador / Totalidad;
}
