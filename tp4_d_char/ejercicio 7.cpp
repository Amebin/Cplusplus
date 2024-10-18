#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char Asignatura[30];

main(){
	int Alumnos[50], Total, B, AuxN;
	Asignatura Asignaturas[50], MayorC, Segunda, AuxC;
	
	
	printf("Cuantas asignaturas posee la carrera?: ");
	scanf("%d", &Total);
		_flushall();
	
	
	for(int i=0; i<Total; i++){
		
		printf("\nIngresa el nombre de la asignatura %d: ", i+1);
		gets(Asignaturas[i]);
		_flushall();
		printf("\nIngresa la cantidad de alumnos inscriptos en la asignatura %d: ", i+1);
		scanf("%d", &Alumnos[i]);
		_flushall();
	}
	
	do{
		B=0;
		for(int i=0; i<Total-1; i++){
			if(Alumnos[i]<Alumnos[i+1]){
				strcpy(AuxC, Asignaturas[i]);
				strcpy(Asignaturas[i], Asignaturas[i+1]);
				strcpy(Asignaturas[i+1], AuxC);
				
				AuxN= Alumnos[i];
				Alumnos[i]= Alumnos[i+1];
				Alumnos[i+1]=AuxN;
				
				B=1;
			}
		}
	}while(B==1);
	strcpy(MayorC, Asignaturas[0]);
	strcpy(Segunda, Asignaturas[1]);
	
	printf("\nLa asignatura con mayor cantidad de inscriptos es: %s", MayorC);
	
	printf("\nLa 2da asignatura con mayor cantidad de inscriptos es: %s", Segunda);
}
