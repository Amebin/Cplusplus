#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char cadena[25];

main(){
	
	int i,j,c=0, N=0;
	cadena Prov;
	printf("Ingresa la cantidad de ciudades a ingresar: ");
	scanf("%d", &N);
	_flushall();
	cadena Matriz[N][2];
	
	
	for(i=0; i<N; i++){
		
			printf("\nIngresa el nombre de la ciudad: "); gets(Matriz[i][1]); _flushall();
			
			printf("\nIngresa el nombre de la Provincia: "); gets(Matriz[i][2]); _flushall();
		
	}
	
	printf("Ingresa el nombre de la provincia para saber la cantidad de ciudades que posee: ");
	gets(Prov); _flushall;
	
	for(i=0; i<N; i++){
		if(strcmp(Matriz[i][2], Prov) == 0)
			c++;	
	}
	
	printf("\nLa provincia %s posee %d ciudades", Prov, c);
}