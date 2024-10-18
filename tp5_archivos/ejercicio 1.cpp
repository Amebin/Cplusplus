#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main(){
	FILE *edades;
	edades = fopen("edades.dat", "ab");
	int edad=1;
	
	if(edades!=NULL){
		printf("\nIngresa la edad o 0(cero) para terminar: ");
		scanf("%d", &edad);
			
		while(edad!=0){
			fwrite(&edad, sizeof(int),1, edades);
			
			printf("\nIngresa la edad o 0(cero) para terminar: ");
			scanf("%d", &edad);
		}
	}else{
		printf("No se encontro el archivo edades.dat");
	}
	
	fclose(edades);
}