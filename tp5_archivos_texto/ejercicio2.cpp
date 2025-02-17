#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main(){
	FILE *ciudades;
	FILE *provincia;
	int N, i=0;
	char aux[25], aux2[25];
	
	if(fopen("ciudades.txt", "r") == NULL || fopen("provincia.txt", "r") == NULL){
		provincia = fopen("provincia.txt", "w");
		ciudades = fopen("ciudades.txt", "w");
		
		if(provincia == NULL || ciudades == NULL){
			perror("Error en la apertura del archivo");
			exit(1);
		}
		
		printf("Ingresa la cantidad de ciudades a ingresar: ");
		scanf("%d", &N);
		
		while(i<N){
			printf("\nIngresa el nombre de la ciudad: ");
			_flushall();
			gets(aux);
			fprintf(ciudades, strcat(aux, "\n"));
			
			printf("\nIngresa el nombre de la provincia: ");
			_flushall();
			gets(aux2);
			fprintf(provincia, strcat(aux2, "\n"));
			
			i++;
		}
		
		fclose(ciudades);
		fclose(provincia);
		
	}//fin del if de creacion 
	
	
	//lectura 
	provincia = fopen("provincia.txt", "r+");
	ciudades = fopen("ciudades.txt", "r+");
		
	if(provincia == NULL || ciudades == NULL){
		perror("Error en la apertura del archivo");
		exit(1);
	}

	fgets(aux, 25, ciudades);
	fgets(aux2, 25, provincia);
	while(!feof(ciudades) && !feof(provincia)){
		printf("\n\nCiudad: %s", aux);
		printf("\nprovincia: %s", aux2);
		
		fgets(aux, 25, ciudades);
		fgets(aux2, 25, provincia);
	}
	
	rewind(ciudades);
	rewind(provincia);
	
	char aux3[25];
	printf("\n\nIngresa el nombre de una provincia para indicar sus ciudades registradas: ");
	_flushall();
	gets(aux3);
	strcat(aux3, "\n");
	
	fgets(aux, 25, ciudades);
	fgets(aux2, 25, provincia);
	while(!feof(ciudades) && !feof(provincia)){
	
		if(strcmp(aux2, aux3) == 0){
		printf("\n\nCiudad: %s", aux);
		printf("\nprovincia: %s", aux2);
		}
		
		fgets(aux, 25, ciudades);
		fgets(aux2, 25, provincia);
	}
	
	fclose(ciudades);
	fclose(provincia);
}