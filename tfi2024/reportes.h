#include<ctype.h>
#include<stdio.h>
#include <time.h>
#include<string.h>

// Asegúrate de que esta estructura coincida con la usada en los otros archivos


// Función para contar hombres
void contarMasculino() {
    FILE *personas;
    personas = fopen("personas.dat", "rb");
    if(personas == NULL) {
        perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
        exit(1);
    }
    int contadorMasculinos = 0;
    registrados personaRegistrada;

    while(fread(&personaRegistrada, sizeof(registrados), 1, personas) == 1) {
        if(personaRegistrada.activo ==true && strcmp(personaRegistrada.sexo, "m") == 0) {
            contadorMasculinos++;
        }
    }
    fclose(personas);
   printf("\n Cantidad de Masculinos : %d",contadorMasculinos);
}//debemos hacer los mismo con lo fememnino solo que cambia "m" x "f" y llamar la funcion en el main


// Función para contar mujeres embarazadas
void contarEmbarazadas() {
    FILE *personas;
    personas = fopen("personas.dat", "rb");
    if(personas == NULL) {
        perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
        exit(1);
    }
    int contadorEmbarazadas = 0;
    registrados personaRegistrada;

    while(fread(&personaRegistrada, sizeof(registrados), 1, personas) == 1) {
        if(personaRegistrada.activo && personaRegistrada.embarazo && strcmp(personaRegistrada.sexo, "f") == 0) {
            contadorEmbarazadas++;
        }
    }
    fclose(personas);
   printf("\n Cantidad de embarazadas : %d",contadorEmbarazadas);
}

// Función para contar personas con desnutrición (esto es un ejemplo simple, ajusta según criterios médicos reales)
void contarDesnutridos() {
    FILE *personas;
    personas = fopen("personas.dat", "rb");
    if(personas == NULL) {
        perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
        exit(1);
    }
    int contadorDesnutridos = 0;
    registrados personaRegistrada;

    while(fread(&personaRegistrada, sizeof(registrados), 1, personas) == 1) {
        if(personaRegistrada.activo) {
            // Un ejemplo muy simple de cálculo de IMC para determinar desnutrición
            float imc = personaRegistrada.peso / ((personaRegistrada.altura / 100) * (personaRegistrada.altura / 100));
            if(imc < 18.5) {  // IMC bajo considerado como desnutrición
                contadorDesnutridos++;
            }
        }
    }
    fclose(personas);
	printf("\n Cantidad de Desnutridos : %d",contadorDesnutridos);
}

// Función para contar trabajadores en el comedor
void contarTrabajadores() {
	
    FILE *personas;
    personas = fopen("personas.dat", "rb");
    if(personas == NULL) {
        perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
        exit(1);
    }
    int contadorTrabajadores = 0;
    registrados personaRegistrada;

    while(fread(&personaRegistrada, sizeof(registrados), 1, personas) == 1) {
    	if(personaRegistrada.activo==true){
        if(strstr(personaRegistrada.tipoDeColaboracion, "cocina") != nullptr ||strstr(personaRegistrada.tipoDeColaboracion, "ayuda") != nullptr)//aqui añadiremos palabras clave para los trabajadores de el comedor. para cada palabra se debe aplicar un "or"y la condicion que ahi aparece + la palabra clave 
		{
            contadorTrabajadores++;
        }
    }
    }
    fclose(personas);
   	printf("\n Cantidad de Trabajadores : %d",contadorTrabajadores) ;
}
void contarFemeninos() {
    FILE *personas;
    personas = fopen("personas.dat", "rb");
    if(personas == NULL) {
        perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
        exit(1);
    }
    int contadorFemeninos = 0;
    registrados personaRegistrada;

    while(fread(&personaRegistrada, sizeof(registrados), 1, personas) == 1) {
        if(personaRegistrada.activo ==true && strcmp(personaRegistrada.sexo, "f") == 0) {
            contadorFemeninos++;
        }
    }
    fclose(personas);
   printf("\n Cantidad de Femeninos : %d",contadorFemeninos);
}
void contarMenores() {
    FILE *personas;
    personas = fopen("personas.dat", "rb");
    if (personas == NULL) {
        perror("Ocurrió un error al abrir el archivo. Por favor, contacte al administrador");
        exit(1);
    }

    int contadorMenores = 0;
    registrados personaRegistrada;

    while (fread(&personaRegistrada, sizeof(registrados), 1, personas) == 1) {
        if (personaRegistrada.activo == true && anioActual-personaRegistrada.anioNacimiento<= 18) {
            contadorMenores++;
        }
    }

    fclose(personas);
    printf("\nCantidad de menores de edad: %d", contadorMenores);
}
void contarAdultos18() {
    FILE *personas;
    personas = fopen("personas.dat", "rb");
    if (personas == NULL) {
        perror("Ocurrió un error al abrir el archivo. Por favor, contacte al administrador");
        exit(1);
    }

    int contadorMayores = 0;
    registrados personaRegistrada;

    while (fread(&personaRegistrada, sizeof(registrados), 1, personas) == 1) {
        if (personaRegistrada.activo == true && anioActual-personaRegistrada.anioNacimiento> 18) {
            contadorMayores++;
        }
    }

    fclose(personas);
    printf("\nCantidad de mayores de edad: %d", contadorMayores);
}

void moduloReporte(){
	
	printf("\nGestion de Reportes\n");
	char GestionReportesOpcion;
	
	do{
		printf("\nA continuacion, elige la opcion de lo que deseas hacer: \n");
		
		printf("\n1. Contar Masculinos .");
		printf("\n2. Contar Embarazadas");
		printf("\n3. Contar Desnutridos.");
		printf("\n4. Contar Trabajadores.");
		printf("\n5. Contar Menores.");
		printf("\n6. Contar Femeninos.");
		printf("\n7. Contar Adultos +18.");
		printf("\n8. Volver al menu anterior.\n");
		
		printf("\nIngresa la opcion correspondiente: ");
		_flushall();
		scanf("%c", &GestionReportesOpcion);
		
		switch(GestionReportesOpcion){
			case '1':
				contarMasculino();
				break;
					
			case '2':
				contarEmbarazadas();
				break;
			
			case '3':
				contarDesnutridos();
				break;
			
			case '4':
				contarTrabajadores();	
				break;
			case '5':
				contarMenores();	
				break;
			case '6':
				contarFemeninos();	
				break;
			case '7':
				contarAdultos18();	
				break;
			case '8':
				printf("\nVolviendo al menu anterior.");		
				break;

			default:
				printf("\nLa opcion ingresada no es valida.");
				printf("\nPor favor, intenta nuevamente.");
				break;	
		}
		
	}while(GestionReportesOpcion!='8');
	
}