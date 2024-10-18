#include<stdio.h>

main(){
	float Ingreso=0, Impuestos=0;
	
	printf("Proporciona el ingreso del trabajador: ");
	scanf("%f", &Ingreso);
	
	if(Ingreso<=50000){
		printf("No paga impuestos");
	} else if(Ingreso>50000 && Ingreso<=80000){
		Impuestos= Ingreso*0.015;
		printf("Debe pagar %2.f de impuestos.", Impuestos);
	} else{
		Impuestos= Ingreso*0.02;
		printf("Debe pagar %2.f de impuestos.", Impuestos);
	}
}