#include<stdlib.h>
#include<stdio.h>
#include<string.h>

main(){
	char Cadena[200];
	char Palabra[30];
	char *Posicion;
	
	printf("Ingresa el texto: ");
	gets(Cadena);
	_flushall();
	
	strupr(Cadena);
	puts(Cadena);
	
	printf("\nIngresa la Palabra a buscar en el texto: ");
	gets(Palabra);
	_flushall();
	
	strupr(Palabra);
	int Lugar=1;
	/*posible solucion 1
	Posicion= strstr(Cadena, Palabra);
	
	
	if (Posicion != NULL) {
    
        int indice = Posicion - Cadena;
        printf("\nLa palabra '%s' se encontro en el texto en la posicion %d.\n", Palabra, indice);
    } else {
        printf("\nLa palabra '%s' no se encontro en el texto.\n", Palabra);
    }*/
    
    //posible solucion 2 - necesita adaptarse para verificar letra por letra 
    for(int i=0; i<strlen(Cadena); i++){
    	if(Cadena[i]== Palabra[0]){
    		printf("\nLa palabra '%s' se encontro en el texto en la posicion %d.\n", Palabra, Lugar);
    		break;
			
		}else{
			Lugar++;
		}
	}
	
}