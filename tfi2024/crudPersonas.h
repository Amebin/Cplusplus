#include<ctype.h>
#include <time.h>

time_t tiempo = time(0);  
struct tm * now = localtime(&tiempo);  
time_t comienzo = time(NULL);

int anioActual = now->tm_year + 1900;

struct registrados{
	char nombreUsuario[11];
	char contrasenia[33];
	char nombre[20], apellido[20];
	char sexo[3];
	char rol[15];
	int dni, anioNacimiento;
	float altura, peso;
	bool embarazo=false, activo=true;
	char tipoDeColaboracion[60];
	char vacunas[1000];
	
};

registrados datosPersonaLogueada;

void leerDatosLogueado(persona &personaLogueada){
	FILE *datosLogin;
	datosLogin = fopen("datosLogin.dat", "rb");
	if(datosLogin == NULL){
		perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
		exit(1);
	}
	
	fread(&personaLogueada, sizeof(registrados), 1, datosLogin);
	strcpy(datosPersonaLogueada.nombre, personaLogueada.nombre);
	strcpy(datosPersonaLogueada.apellido, personaLogueada.apellido);
	strcpy(datosPersonaLogueada.nombreUsuario, personaLogueada.nombreUsuario);
	strcpy(datosPersonaLogueada.rol, personaLogueada.rol);
	strcpy(datosPersonaLogueada.sexo, personaLogueada.sexo);
	
	fclose(datosLogin);
}
 
void verificarQueSeaUsuarioUnico(registrados nuevaPersona, bool &usuarioUnico){
	FILE *personas;
	personas = fopen("personas.dat", "r+b");
	if(personas == NULL){
		perror("Ocurrio un error al intentar validar condiciones de usuario. Por favor contacte al administrador");
		exit(1);
	}
	
	registrados persona;
	char auxPersonRegister[11], auxNuevaPerson[11];	
	strcpy(auxPersonRegister, nuevaPersona.nombreUsuario);
	strlwr(auxPersonRegister);
	usuarioUnico=true;
	fread(&persona, sizeof(registrados), 1, personas);
	while(!feof(personas) && usuarioUnico==true){
		strcpy(auxNuevaPerson, persona.nombreUsuario);
		strlwr(auxNuevaPerson);
		
		if(strcmp(auxPersonRegister, auxNuevaPerson) == 0){
			usuarioUnico=false;
			printf("\nEl nombre de usuario ya esta en uso, por favor, intenta nuevamente.");
		}
		fread(&persona, sizeof(registrados), 1, personas);
	}
	fclose(personas);
}

void almacenarPersona( registrados &nuevaPersona){
	FILE *personas;
	personas = fopen("personas.dat", "a+b");
	registrados personaRegistrar;
	if(personas == NULL){
		perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
		exit(1);
	}	
	strcpy(personaRegistrar.nombreUsuario, nuevaPersona.nombreUsuario);
	strcpy(personaRegistrar.contrasenia, nuevaPersona.contrasenia);
	strcpy(personaRegistrar.rol, nuevaPersona.rol);
	
	printf("\nIngresa el nombre de la persona: ");
	_flushall();
	gets(personaRegistrar.nombre);
	printf("\nIngresa el apellido de la persona: ");
	_flushall();
	gets(personaRegistrar.apellido);
	printf("\nIngresa el sexo de la persona (f para femenino, m para masculino):");
	_flushall();
	gets(personaRegistrar.sexo);
	
	printf("\nIngresa el anio de nacimiento con 4 digitos (por ej. 1996):");
	_flushall();
	scanf("%d", &personaRegistrar.anioNacimiento);
	
	fwrite(&personaRegistrar, sizeof(personaRegistrar), 1, personas);
	fclose(personas);
}

