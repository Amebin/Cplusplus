#include<stdio.h>
#include<strings.h>

main(){
	int Lista=0, i=0, Len=0;
	char Corto[30], Largo[30], Provincia[30];
	
	printf("Ingresa la cantidad de provincias en la lista: ");
	scanf("%d", &Lista);
	_flushall();
	while(i<Lista){
		printf("\nIngresa el nombre de la Provincia %d: ", i+1);
		gets(Provincia);
		_flushall();
		Len= strlen(Provincia);
		printf("\t| %d |\n", Len);
		
		if(Len<=strlen(Corto) || strlen(Corto)==0){
		
				strcpy(Corto, Provincia);
		}else{
			if(Len>=strlen(Largo))
				strcpy(Largo, Provincia);			
		}
		i++;
	}
	printf("\nEl nombre mas largo es: %s", Largo);
	printf("\nEl nombre mas corto es: %s", Corto);
}