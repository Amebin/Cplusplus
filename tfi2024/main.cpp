#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "inicioSesion.h"
#include "crudPersonas.h"
#include "crudAlimentos.h"
#include "reportes.h"
#include "crudAsientos.h"

main(){
	bool validaInicioSesion;
	char opcionDeGestion;	
	if(fopen("personas.dat", "rb") == NULL){
		printf("\nBienvenido por primera vez a la aplicacion, vos seras el administrador, a continuacion te pedire tu nombre, apellido, sexo y anio de nacimiento.");
		printf("\nLuego de completar los datos, podras iniciar sesion con el usuario 'admin' y la contrasenia 'admin'");
		
		primerIngreso();		
	}
	do{
		validaInicioSesion=false;
		printf("\nBiendenido/a al sistema Merenderos.");
		menuInicioSesion(validaInicioSesion);
		
		persona personaLogueada;
		if(validaInicioSesion!=false){	
			
			leerDatosLogueado(personaLogueada);
			
			limpiarPantalla();
			if(strcmp(personaLogueada.sexo, "f") == 0){
				printf("Bienvenida: ");
			}else{
				printf("Bienvenido: ");
			}
			
			 puts(personaLogueada.nombre);
		}
			opcionDeGestion='0';
		while(opcionDeGestion!='6' && validaInicioSesion!=false){		
		
			printf("\nElige una opcion para continuar: ");
			
			printf("\n1. Modulo personas.");
			printf("\n2. Modulo stock/inventario.");
			printf("\n3. Modulo recetas.");
			printf("\n4. Modulo Analis Personas."); 
			printf("\n5. Modulo sillas/porciones.");
			printf("\n6. Cerrar sesion.");	
			
			printf("\n\nIngresa la opcion correspondiente: ");
			_flushall();
			scanf("%c", &opcionDeGestion);

			switch(opcionDeGestion){
				case '1':	
					limpiarPantalla();
					moduloPersonas(personaLogueada);
					break;
					
				case '2':
					limpiarPantalla();
					moduloAlimentos();
					break;
				
				case '3':
					limpiarPantalla();
					system("crudRecetas.exe"); 
					break;
				
				case '4':
					limpiarPantalla();
					moduloReporte();
					break;
				
				case '5':
					limpiarPantalla();
					moduloAsientos();
					break;
				
				case '6':
					printf("\nSaliendo del sistema...");
					break;
				
				default:
					printf("\nLa opcion ingresada no es valida.");
					printf("\nPor favor, intenta nuevamente.");
					break;					
			}
		}
		}while(validaInicioSesion!=false);
	
	
}