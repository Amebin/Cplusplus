#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//definimos el typedef de caracteres para posteriormente crear el array de nombres 40 c max
typedef char nombre[40];

main(){
	int Cantidad, i, B, C=0;
	
	
	printf("Ingresa la cantidad de nombres de personas: ");
	scanf("%d", &Cantidad);
	_flushall();
	
	//reservamos en memoria el espacio de acuerdo a la cantidad
	//esta practica es poco recomendada ya que la ultima posicion almacena el caracter que indica el fin de la misma
	//se recomienda reservar +1 el espacio o reservar de sobra (reservar 100 lugares como se hace comunmente)
	// posteriormente cargamos los datos pidiendolos al usuario 
	nombre Lista1[Cantidad], Ordenada[Cantidad], Aux;
	
	for(i=0; i<Cantidad; i++){
		printf("\nIngresa el nombre %d: ", i+1);
		gets(Lista1[i]);
		_flushall();	
	}
	
	//utilizamos un metodo de ordenamiento, el mismo que para numeros, pero ahora aplicado a caracteres y por orden alfabetico
	do{
		B=0;
		for(i=0; i<Cantidad-1; i++){
			
			if(strcmp(Lista1[i], Lista1[i+1])>0){
				strcpy(Aux, Lista1[i]);
				strcpy(Lista1[i], Lista1[i+1]);
				strcpy(Lista1[i+1], Aux);
				B=1;
			}
		}
	}while(B==1);
	
	//imprimimos el array ordenado 
	for(i=0; i<Cantidad; i++){
		printf("\nNombre %d de la lista ya ordenada alfabeticamente: %s", i+1, Lista1[i]);
	}
	
	
	//repetimos metodo de ordenamiento pero esta vez de acuerdo a la longitud del nombre
	int L1, L2;
	do{
		B=0;
		for(i=0; i<Cantidad-1; i++){
			L1=strlen(Lista1[i]);
			L2= strlen(Lista1[i+1]);
			if(L1>L2){
				strcpy(Aux, Lista1[i]);
				strcpy(Lista1[i], Lista1[i+1]);
				strcpy(Lista1[i+1], Aux);
				B=1;
			}
		}
	}while(B==1);
	
	//imprimimos el array ordenado 
	for(i=0; i<Cantidad; i++){
		
		printf("\nNombre %d de la lista ordenada por length: %s", i+1, Lista1[i]);
	}
}