#include<stdio.h>
void Gestionador(int Dato);

main(){
	int Numero, Cantidad, Contador;
	
	printf("Ingresa la cantidda de numeros a gestionar: ");
	scanf("%d", &Cantidad);
	
	while(Contador<Cantidad){
		printf("\nIngresa el %d° numero: ", Contador+1);
		scanf("%d", &Numero);
		
		Gestionador(Numero);
		
		Contador++;
	}
	
}

void Gestionador(int Dato){
	int Calculo;
	
	if(Dato>0){
		Calculo= Dato * 5;
		printf("El numero %d es positivo, multiplicado x5 da como resultado: %d", Dato, Calculo);
	}else{
		printf("El numero es negativo, no se realizara ningun calculo");
	}
}
