#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef char Palabra[30];

main(){
	char Cadena[301], Aux[50];
	Palabra Palabras[150];
	int i=0, B, Largo;
	
	printf("Ingresa la Cadena: ");
	gets(Cadena);
	_flushall();
	
	strlwr(Cadena);
	puts(Cadena);
	
	//solo encontre solucion utilizando puntero y palabras reservadas nuevas
	char *token = strtok(Cadena, " ,.-\n\t"); 
	
    while (token != NULL && i < 150) {
        strcpy(Palabras[i], token); 
        token = strtok(NULL, " ,.-\n\t");        
        i++;
	}
	Largo= i;
	for(int j=0; j<Largo; j++){
		puts(Palabras[j]);
	}
	
	//ordenamos el vector alfabeticamente
	do{
		B=0;
		for(i=0; i<Largo-1; i++){
			
			if(strcmp(Palabras[i], Palabras[i+1])>0){
				strcpy(Aux, Palabras[i]);
				strcpy(Palabras[i], Palabras[i+1]);
				strcpy(Palabras[i+1], Aux);
				B=1;
			}
		}
	}while(B==1);
		
	for(int i=0; i<Largo; i++){
		puts(Palabras[i]);
	}	
}