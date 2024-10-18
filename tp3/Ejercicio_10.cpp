// ingresar la cantidad de horas trabajadas durante el mes
// Calcular Salario mensual 
//items: *180hs o menos = $560,00 la hora
// **mas de 180 hs = plus por cada hora adicional de $200,00
#include<stdio.h>

void Calculadora(int Horas, float Base, float Plus, float &Liquidacion);

main(){
	int Empleados, Contador, HsTrabajadas;
	float HsBase= 560.00, Plus= 200.00, Salario;
	
	printf("Ingresa la cantidad de empleados: ");
	scanf("%d", &Empleados);
	
	while(Contador < Empleados){
		printf("Ingresa las horas trabajadas del empleado %d: ", Contador+1);
		scanf("%d", &HsTrabajadas);
		
		Calculadora(HsTrabajadas, HsBase, Plus, Salario);
		printf("El salario mensual del trabajador %d es: $%.2f", Contador+1, Salario);
		
		Contador++;
	}
}

void Calculadora(int Horas, float Base, float Plus, float &Liquidacion){
	int Diferencias=0;
	
	Liquidacion= Horas*Base;

	if(Horas>180)
		Diferencias= Horas - 180;
		Liquidacion+= Diferencias*Plus;

}
