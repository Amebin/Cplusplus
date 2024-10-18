#include<stdio.h>

int N;

main(){
	printf("Ingresa el numero a verificar");
	scanf("%d", &N);
	
	if(N<25){
		printf("El numero %d es menor a 25", N);
	} else {
		printf("El numero %d es mayor a 25", N);
	}
}
