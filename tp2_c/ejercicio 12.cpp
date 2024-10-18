#include<stdio.h>

main(){
	float Sueldos=0, Basico=0, Anti=0.1, Familiar=12500.00, Jub=0.14, Seguro=1500.00;
	
	printf("Ingresa el salario basico para calcular la liquidacion: ");
	scanf("%f", &Basico);
	
	Sueldos= Basico + Basico * Anti + Familiar - Basico * Jub - Seguro;
	
	printf("El sueldo es de: %.2f. Basico: %.2f, Antiguedad: +%.2f, Familiar: +%2.f, Jubilacion: -%2.f, Seguro: -%2.f.",
	 Sueldos, Basico, Basico*Anti, Familiar, Basico*Jub, Seguro);
}