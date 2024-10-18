#include<stdio.h>

void Ingresador(int Cant, int Vec[]);
int Sumador(int Vec[], int Cant);

main(){
	int Cantidad, Sumatoria=0;
	
	printf("Ingresa el largo del vector: ");
	scanf("%d", &Cantidad);
	
	int Vector[Cantidad];
	Ingresador(Cantidad, Vector);
	Sumatoria=Sumador(Vector, Cantidad);
	printf("\nSe muestra la sumatoria de los elementos del Vector: %d", Sumatoria);
}

void Ingresador(int Cant, int Vec[]){
	int Cont=0;
	while(Cont<Cant){
		printf("Ingresa el valor %d del Vector: ", Cont+1);
		scanf("%d", &Vec[Cont]);
		Cont++;
	}
}

int Sumador(int Vec[], int Cant){
	int Cont=0, Suma=0;
	while(Cont<Cant){
		Suma=Suma + Vec[Cont];
		Cont++;
	}
	return Suma;
}