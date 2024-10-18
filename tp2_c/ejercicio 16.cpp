#include<stdio.h>

main(){
	float Ifamiliar=0, Anticipo=0, Cuota=0;
	
	printf("Introduci el ingreso familiar: ");
	scanf("%f", &Ifamiliar);
	
	if(Ifamiliar<95000){
		printf("No podes acceder a la hipoteca");
	} else if(Ifamiliar<=95000 & Ifamiliar<120000){
		Anticipo=1800000 * 0.15;
		Cuota= ((1800000-Anticipo)*2)/(15*12);
		
		printf("\nEl monto del anticipo a entregar es de: %.2f.", Anticipo);
		printf("\nLa cantidad de cuotas es de %d de un monto de %.2f final por cuota.",(15*12), Cuota);		
	} else{
		Anticipo=1800000 * 0.2;
		Cuota= ((1800000-Anticipo)*1.1)/(10*12);
		
		printf("\nEl monto del anticipo a entregar es de: %.2f.", Anticipo);
		printf("\nLa cantidad de cuotas es de %d de un monto de %.2f final por cuota.",(10*12), Cuota);
	}
}