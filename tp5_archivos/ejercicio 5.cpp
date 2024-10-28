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
	int cantidad;
	fecha ven;
};

main(){
	float Caro=0, Total=0;
	int Out=0, Codigo, band=0;
	registro Art;
	FILE *productos;
	productos= fopen("productos.dat", "r+b");
	
	fread(&Art, sizeof(registro), 1, productos);
	
	while(!feof(productos)){
		if(Art.precio>10000){
			Caro++;
		}
		if(Art.cantidad ==0){
			Out++;
		}
		Total++;
		fread(&Art, sizeof(registro), 1, productos);	
	}
	
	printf("\n\nEl porcentaje de productos de precio mayor a 10000 son: %.2f", Caro/Total*100);
	printf("\n\nEl total de productos sin stock son: %d", Out);
	
	rewind(productos);
	printf("\n\nListar archivo: ");
	
	fread(&Art, sizeof(registro), 1, productos);	
	while(!feof(productos)){
		
			printf("\n\nCodigo del articulo: %d", Art.codigo);
		
			printf("\nDescripcion del articulo: ");	puts(Art.descripcion);
		
			printf("Precio del articulo: %.2f",Art.precio);
			
			printf("\nCantidad de articulos: %d",Art.cantidad);
		
			printf("\nVencimiento del articulo: %d/%d/%d", Art.ven.dia, Art.ven.mes, Art.ven.anio);
			
		fread(&Art, sizeof(registro), 1, productos);
		
	}
	
	printf("\nPosicion puntero %d", ftell(productos));
	
	rewind(productos);
	printf("\n\nIngresa el codigo a buscar y modificar: ");
	scanf("%d", &Codigo);
	
	printf("\nPosicion puntero %ld", ftell(productos));
	
	fread(&Art, sizeof(registro), 1, productos);
	while(feof(productos)==0 and band==0){
		
		if(Art.codigo == Codigo){
			printf("\nIngresa el nuevo dia de vencimiento: ");
			scanf("%d", &Art.ven.dia);
			
			printf("Ingresa el nuevo mes de vencimiento: ");
			scanf("%d", &Art.ven.mes);
			
			printf("Ingresa el nuevo anio de vencimiento: ");
			scanf("%d", &Art.ven.anio);
			
			fseek(productos,-sizeof(registro),SEEK_CUR);
					
			fwrite(&Art, sizeof(registro), 1, productos);			
		
			band=1;	
		}else{
			fread(&Art, sizeof(registro), 1, productos);
		}		
	}
	
	if(band!=1){
		printf("\n\nNo se encuentra el archivo a modificar");
	}
	
	rewind(productos);
	printf("\n\nListar archivo post modificacion: ");
	
	fread(&Art, sizeof(registro), 1, productos);	
	while(!feof(productos)){
		
			printf("\n\nCodigo del articulo: %d", Art.codigo);
		
			printf("\nDescripcion del articulo: ");	puts(Art.descripcion);
		
			printf("Precio del articulo: %.2f",Art.precio);
			
			printf("\nCantidad de articulos: %d",Art.cantidad);
		
			printf("\nVencimiento del articulo: %d/%d/%d", Art.ven.dia, Art.ven.mes, Art.ven.anio);
		
		
		fread(&Art, sizeof(registro), 1, productos);
		
	}
	
	fclose(productos);
	
}