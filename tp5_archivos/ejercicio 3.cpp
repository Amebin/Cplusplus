#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct registro{
	int codigo;
	char descripcion[30];
	float precio;
	bool baja=false;
};

main(){
	registro Art;
	FILE *articulos;
	articulos= fopen("articulos.dat", "wb");
	int codigo=1;
	
	printf("Ingresa el codigo del nuevo articulo: ");
	scanf("%d", &codigo);
	
	while(codigo!=0){
		Art.codigo= codigo;
		_flushall();
		
		printf("\nIngresa la descripcion del articulo: ");
		gets(Art.descripcion);
		
		printf("Ingresa el precio del articulo: ");
		scanf("%f", &Art.precio);
		
		fwrite(&Art, sizeof(registro), 1, articulos);
		
		printf("Ingresa el codigo del nuevo articulo: ");
		scanf("%d", &codigo);
	}
	
	fclose(articulos);
}

