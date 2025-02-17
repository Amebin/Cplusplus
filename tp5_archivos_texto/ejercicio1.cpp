#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main(){
	char Name[30];
	int N, i=0;
	FILE *provincias;
	if(fopen("provincias.txt", "r") == NULL){
		
		provincias = fopen("provincias.txt", "w+");
		
		if(provincias == NULL){
			perror("Ocurrio un error");
			exit(1);
		}
		
		printf("\nIngresa la cantidad de provincias a registrar: ");
		scanf("%d", &N);
		
		while(i<N){
			printf("\n\nNombre de la provincia: ");
			_flushall();
			gets(Name);
			
			fprintf(provincias, strcat(Name, "\n"));		
			i++;
		}
		
		rewind(provincias);
		
			
			fgets(Name, 30, provincias);
		while(!feof(provincias)){
			printf("\n%s", Name);
			
			fgets(Name, 30, provincias);
			
		}
		
		fclose(provincias);
	}
	
	provincias = fopen("provincias.txt", "r");
	if(provincias == NULL){
		perror("Ocurrio un error inesperado.");
		exit(1);
	}
	char Corto[30], Largo[30];
	int Len=0;
	fgets(Name, 30, provincias);
		while(!feof(provincias)){
			printf("\n%s", Name);
			Len= strlen(Name);
			printf("\t| %d |\n", Len);
		
			if(Len<=strlen(Corto) || strlen(Corto)==0){
		
				strcpy(Corto, Name);
			}else{
				if(Len>=strlen(Largo))
				strcpy(Largo, Name);			
			}
			fgets(Name, 30, provincias);
			
		}
		printf("\nEl nombre mas largo es: %s", Largo);
	printf("\nEl nombre mas corto es: %s", Corto);
		
		fclose(provincias);
}