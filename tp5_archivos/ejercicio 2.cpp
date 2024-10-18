#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main(){
	FILE *temperaturas;
	temperaturas = fopen("temperaturas.dat", "ab");
	float temp;
	
	if(temperaturas!=NULL){
		printf("\nIngresa la temperatura o 0(cero) para terminar: ");
		scanf("%f", &temp);
			
		while(temp!=0){
			fwrite(&temp, sizeof(float),1, temperaturas);
			
			printf("\nIngresa la temperatura o 0(cero) para terminar: ");
			scanf("%f", &temp);
		}
	}else{
		printf("No se encontro el archivo temperaturas.dat");
	}
	
	fclose(temperaturas);
	
	
}