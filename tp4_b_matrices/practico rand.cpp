#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
	srand(time(0)); // tomo el tiempo actual como base
	
	
	for(int i=0; i<20; i++){
	int Tiempo= 10000 + rand()%99999; //genero numero aleatorio de 2 digitos del 1 al 10 
	printf("\nel tiempo es: %d", Tiempo);// imprimo 
		
	}
}