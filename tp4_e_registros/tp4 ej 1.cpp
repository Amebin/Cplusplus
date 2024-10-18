#include<stdlib.h>
#include<stdio.h>
#include<string.h>
// ejercicios uno y dos combinados

struct Fecha{
	int dia;
	int mes;
	int ano;	
};
struct Articulo{
	int codigo;
	char descripcion[50];
	float precio;
	Fecha vencimiento;
};

main(){
	int N=1, c=0, i=0;
	Articulo art[50];
	
	while(N!=0){
		printf("ingresa el codigo del producto (o 0 para finalizar): ");
		scanf("%d", &N);
		
		if(N!=0){
			art[i].codigo= N;
			_flushall();
			
			printf("Ingresa la descripcion del producto: ");
			gets(art[i].descripcion);
			
			printf("Ingresa el precio: ");
			scanf("%f", &art[i].precio);
			
			printf("Ingresa dia del vencimiento: ");
			scanf("%d", &art[i].vencimiento.dia);
			
			printf("Ingresa mes del vencimiento: ");
			scanf("%d", &art[i].vencimiento.mes);
			
			printf("Ingresa año del vencimiento: ");
			scanf("%d", &art[i].vencimiento.ano);
			
			i++;
			c++;
		}
	}
	
	
	for(i=0; i<c; i++){
		printf("\nEl producto %d: \ncodigo: %d", i+1, art[i].codigo);
		printf("\nDescripcion: "); puts(art[i].descripcion);
		printf("Precio: %.2f", art[i].precio);
		printf("\nFecha de vencimiento: %d/%d/%d", art[i].vencimiento.dia, art[i].vencimiento.mes,art[i].vencimiento.ano);
	}
}