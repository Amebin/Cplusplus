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
	articulos= fopen("articulos.dat", "r+b");
	int codigo=0, b=0;
	
	printf("Ingresa el codigo a dar de baja: ");
	scanf("%d", &codigo);
	
	fread(&Art, sizeof(registro), 1, articulos);
	
	while(!feof(articulos) && b==0){
		if(Art.codigo==codigo && Art.baja==false){
			
			Art.baja=true;
			fseek(articulos,- sizeof(registro),SEEK_CUR);
			fwrite(&Art, sizeof(registro), 1, articulos);
			printf("Registro dado de baja\n\n");

			b=1;
		}else{
			fread(&Art, sizeof(registro), 1, articulos);
		}
		
	
		
	}
	
	rewind(articulos); 
	fread(&Art, sizeof(registro), 1, articulos);
	
	while(!feof(articulos)){
		
		if(Art.baja!=1){
			printf("\n\nCodigo: %d", Art.codigo);
			
			printf("\nDescripcion: "); puts(Art.descripcion);
			
			printf("Precio: %.2f", Art.precio);
			
			printf("\nActivo?: %d", Art.baja);
		}
		
	
		fread(&Art, sizeof(registro), 1, articulos);
	}
	
	fclose(articulos);
}