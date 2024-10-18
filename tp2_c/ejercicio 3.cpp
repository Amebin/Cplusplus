#include<stdio.h>

float FACTURA, LIMITE=2500.00;

main(){
	printf("ingresa el monto de la factura\n");
	scanf("%f", &FACTURA);
	
	if(FACTURA>LIMITE){
		printf("Debe abonar la facuta con cheque"); 
	} else{
		printf("Debe abonar la factura con efectivo");
	}
}