void validarCredencialesUsuario(){
	limpiarPantalla();
	registrados nuevaPersona;
	bool usuarioUnico=false; 
	if(strcmp(datosPersonaLogueada.rol, "admin")==0){
		bool validaMayusculasDigitos, validaContrasenia;
		int largoNombre, largoPass, mayusculas=0, digitosConsecutivos, maxDigitosConsecutivos;
		
	while(usuarioUnico!=true){
		printf("\nIngresa el nombre de usuario a utilizar: ");
		_flushall();
		gets(nuevaPersona.nombreUsuario);
		largoNombre= strlen(nuevaPersona.nombreUsuario);
		int mayusculas = 0;
    	int digitosConsecutivos = 0;
   		 int maxDigitosConsecutivos = 0;
		for(int i=0; nuevaPersona.nombreUsuario[i] != '\0'; i++){
			if(isupper(nuevaPersona.nombreUsuario[i]))
				mayusculas++;
		
			if (isdigit(nuevaPersona.nombreUsuario[i])) {
        	    digitosConsecutivos++;
            	maxDigitosConsecutivos = (maxDigitosConsecutivos > digitosConsecutivos) ? maxDigitosConsecutivos : digitosConsecutivos;
        	} else {
            	digitosConsecutivos = 0; 
        	}	
		}
		if (mayusculas < 2 || maxDigitosConsecutivos > 3) {
       	 		validaMayusculasDigitos=false;
    		}else{
    			validaMayusculasDigitos=true;
			}
	
		if(largoNombre < 6 || largoNombre >10 || nuevaPersona.nombreUsuario[0] == '\0' || !islower(nuevaPersona.nombreUsuario[0]) || validaMayusculasDigitos == false){
			printf("\n::ERROR:: El nombre de usuario no cumple alguna de las siguientes caracteristicas: \n");
			printf("\n1.Tener entre 6 y 10 caracteres.");
			printf("\n2.Comenzar en minuscula.");
			printf("\n3.Tener al menos 2 mayusculas.");
			printf("\n4.Un maximo de 3 digitos consecutivos.");
			printf("\n5.O bien, no se ingreso ningun caracter.");
			printf("\nIntentalo nuevamente\n");	
		}else{
			
			verificarQueSeaUsuarioUnico(nuevaPersona, usuarioUnico);
		}
	}

	mayusculas=0;
	digitosConsecutivos=0;
	maxDigitosConsecutivos=0;
	int minusculas=0;
	bool esAlfanumerico=true, letrasConsecutivas=true;
	
	while(validaContrasenia==false){
		printf("\nIngresa la contrasenia a utilizar: ");
		gets(nuevaPersona.contrasenia);
		
		largoPass= strlen(nuevaPersona.contrasenia);
		
		for(int i=0; nuevaPersona.contrasenia[i] != '\0'; i++){
			if(isupper(nuevaPersona.contrasenia[i])){
				mayusculas++;
			} else if(islower((nuevaPersona.contrasenia[i]))){
				minusculas++;
			}
			
			if (isdigit(nuevaPersona.contrasenia[i])) {
        	    digitosConsecutivos++;
            	maxDigitosConsecutivos = (maxDigitosConsecutivos > digitosConsecutivos) ? maxDigitosConsecutivos : digitosConsecutivos;
        	} else {
            	digitosConsecutivos = 0; 
        	}
        
        	if (mayusculas < 1 || maxDigitosConsecutivos > 3 || minusculas<1) {
       	 		validaMayusculasDigitos=false;
    		}else{
    			validaMayusculasDigitos=true;
			}
			
			if(isalnum(nuevaPersona.contrasenia[i])==0){
				esAlfanumerico=false;
			}
			
			if (isalpha(nuevaPersona.contrasenia[i]) && isalpha(nuevaPersona.contrasenia[i+1])){
            	char c1 = tolower(nuevaPersona.contrasenia[i]);
            	char c2 = tolower(nuevaPersona.contrasenia[i+1]);

           		if (c2 == c1 + 1) {
           	  	  	letrasConsecutivas=false; 
          	  	}
			}
		}
		
		if(largoPass<6 || largoPass>32  || validaMayusculasDigitos==false || esAlfanumerico==false || letrasConsecutivas==false){
				printf("\n::ERROR:: La contrasenia no cumple alguna de las siguientes caracteristicas: \n");
				printf("\n1.Tener entre 6 y 32 caracteres.");
				printf("\n2.Contener al menos una letra mayuscula, una letra minuscula y un numero.");
				printf("\n3.No debe tener caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos.");
				printf("\n4.Un maximo de 3 digitos numericos consecutivos.");
				printf("\n5.O bien, no debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente).");
				printf("\nIntentalo nuevamente\n");
			}else{
				validaContrasenia=true;
			}
	}
			if(validaContrasenia==true && usuarioUnico==true){
			printf("\nIngresa el rol de la persona encargado/a: ");
			_flushall();
			gets(nuevaPersona.rol);
			}
	}else{
		
		while(usuarioUnico!=true){
			srand(time(0));
			int usuarioAleatorio= 10000 + rand()%99999;
			
			sprintf(nuevaPersona.nombreUsuario, "%d", usuarioAleatorio);
			sprintf(nuevaPersona.contrasenia, "%d", usuarioAleatorio);
			
			
			verificarQueSeaUsuarioUnico(nuevaPersona, usuarioUnico);
		}	
	}
	almacenarPersona(nuevaPersona);
}

