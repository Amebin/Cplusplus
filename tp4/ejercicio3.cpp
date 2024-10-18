#include<stdio.h>
void Ingresar(float Vec[], int Cant);
void Explorador(int Cant, float Vec[]);

main(){
	int Cantidad=0;
	
	printf("Ingresa el tamaño de la lista: ");
	scanf("%d", &Cantidad);
	
	float Vector[Cantidad];
	Ingresar(Vector, Cantidad);
	Explorador(Cantidad, Vector);
}

void Ingresar(float Vec[], int Cant){
	int Cont=0;
	
	while(Cont<Cant){
		printf("\nIngresa el valor real %d: ", Cont+1);
		scanf("%f", &Vec[Cont]);
		
		Cont++;
	}
}

void Explorador(int Cant, float Vec[]){
	int Cont, Repes=0, Pos, Vec2[Cant];
	float  Max=0;
	
	for(Cont=0; Cont<Cant; Cont++){
		if(Vec[Cont]>Max){
			Max= Vec[Cont];
		}			
	}
	
	for(Cont=0; Cont<Cant; Cont++){
		if(Vec[Cont]==Max){
			Vec2[Repes]= Cont;
			Repes++;
		}
	}
	
	printf("El valor maximo es: %.2f . La cantidad de veces que aparece es de %d en las siguientes posiciones: ", Max, Repes);
	for(Cont=0; Cont<Repes; Cont++){
		printf("%d \n", Vec2[Cont]);
	}
}






