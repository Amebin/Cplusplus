#include<stdio.h>

float N1, N2, N3, N4, N5, SUMA, PROMEDIO;

main(){
	printf("ingresa los numeros a sumar\n");
	scanf("%f %f %f %f %f", &N1, &N2, &N3, &N4, &N5);
	
	SUMA= N1 + N2 + N3 + N4 + N5;
	PROMEDIO= SUMA/5;
	
	printf("La suma es= %.2f, el promedio es= %.2f", SUMA, PROMEDIO);
}
