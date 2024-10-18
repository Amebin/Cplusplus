#include<stdio.h>

main(){
	int Numero, Multiplicacion;
	
	printf("Ingresa el numero a evaluar");
	scanf("%d", &Numero);
	
	if(Numero > 0){
		Multiplicacion = Numero * 5;
		printf("%d", Multiplicacion);
	} else {
		printf("el numero %d, es un numero negativo", Numero);
	}
	
	
}
