#include<stdio.h>
int SegIngresados, MinTotales, Horas, Minutos, Segundos;

main(){
	printf("Ingresa los segundos a transformar al formato HH:MM:SS");
	scanf("%d", &SegIngresados);
	
	MinTotales = SegIngresados / 60;
	Horas= MinTotales/ 60;   
	Minutos= MinTotales % 60; 
	Segundos= SegIngresados % 60;
	
	
	printf("Los segundos %d ingresados corresponden a %d:%d:%d, en el formato HH:MM:SS", 
	SegIngresados, Horas, Minutos, Segundos);
}