void listarCompleto(){
	FILE *personas;
	personas = fopen("personas.dat", "rb");
	registrados personaRegistrada;
	if(personas == NULL){
		perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
		exit(1);
	}
	int contadorPersonas=0;

	while(fread(&personaRegistrada, sizeof(registrados), 1, personas)){
		
		if(strcmp(datosPersonaLogueada.rol, "admin")==0){
			contadorPersonas++;
			printf("\n\nDatos de la persona %d:", contadorPersonas);
			printf("\nApellido/s: "); puts(personaRegistrada.apellido);
			printf("Nombre/s: "); puts(personaRegistrada.nombre);
			printf("Edad: %d", anioActual-personaRegistrada.anioNacimiento); 
			printf("\nRol: "); puts(personaRegistrada.rol);
			printf("Activo: %s\n", personaRegistrada.activo ? "si" : "no"); 
			printf("Nombre de usuario/a: "); puts(personaRegistrada.nombreUsuario);
			printf("Contrasenia de usuario/a: "); puts(personaRegistrada.contrasenia);
			printf("Dni: %d", personaRegistrada.dni); 
		}else{
			if(personaRegistrada.activo!=false){
				contadorPersonas++;
				printf("\n\nDatos de la persona %d:", contadorPersonas);
				printf("\nApellido/s: "); puts(personaRegistrada.apellido);
				printf("Nombre/s: "); puts(personaRegistrada.nombre);
				printf("Edad: %d", anioActual-personaRegistrada.anioNacimiento);  
				printf("\nDni: %d", personaRegistrada.dni); 
			}	
		}
	}	
	printf("\nExiste un total de %d personas registradas en la aplicacion.", contadorPersonas);
	fclose(personas);
}

void listarModeradores(){
	FILE *personas;
	personas = fopen("personas.dat", "rb");
	registrados personaRegistrada;
	if(personas == NULL){
		perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
		exit(1);
	}
	int contadorPersonas=0;

	while(fread(&personaRegistrada, sizeof(registrados), 1, personas)){
		if(personaRegistrada.activo!=false){
			
			if(strcmp(personaRegistrada.rol, "admin") ==0 || strcmp(personaRegistrada.rol, "encargado") ==0){

				contadorPersonas++;
				printf("\n\nDatos del/la encargado/a %d:", contadorPersonas);
				printf("\nApellido/s: "); puts(personaRegistrada.apellido);
				printf("Nombre/s: "); puts(personaRegistrada.nombre);
				printf("Edad: %d", anioActual-personaRegistrada.anioNacimiento);
				printf("\nRol: "); puts(personaRegistrada.rol);
				printf("\nNombre de usuario: "); puts(personaRegistrada.nombreUsuario);		
			}	
		}
	}
	printf("\nExiste un total de %d encargados/admin registradas en la aplicacion.", contadorPersonas);
	fclose(personas);	
}

