#include<stdio.h>

int Evaluador(int DatoA);

main(){
	int Cantidad, Numero, Resultado;
	
	printf("Ingresa la cantidad de numeros enteros a evaluar: ");
	scanf("%d", &Cantidad);
	
	for( int Contador=0; Contador < Cantidad ; Contador++){
		
		printf("\nIngresa el numero %d a evaluar: ", Contador+1);
		scanf("%d", &Numero);
		
		Resultado= Evaluador(Numero);
		
		if(Resultado != 0){
			printf("El numero %d es menor a 25", Numero);
		} else {
			printf("El numero %d es mayor a 25", Numero);	
		}
	}
}

int Evaluador(int DatoA){
	int Booleano;
	Booleano = DatoA < 25;
	return Booleano;
}
