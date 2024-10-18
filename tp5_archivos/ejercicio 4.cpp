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
	productos= fopen("productos.dat", "ab");
	int codigo=1;
	
	printf("Ingresa el codigo del nuevo articulo: ");
	scanf("%d", &codigo);
	
	while(codigo!=0){
		Art.codigo= codigo;
		_flushall();
		
		printf("Ingresa la descripcion del articulo: ");
		gets(Art.descripcion);
		
		printf("Ingresa el precio del articulo: ");
		scanf("%f", &Art.precio);
		
		printf("Ingresa el dia de vencimiento del articulo: ");
		scanf("%d", &Art.ven.dia);
		
		printf("Ingresa el mes de vencimiento del articulo: ");
		scanf("%d", &Art.ven.mes);
		
		printf("Ingresa el año de vencimiento del articulo: ");
		scanf("%d", &Art.ven.anio);
		
		fwrite(&Art, sizeof(registro), 1, productos);
		
		printf("Ingresa el codigo del nuevo articulo: ");
		scanf("%d", &codigo);
	}
	
	fclose(productos);
}
