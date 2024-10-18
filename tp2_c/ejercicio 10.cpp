#include<stdio.h>

main(){
	int Duracion=0; 
	float Costo=0;
	
	printf("Ingresa la duracion de la llamada en minutos: ");
	scanf("%d", &Duracion);
	
	if(Duracion<=3){
		Costo= Duracion * 120;
	} else{
		Costo= (3 * 120) + ((Duracion-3)* 65);
	}
	
	printf("El costo total de la llamada es de: %.2f", Costo);
}