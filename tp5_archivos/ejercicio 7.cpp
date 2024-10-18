#include<stdio.h>
#include<stdlib.h>

struct alum{
	int legajo;
	int nota[4];
};

main(){
	alum alumno;
	FILE *alumnos, *aux;
	int b, leg;
	
	alumnos= fopen("alumnos.dat", "a+b");
	aux= fopen("aux.dat", "wb");
	
	if (alumnos == NULL) {
        perror("Error al abrir alumnos.dat");
        return 1;
    }

    if (aux == NULL) {
        perror("Error al abrir aux.dat");
        fclose(alumnos);
        return 1;
    }

	printf("Ingrese un numero de legajo a ingresar: ");
	scanf("%d",&leg);

	while(leg!=0){
		alumno.legajo=leg;
		
		printf("Ingresa la primera nota: ");
		scanf("%d", &alumno.nota[0]);
		
		printf("Ingresa la segunda nota: ");
		scanf("%d", &alumno.nota[1]);
		
		printf("Ingresa la tercera nota: ");
		scanf("%d", &alumno.nota[2]);
		
		fwrite(&alumno, sizeof(alum), 1, alumnos);
		
		printf("Ingrese un numero de legajo a ingresar: ");
		scanf("%d",&leg);

	}
	
	rewind(alumnos);
	fread(&alumno, sizeof(alum), 1, alumnos);
	while(!feof(alumnos)){
		printf("\n\nLegajo ingresado: %d", alumno.legajo);
		fread(&alumno, sizeof(alum), 1, alumnos);
	}
	
	
	printf("\nIngrese un numero de legajo a dar de BAJA: ");
	scanf("%d",&leg);
	
	rewind(alumnos);
	fread(&alumno, sizeof(alum), 1, alumnos);
	b=0;
	
	while(!feof(alumnos)){
		if(alumno.legajo!=leg){
			fwrite(&alumno, sizeof(alum), 1, aux);
		}else{
			b=1;
		}
		
		fread(&alumno, sizeof(alum), 1, alumnos);
	}
	
	
	
	if (b==1) {
 		printf("\n\nRegistro dado de baja");
 	}  	
 	
 	
 	
 	
 	fclose(alumnos);
 	fclose(aux);
 	remove("alumnos.dat");
 	rename("aux.dat", "alumnos.dat");
}
