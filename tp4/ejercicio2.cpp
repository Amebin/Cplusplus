#include<stdio.h>

void Ingresar(int Vec[], int Cant);
int Promediar(int Vec[], int Cant);

main(){
	int Cantidad, TotalAlumnos=0;

	printf("ingresa la cantidad de alumnos: ");
	scanf("%d", &Cantidad);
	int Vector[Cantidad];
	
	Ingresar(Vector, Cantidad);
	TotalAlumnos= Promediar(Vector, Cantidad);
	
	printf("El total de alumnos que saco una nota mayor al promedio es de: %d", TotalAlumnos);
}

void Ingresar(int Vec[], int Cant){
	int Cont=0;
	
	while(Cont<Cant){
		printf("\nIngresa la nota del alumno %d: ", Cont+1);
		scanf("%d", &Vec[Cont]);
		
		Cont++;
	}
}

int Promediar(int Vec[], int Cant){
	int Contador=0, AC=0, Sumatoria=0;
	float Promedio;
	
	while(Contador<Cant){
		AC= AC + Vec[Contador];
		Contador++;
	}
	
	Promedio= AC/Cant;
	Contador= 0;
	
	while(Contador<Cant){
		if(Vec[Contador]>Promedio)
			Sumatoria++;
		
		Contador++;	
	}
	
	return Sumatoria;
}