#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <cstdlib>

struct persona{
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

void limpiarPantalla(){
    system("cls");  
}


void solicitarUsuarioYContrasenia(persona &datosInicioSesion){	
	printf("\nA continuacion, ingresa tu usuario: "); 
	_flushall();
	gets(datosInicioSesion.nombreUsuario);
	printf("\nA continuacion, ingresa tu contrasenia: "); 
	_flushall();
	gets(datosInicioSesion.contrasenia);
}

void almacenarDatosLogin(persona datosInicioSesion){
	FILE *datosLogin;
	datosLogin = fopen("datosLogin.dat", "wb");
	if(datosLogin == NULL){
		perror("Ocurrio un error al almacenar los datos de inicio de sesion. Por favor contacte al administrador");
		exit(1);
	}
	
	fwrite(&datosInicioSesion, sizeof(persona), 1, datosLogin);
	fclose(datosLogin);
	
}

void buscarUsuarioExistente(persona datosInicioSesion, int &intentosInicioSesion, bool &validaInicioSesion){
	FILE *personas;
	

	personas =fopen("personas.dat", "rb");
	if(personas == NULL){
		
		perror("Ocurrio un error al recuperar los datos de inicio de sesion. Por favor, contacte al administrador");
		exit(1);
	}
	bool encuentraUsuario=false;
	persona personaRegistrada;
	char auxPersonaRegister[11], auxLoguerPersona[11], auxContraRegister[33], auxContraLoguer[33];
	strcpy(auxLoguerPersona, datosInicioSesion.nombreUsuario);
	strlwr(auxLoguerPersona);
	strcpy(auxContraLoguer, datosInicioSesion.contrasenia);
	strlwr(auxContraLoguer);
	
	
	fread(&personaRegistrada, sizeof(persona), 1, personas);
	while(!feof(personas) && encuentraUsuario==false){	
		strcpy(auxPersonaRegister, personaRegistrada.nombreUsuario);
		strlwr(auxPersonaRegister);
		strcpy(auxContraRegister, personaRegistrada.contrasenia);
		strlwr(auxContraRegister);
	
		if((strcmp(auxPersonaRegister,auxLoguerPersona)) == 0){	
			encuentraUsuario=true;	
			if((strcmp(auxContraRegister,auxContraLoguer)) == 0){
				
				validaInicioSesion=true;
				
			
				strcpy(datosInicioSesion.apellido, personaRegistrada.apellido);
				strcpy(datosInicioSesion.nombre, personaRegistrada.nombre);
				strcpy(datosInicioSesion.nombreUsuario, personaRegistrada.nombreUsuario);
				strcpy(datosInicioSesion.rol, personaRegistrada.rol);
				strcpy(datosInicioSesion.sexo, personaRegistrada.sexo);
				
				almacenarDatosLogin(datosInicioSesion);
				
				
			}else{
				printf("\nEl usuario o la contrasenia son incorrectos, por favor intenta nuevamente\n");
				intentosInicioSesion++;
			}
		}	
		
		fread(&personaRegistrada, sizeof(persona), 1, personas);	
	};
	if(encuentraUsuario==false){
		printf("\nEl usuario o la contrasenia son incorrectos, por favor intenta nuevamente\n");
		intentosInicioSesion++;
	}
	fclose(personas);
}

void menuInicioSesion(bool &validaInicioSesion){
	char opcionMenuBienvenida;
	int intentosInicioSesion=0;
	bool auxValidacion=false;
	do{
		
		printf("\n\nQue deseas hacer?: ");
		
		printf("\n1. Iniciar sesion.");
		printf("\n2. Salir.");
		
		printf("\nIngresa la opcion correspondiente: ");
		_flushall();
		scanf("%c", &opcionMenuBienvenida);
		
		
		persona datosInicioSesion;
		switch(opcionMenuBienvenida){
			case '1':
				
				
				while(validaInicioSesion!=true){
					solicitarUsuarioYContrasenia(datosInicioSesion);
					
					buscarUsuarioExistente(datosInicioSesion, intentosInicioSesion,validaInicioSesion);
					
					if(intentosInicioSesion>3){
						limpiarPantalla();
						printf("\nSe supero el limite de intentos consecutivos, por favor, volve mas tarde");
						intentosInicioSesion=0;
						break;
					}						
				}
				
				break;
			
			case '2':
				printf("\nSaliendo del sistema...");
				break;
				
			default:
				printf("\nLa opcion ingresada no es valida.");
				printf("\nPor favor, intenta nuevamente.");
				break;			
		}
		
		
	}while(validaInicioSesion!=true && opcionMenuBienvenida!='2');
	
}


