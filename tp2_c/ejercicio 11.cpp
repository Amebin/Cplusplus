#include<stdio.h>

main(){
	float Horas=0, Salario=0;
	
	printf("Ingresa las horas trabajadas del mes: ");
	scanf("%f", &Horas);
	
	if(Horas<=180){
		Salario= Horas * 560;
	} else{
		Salario= (180*560)+((Horas-180)*200);
	}
	
	printf("El salario del mes es de: %.2f", Salario);
}