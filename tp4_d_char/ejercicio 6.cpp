#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main(){
	char Cadena[201];
	int Contador=0, Largo=0;
	
	printf("Ingresa el texto en la cadena max 200 caracteres: ");
	gets(Cadena);
	
	Largo= strlen(Cadena);
	
	for(int i=0; i<Largo; i++){
		if(Cadena[i]==' '){
			Cadena[i]='#';
			Contador++;
		}
	}
	
	puts(Cadena);
	
	printf("La cantidad de reemplazos que se realizo fue de: %d", Contador);
}