void buscarUsuario(){
	FILE *personas;
	personas = fopen("personas.dat", "rb");
	registrados personaRegistrada;
	if(personas == NULL){
		perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
		exit(1);
	}
	int contadorPersonas=0;
	char personaBuscada[20], auxiliarPersonaBuscada[20];
	printf("\nSi deseas realizar una busqueda mas precisa, utiliza el primer nombre y el segundo nombre.");
	printf("\nIngresa el nombre o nombres a buscar: ");
	_flushall();
	gets(personaBuscada);
	strlwr(personaBuscada);
	printf("\nA continuacion, se listaran todos los usuarios que coincidan con el nombre: ");
	
	while(fread(&personaRegistrada, sizeof(registrados), 1, personas)){
		strcpy(auxiliarPersonaBuscada, personaRegistrada.nombre);
		strlwr(auxiliarPersonaBuscada);
		if(personaRegistrada.activo!=false){
			
			if(strstr(auxiliarPersonaBuscada, personaBuscada)!= NULL){
				contadorPersonas++;
				printf("\n\nDatos de la persona que coinciden con la busqueda %d:", contadorPersonas);
				printf("\nApellido/s: "); puts(personaRegistrada.apellido);
				printf("Nombre/s: "); puts(personaRegistrada.nombre);
				printf("Edad: %d", anioActual-personaRegistrada.anioNacimiento);
				printf("\nRol: "); puts(personaRegistrada.rol);
			}
		}
	}
	printf("\nExiste un total de %d personas registradas que coinciden con la busqueda.", contadorPersonas);
	fclose(personas);	
}

void listarBuscarPersona(){
	limpiarPantalla();
	char opcionLeer;
	do{
		printf("\nElegi una de las siguientes opciones: ");
		printf("\n1. Listar la totalidad de personas registradas.");
		printf("\n2. Listar usuarios y administradores.");
		printf("\n3. Buscar un usuario especifico.");
		printf("\n4. Volver al menu anterior.");
		
		printf("\nIngresa la opcion deseada: ");
		_flushall();
	
		scanf("%c", &opcionLeer);
		
		switch(opcionLeer){
			case '1':
				limpiarPantalla();
				printf("\nA Continuacion, veras nombre, apellido y edad de todos los usuarios registrados.");
				listarCompleto();
				break;
			
			case '2':
				limpiarPantalla();
				printf("\nA Continuacion, veras solo los encargados y administradores registrados.");
				listarModeradores();
				break;
			
			case '3':
				limpiarPantalla();
				printf("\nA Continuacion, podras buscar una persona en especifico.");
				buscarUsuario();
				break;
				
			case '4':
				printf("\nVolviendo al menu anterior.");
				break;
				
			default:
				printf("\nLa opcion ingresada no es valida, intenta nuevamente.");
				break;
		}
		
	}while(opcionLeer!='4');
}

