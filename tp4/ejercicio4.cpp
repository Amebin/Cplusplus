#include<stdio.h>
void Cantidad(int &Cant);
void Ingresador(int Largo, int Vector[]);
void Ordenador(int Vector1[], int Vector2[], int Vector3[], int Canti3);
int cont= 1;
main(){
	int Cant1, Cant2, Cant3;
	Cantidad(Cant1);
	Cantidad(Cant2);
	Cant3=Cant1+Cant2;
	int VectorA[Cant1], VectorB[Cant2], VectorC[Cant3];
	
	cont=1;
	Ingresador(Cant1, VectorA);
	Ingresador(Cant2, VectorB);
	
	Ordenador(VectorA, VectorB, VectorC, Cant3);
	cont=0;
	while(cont<Cant3){
		printf("\nElemento %d del vector 3: %d", cont, VectorC[cont]);
		cont++;
	}
	
}

void Cantidad(int &Cant){
	
	printf("\nIngresa el tamaño del vector %d: ", cont);
	scanf("%d", &Cant);
	cont++;
}
void Ingresador(int Largo, int Vector[]){
	int i=0;
	
	while(i<Largo){
		printf("\nIngresa el valor %d del vector %d: ", i+1, cont);
		scanf("%d", &Vector[i]);
		i++;
	}
	cont++;
}
void Ordenador(int Vector1[], int Vector2[], int Vector3[], int Canti3){
	int i=0, e=0, Aux, Bandera;
	while(i<Canti3){
		Vector3[i]=Vector1[e];
		i++;
		Vector3[i]=Vector2[e];
		i++;
		e++;
	}
	
	do{
		 Bandera=0;
		 for(i=0;i<Canti3-1; i++){
		 	if(Vector3[i]>Vector3[i+1]){
		 		Aux= Vector3[i];
		 		Vector3[i]= Vector3[i+1];
		 		Vector3[i+1]=Aux;
		 		Bandera=1;
			 }
		 }
	}while(Bandera==1);
}
