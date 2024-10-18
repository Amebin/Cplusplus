#include<stdio.h>

main(){
	float Nfinal=0, N1=0, N2=0, Tfi=0, Prom=0;
	
	printf("Ingresa la nota 1 de la asignatura 1: ");
	scanf("%f", &N1);
		
	printf("Ingresa la nota 2 de la asignatura 1: ");
	scanf("%f", &N2);
	
	Prom+= ((N1+N2)/2)*0.2;
	
	printf("Ingresa la nota 1 de la asignatura 2: ");
	scanf("%f", &N1);
		
	printf("Ingresa la nota 2 de la asignatura 2: ");
	scanf("%f", &N2);
	
	Prom+= ((N1+N2)/2)*0.3;
	
	printf("Ingresa la nota del TFI: ");
	scanf("%f", &Tfi);
	
	Prom+= Tfi*0.5;
	
	printf("la nota final es de %.2f: ", Prom);	
}