void updatePersona(){
	limpiarPantalla();
	char personaParaActualizar[20], auxiliarParaActualizar[20];
	
	printf("\nA continuacion, ingresa por favor el nombre de la persona a modificar sus datos: ");
	_flushall();
	gets(personaParaActualizar);
	strlwr(personaParaActualizar);
	
	FILE *personas;
	personas = fopen("personas.dat", "r+b");
	registrados personaRegistrada, auxPersonaRegistrada;
	bool usuarioEncontrado=false;
	int confirmacionUpdate;
	
	if(personas == NULL){
		perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
		exit(1);
	}
	printf("\nA continuacion, buscara la primera coincidencia: ");

   	long posicionPunteroPersonas;
   	fread(&personaRegistrada, sizeof(registrados), 1, personas);
	while(!feof(personas) && usuarioEncontrado==false){
		if(personaRegistrada.activo!=false){
			strcpy(auxiliarParaActualizar, personaRegistrada.nombre);
			strlwr(auxiliarParaActualizar);
			
			if(strstr(auxiliarParaActualizar, personaParaActualizar)!= NULL){
				printf("\n\nDatos de la persona encontrada: ");
				printf("\nApellido/s: "); puts(personaRegistrada.apellido);
				printf("Nombre/s: "); puts(personaRegistrada.nombre);
				printf("Edad: %d", anioActual-personaRegistrada.anioNacimiento); 	
				
				if(strcmp(datosPersonaLogueada.rol, "admin")!= NULL){	
					printf("\nNombre de usuario: "); puts(personaRegistrada.nombreUsuario);
					printf("\nContraseña de usuario: "); puts(personaRegistrada.contrasenia);
					printf("\nRol de usuario: "); puts(personaRegistrada.rol);
				}
			
				
				printf("\nIngresa 1 si desea actualizar esta persona, 0 para buscar la siguiente coincidencia: ");
				scanf("%d", &confirmacionUpdate);
				_flushall();
				
				if(confirmacionUpdate==1){
					
					posicionPunteroPersonas = ftell(personas);
					
					printf("\nIngresa el nuevo nombre de la persona: ");
					_flushall();
					gets(personaRegistrada.nombre);		
					
					printf("\nIngresa el nuevo apellido de la persona: ");
					_flushall();
					gets(personaRegistrada.apellido);		
					
					printf("\nIngresa el sexo de la persona (f para femenino, m para masculino): ");
					_flushall();
					gets(personaRegistrada.sexo);
								
					printf("\nIngresa el tipo de colaboracion o si viene a proveerse de alimentos: ");
					_flushall();
					gets(personaRegistrada.tipoDeColaboracion);
								
					printf("\nIngresa todas las vacunas que posee (importante, registrar nuevamente el listado total): ");
					_flushall();
					gets(personaRegistrada.vacunas);
							
					printf("\nIngresa el dni de la persona: ");
					_flushall();
					scanf("%d", &personaRegistrada.dni);				
					
					printf("\nIngresa el anio de nacimiento de la persona en formato 4 digitos (ej. 1996): ");
					_flushall();
					scanf("%d", &personaRegistrada.anioNacimiento);
									
					printf("\nIngresa el peso de la persona, se puede usar comas (ej. 87.5): ");
					_flushall();
					scanf("%f", &personaRegistrada.peso);
									
					printf("\nIngresa la altura de la persona, se puede usar comas (ej. 170.2): ");
					_flushall();
					scanf("%f", &personaRegistrada.altura);
									
					if(strcmp(personaRegistrada.sexo,"f")==0){
						
						printf("\nEsta embarazada? (ingresa 1 si lo esta, 0 si no lo esta): ");
						_flushall();
						scanf("%d", &personaRegistrada.embarazo);
					}
					
					if(strcmp(datosPersonaLogueada.rol, "admin")!= NULL){
						
						printf("\nNombre de usuario: "); 
						_flushall();
						gets(personaRegistrada.nombreUsuario);
						
						printf("\nContraseña de usuario: "); 
						_flushall();
						puts(personaRegistrada.contrasenia);
						
						printf("\nRol de usuario: "); 
						_flushall();
						puts(personaRegistrada.rol);
					}
									
					fseek(personas, posicionPunteroPersonas, SEEK_SET);
					fseek(personas, -sizeof(registrados), SEEK_CUR);
									
					fwrite(&personaRegistrada, sizeof(registrados), 1, personas);
					
					usuarioEncontrado=true;	
				}else{
					fread(&personaRegistrada, sizeof(registrados), 1, personas);
				}
			}else{
				fread(&personaRegistrada, sizeof(registrados), 1, personas);
			}		
		}else{
			fread(&personaRegistrada, sizeof(registrados), 1, personas);
		}
	}
		
	if(usuarioEncontrado==false){
		printf("\nNo se encontro el usuario a modificar, corrobora los datos y volve a intentar");
	}else{
		printf("\nPersona actualizada con exito.");
	}
	
	fclose(personas);
	
}

