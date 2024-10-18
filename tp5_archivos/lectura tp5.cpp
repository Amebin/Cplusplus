#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fecha{
	int dia, mes, anio;
};

struct registro{
	int codigo;
	char descripcion[30];
	float precio;
	fecha ven;
};

main(){
	registro Art;
	FILE *productos;
	productos= fopen("productos.dat", "r+b");
	
	fread(&Art, sizeof(registro), 1, productos);
	
	while(!feof(productos)){
		if(Art.ven.mes==11 && Art.ven.anio==2024){
			printf("\n\nCodigo del articulo: %d", Art.codigo);
		
			printf("\nDescripcion del articulo: ");	puts(Art.descripcion);
		
			printf("Precio del articulo: %.2f",Art.precio);
		
			printf("\nVencimiento del articulo: %d/%d/%d", Art.ven.dia, Art.ven.mes, Art.ven.anio);
		}
		
		fread(&Art, sizeof(registro), 1, productos);
		
	}
	
	fclose(productos);
	
}