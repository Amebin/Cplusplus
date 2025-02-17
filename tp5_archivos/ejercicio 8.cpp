#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct empleado{
	int legajo;
	char nombreUsuario[11];
	char contrasenia[32];
	float sueldo;
	int edad;
};

void Cargar();
void Calcular(float &t, float &pS, float &pE);

main(){
	FILE *empleados;
	float total, promS, promE;
	
//	if(fopen("empleados.dat", "rb") == NULL){
		Cargar();
//	}
	
	Calcular(total, promS, promE);
	
	printf("\n\nEl total de sueldos es de: %.2f", total);
	printf("\n\nEl promedio de sueldos es de: %.2f", promS);
	printf("\n\nEl promedio de edades es de: %.2f", promE);
	
	
}

void Cargar(){
	FILE *empleados;
	empleados =fopen("empleados.dat", "w+b");
	empleado emp;
	int leg;
	
	if(empleados == NULL){
		perror("Ocurrio un error al recuperar los datos del archivo");
		exit(1);
	}
	
	printf("Ingresa el legajo del empleado: ");
	scanf("%d", &leg);
	
	while(leg!=0){
		emp.legajo=leg;
		
		printf("\nIngresa el apellido y nombre del empleado: ");
		_flushall();
		gets(emp.nombreUsuario);
		
		printf("\nIngresa el cargo: ");
		_flushall();
		gets(emp.contrasenia);
		
		/*printf("\nIngresa el sueldo del empleado: ");
		scanf("%f", &emp.sueldo);
		
		printf("\nIngresa la edad del empleado: ");
		scanf("%d", &emp.edad);*/
		
		fwrite(&emp, sizeof(emp), 1, empleados);
		
		printf("Ingresa el legajo del siguiente empleado: ");
		scanf("%d", &leg);
	}
	
	rewind(empleados);
	fread(&emp, sizeof(emp), 1, empleados);
	while(!feof(empleados)){
		printf("\n\nLegajo: %d", emp.legajo);
		printf("\nApellido y nombre: "); puts(emp.nombreUsuario);
		printf("Cargo: "); puts(emp.contrasenia);
		printf("Sueldo: %.2f", emp.sueldo);
		printf("\nEdad: %d", emp.edad);
		
		fread(&emp, sizeof(emp), 1, empleados);
	}
	
	fclose(empleados);
}

void Calcular(float &t, float &pS, float &pE){
	FILE *empleados;
	empleados =fopen("empleados.dat", "rb");
	empleado emp;
	int C=0;
	float e=0;
	
	fread(&emp, sizeof(emp), 1, empleados);
	
	while(!feof(empleados)){
		t+=emp.sueldo;
		e+=emp.edad;
		C++;
		fread(&emp, sizeof(emp), 1, empleados);	
	}
	
	pS= t/C;
	pE= e/C;
	
	
	fclose(empleados);
}