void borradoLogicoPersona(){
	limpiarPantalla();
	char datoParaEncontrarPersona[11], auxiliarParaActualizar1[11], auxiliarParaActualizar2[11];
	int poseeDatoPersona;
	
	printf("A continuacion, realizaremos el proceso de borrado/activado de una persona. \nSolo podras continuar en caso de ser administrador.");	
	printf("\nPara realizarlo es necesario que, si es un encargado, tenga en claro el nombre de usuario para ubicarlo correctamente.");
	printf("\nEn caso contrario, si no es encargado, debera tener correctamente registrado el dni para ser encontrado");
	
	printf("\n\nTienes el dato requerido continuar?  \n1 si tenes el dato requerido \n2 para volver al menu anterior \nIngresa la opcion que corresponda:");
	scanf("%d", &poseeDatoPersona);
	
	if(poseeDatoPersona==1 and strcmp(datosPersonaLogueada.rol, "admin")==0){
		printf("\nA continuacion, ingresa el dato de nombre de usuario o dni para realizar la busqueda: ");
		_flushall();
		gets(datoParaEncontrarPersona);
		strlwr(datoParaEncontrarPersona);
	
		FILE *personas;
		personas = fopen("personas.dat", "r+b");
		registrados personaRegistrada;
		bool usuarioEncontrado=false, confirmacionUpdate=false;
	
		if(personas == NULL){
			perror("Ocurrio un error con los datos de inicio de sesion. Por favor contacte al administrador");
			exit(1);
		}
		printf("\nA continuacion, te muestro el dato de la persona buscada: ");

   		long posicionPunteroPersonas;
   		
   		fread(&personaRegistrada, sizeof(registrados), 1, personas);
   		
		while(!feof(personas) && usuarioEncontrado==false){
			strcpy(auxiliarParaActualizar1, personaRegistrada.nombreUsuario);
			strlwr(auxiliarParaActualizar1);
			
			sprintf(auxiliarParaActualizar2, "%d", personaRegistrada.dni);
			strlwr(auxiliarParaActualizar2);
			
			if(strstr(auxiliarParaActualizar1, datoParaEncontrarPersona)!= NULL || strstr(auxiliarParaActualizar2, datoParaEncontrarPersona)!= NULL ){
				printf("\n\nDatos de la persona encontrada: ");
				printf("\nApellido/s: "); puts(personaRegistrada.apellido);
				printf("Nombre/s: "); puts(personaRegistrada.nombre);
				printf("Edad: %d", anioActual-personaRegistrada.anioNacimiento); 
					
				printf("Activo: %s\n", personaRegistrada.activo ? "si" : "no");
				
				printf("\nIngresa 1 si desea %s esta persona, 0 para cancelar: ", personaRegistrada.activo ? "borrar" : "activar");
				scanf("%d", &confirmacionUpdate);
				if(confirmacionUpdate==1){
				
					posicionPunteroPersonas = ftell(personas);
				
					personaRegistrada.activo= !personaRegistrada.activo;
						
					fseek(personas, posicionPunteroPersonas, SEEK_SET);
					fseek(personas, -sizeof(registrados), SEEK_CUR);
								
					fwrite(&personaRegistrada, sizeof(registrados), 1, personas);
				
					usuarioEncontrado=true;	
				}else{
					return;
				}
			}else{
				fread(&personaRegistrada, sizeof(registrados), 1, personas);
			}		
		}
		
		if(usuarioEncontrado==false){
			printf("\nNo se encontro el usuario a borrar, corrobora los datos y volve a intentar");
		}else{
			printf("\nPersona borrada con exito.");
		}
	
		fclose(personas);
		
	}else{
		printf("\nLa opcion ingresada no es correcta o no tiene los permisos necesarios para continuar. \nVolviendo al menu anterior...");
	}
	
}

void primerIngreso(){
	registrados nuevaPersona;
	strcpy(nuevaPersona.nombreUsuario, "admin");
	strcpy(nuevaPersona.contrasenia, "admin");
	strcpy(nuevaPersona.rol, "admin");

	almacenarPersona(nuevaPersona);
}

void moduloPersonas(persona personaLogueada){
	
	printf("\nGestion de personas\n");
	char opcionGestionPersonas;
	
	do{
		printf("\nA continuacion, elige la opcion de lo que deseas hacer: \n");
		
		printf("\n1. Crear nueva persona.");
		printf("\n2. Ver listado de personas o buscar una en particular");
		printf("\n3. Actualizar datos de una persona.");
		printf("\n4. Borrar una persona.");
		
		printf("\n5. Volver al menu anterior.\n");
		
		printf("\nIngresa la opcion correspondiente: ");
		_flushall();
		scanf("%c", &opcionGestionPersonas);
		
		switch(opcionGestionPersonas){
			case '1':
				validarCredencialesUsuario();
				break;
					
			case '2':
				listarBuscarPersona();
				break;
			
			case '3':
				updatePersona();
				break;
			
			case '4':
				borradoLogicoPersona();	
				break;
			
			case '5':
				printf("\nVolviendo al menu anterior.");		
				break;

			default:
				printf("\nLa opcion ingresada no es valida.");
				printf("\nPor favor, intenta nuevamente.");
				break;	
		}
		
	}while(opcionGestionPersonas!='5');
	
}