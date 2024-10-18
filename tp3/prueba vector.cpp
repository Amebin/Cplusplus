#include<stdio.h>

main(){
	int Longitud, Iterador;
	printf("ingresa la longitud del vector ");
	scanf("%d", &Longitud);

	int Vector[Longitud];
	
	for(Iterador=0;Iterador<Longitud; Iterador++){
		printf("\nIngresa el elemento de la posicion [%d]", Iterador);
		scanf("%d", &Vector[Iterador]);
	}
	
	for(Iterador=0;Iterador<Longitud; Iterador++){
	printf("\nElemento Vector[%d]: %d", Iterador, Vector[Iterador]);
	
	}
}
