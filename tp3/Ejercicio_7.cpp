#include<stdio.h>

void Evaluador(int A, int B, int C);

main(){
	int Alumnos, Nota1, Nota2, Nota3, Contador;
	
	printf("Ingresa la cantidad de alumnos: ");
	scanf("%d", &Alumnos);
	
	while(Contador<Alumnos){
		printf("\nIngresa las 3 notas del alumno %d: ", Contador+1);
		scanf("%d %d %d", &Nota1, &Nota2, &Nota3);
		
		Evaluador(Nota1, Nota2, Nota3);
		
		Contador++;
	}
}

void Evaluador(int A, int B, int C){
	if(A>B & A>C){
		printf("La nota mayor es la nota 1: %d\n", A);
	}else if(B>A & B>C){
		printf("La nota mayor es la nota 2: %d\n", B);
	}else{
		printf("La nota mayor es la nota 3: %d\n", C);
	}
	
}
