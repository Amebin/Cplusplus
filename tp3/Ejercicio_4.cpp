#include<stdio.h>
//tomamos el ejercicio 3 y realizamos leves modificaciones, no necesitamos crearlo desde 0
void Operadora(float R, float &Perimetrar, float &Superficiar);

main(){
	int Contador, Cantidad;
	float  Radio, Perimetro, Superficie;
	
	printf("ingresa la cantidad de numeros a trabajar: ");
	scanf("%d", &Cantidad);
	
	while(Contador < Cantidad){
		printf("\nIngresa el Radio %d: ", Contador+1);
		scanf("%f", &Radio);
		
		Operadora(Radio, Perimetro, Superficie);
		printf("El resultado del Radio %d Perimetro es: %.2f, y del Superficie es %.2f", Contador+1, Perimetro, Superficie);
		Contador++;
	}
	
	
}

void Operadora(float R, float &Perimetrar, float &Superficiar){
	Perimetrar= 2 * 3.14 * R;
	
	Superficiar= 3.14 * (R * R);
}
