#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fecha{
	int d,m,a;
};

struct vuelo{
	int num;
	char des[50];
	fecha fec;
	int pas;
};

int pvendidos();
int sinventas();

main(){
	FILE *vuelos;
	int N=0;
	
	if(fopen("vuelos.dat", "rb") == NULL){
		vuelos = fopen("vuelos.dat", "w+b");
		vuelo vue;
		
		if(vuelos == NULL){
		perror("Ocurrio un error al recuperar los datos del archivo");
		exit(1);
		}
		
		printf("Ingresa el numero de vuelo para comenzar o 0 para terminar: ");
		scanf("%d", &N);
		
		while(N!=0){
			vue.num = N;
			
			printf("\nIngresa el nombre del destino: ");
			_flushall();
			gets(vue.des);
			
			printf("\nIngresa el dia del vuelo: ");
			scanf("%d", &vue.fec.d);
			
			printf("\nIngresa el mes del vuelo: ");
			scanf("%d", &vue.fec.m);
			
			printf("\nIngresa el anio del vuelo: ");
			scanf("%d", &vue.fec.a);
			
			printf("\nIngresa la cantidad de pasajes vendidos: ");
			scanf("%d", &vue.pas);
			
			fwrite(&vue, sizeof(vue), 1, vuelos);
			
			
			printf("\nIngresa el numero de vuelo para comenzar o 0 para terminar: ");
			scanf("%d", &N);
		}
		
		rewind(vuelos);
		
		fread(&vue, sizeof(vue), 1, vuelos);
		while(!feof(vuelos)){
			printf("\n\nNumero de vuelo: %d", vue.num);
			printf("\nDestino: "); puts(vue.des);
			printf("Fecha del vuelo: %d/%d/%d", vue.fec.d, vue.fec.m, vue.fec.a);
			printf("\nPasajes vendidos: %d", vue.pas);
			fread(&vue, sizeof(vue), 1, vuelos);
			
		}
		fclose(vuelos);
	}
	
	
	printf("\n\nLa cantidad de pasajes vendidos es de: %d", pvendidos());
	printf("\n\nLa cantidad vuelos sin ventas es de: %d", sinventas());
}


int pvendidos(){
	FILE *vuelos;
	vuelos= fopen("vuelos.dat", "r+b");
	int totalv=0;
	vuelo vue;
	
	if(vuelos == NULL){
		perror("Ocurrio un error");
		exit(1);
	}
	fread(&vue, sizeof(vue), 1, vuelos);
	while(!feof(vuelos)){
		totalv+= vue.pas;	
		fread(&vue, sizeof(vue), 1, vuelos);	
	}
	
	fclose(vuelos);
	return totalv;
}

int sinventas(){
	FILE *vuelos;
	vuelos= fopen("vuelos.dat", "r+b");
	int encero=0;
	vuelo vue;
	
	if(vuelos == NULL){
		perror("Ocurrio un error");
		exit(1);
	}
	
	fread(&vue, sizeof(vue), 1, vuelos);
	
	while(!feof(vuelos)){
		if(vue.pas ==0){
			encero++;
		}	
		fread(&vue, sizeof(vue), 1, vuelos);	
	}
	
	fclose(vuelos);
	return encero;
}

