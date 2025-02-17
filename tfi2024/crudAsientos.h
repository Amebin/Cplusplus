struct registroAsientos{
	char nombreMes[11];
	char personaAsiento[31][60][9];
	char dia[31][30];
};
void crearAsientos(){
	limpiarPantalla();
	FILE *asientos;
	
	if(fopen("asientos.dat", "ab") ==NULL){
		asientos = fopen("asientos.dat", "wb");
	}else{
		asientos = fopen("asientos.dat", "ab");
	}
	
	if(asientos == NULL){
		perror("\n\nOcurrio un error al intentar validar id unico de producto. Contacta al administrador.");
		exit(1);
	}
	int cantidadDias, contador=0;
	registroAsientos asignarMes;
	printf("\nA continuacion, crearemos un nuevo mes.");
	printf("\nPor favor, ingresa el nombre del mes a crear: (enero, febrero, etc..)");
	_flushall();
	gets(asignarMes.nombreMes);
	
	printf("\nA continuacion, te pedire la fecha de cada dia del mes en formato 12/10/25 y el nombre del dia como lunes, martes, domingo, etc.");
	printf("\nIngresa un numero entre el 1 y el 31 para continuar. Esto representara la cantidad de dias que ofreceras servicios. \nSi ingresas 0 se cancelara la creacion y deberas volver a ingresar al modulo.");
	scanf("%d", &cantidadDias);
	
	if(cantidadDias!=0){
		for(int contador=0; contador<cantidadDias; contador++){
			printf("\nIngresa el nombre del dia %d, siguiendo el siguiente formato: 'Lunes 19/03/2025'\n", contador+1);
			_flushall();
			gets(asignarMes.dia[contador]);
		}
	}
	
	fwrite(&asignarMes, sizeof(registroAsientos), 1, asientos);
	fclose(asientos);
}

void verListado(){
	limpiarPantalla();
	FILE *asientos;
	
	asientos = fopen("asientos.dat", "rb");
	
	if(asientos == NULL){
		perror("\n\nOcurrio un error al intentar leer los datos de asientos. Contacta al administrador.");
		exit(1);
	}
	
	registroAsientos listarMes;
	char mesListar[11], auxMesRegistrado[11];
	bool encuentraMes=false;
	int diaMostrar;
	
	printf("\nIngresa el mes del que queres ver el listado: ");
	_flushall();
	gets(mesListar);
	strlwr(mesListar);
	
	fread(&listarMes, sizeof(registroAsientos), 1, asientos);
	do{
		strcpy(auxMesRegistrado, listarMes.nombreMes);
		strlwr(auxMesRegistrado);
		
		if(strcmp(auxMesRegistrado, mesListar)==0){
			encuentraMes=true;
			printf("\nA continuacion mostraremos los dias del mes "); puts(listarMes.nombreMes);
			for(int i=0; i<31; i++){
				if(strlen(listarMes.dia[i])>7){
					printf("\nDia "); puts(listarMes.dia[i]);
					
					printf("\nMostrar datos de este dia? Ingresa 1 para mostrar los datos, 0 para ver el siguiente dia: ");
					scanf("%d", &diaMostrar);
					
					if(diaMostrar==1){
						for(int j=0; j<60; j++){
							
							if(strlen(listarMes.personaAsiento[i][j])>6){
								printf("Persona en el asiento %d ", j+1); puts(listarMes.personaAsiento[i][j]);
							}
						}
					}
				}
			}
		}
		
		fread(&listarMes, sizeof(registroAsientos), 1, asientos);
	}while(!feof(asientos) && encuentraMes==false);
	
	if(encuentraMes==false){
		printf("\nEl mes que ingresaste no posee datos asignados.\n");
	}
	
	fclose(asientos);
}

void agregarPersonaAsiento(){
	limpiarPantalla();
	FILE *asientos;
	
	asientos = fopen("asientos.dat", "r+b");
	
	if(asientos == NULL){
		perror("\n\nOcurrio un error al intentar leer los datos de asientos. Contacta al administrador.");
		exit(1);
	}
	
	registroAsientos listarMes;
	char mesListar[11], auxMesRegistrado[11];
	bool encuentraMes=false;
	int asignarPersona, asignarDia;
	long posicionPunteroAsientos;
	
	printf("\nIngresa el mes del que queres asignar asientos: ");
	_flushall();
	gets(mesListar);
	strlwr(mesListar);
	
	
	fread(&listarMes, sizeof(registroAsientos), 1, asientos);
	do{
		strcpy(auxMesRegistrado, listarMes.nombreMes);
		strlwr(auxMesRegistrado);
		
		if(strcmp(auxMesRegistrado, mesListar)==0){
			encuentraMes=true;
			posicionPunteroAsientos= ftell(asientos);
			
			printf("\nA continuacion mostraremos los dias sin asignar del mes "); puts(listarMes.nombreMes);
			for(int i=0; i<31; i++){
				if(strlen(listarMes.dia[i])>7){
					printf("\nDia a asignar "); puts(listarMes.dia[i]);
					
					printf("\nDesea asignar personas a este dia? 1 para si, 0 para no.");
					scanf("%d", &asignarDia);
					if(asignarDia == 1){
						
						
						for(int j=0; j<60; j++){
								if(strlen(listarMes.personaAsiento[i][j])<7){
									printf("Ingresa el dni de la persona a asignar en el asiento %d", j+1); 
									_flushall();
									gets(listarMes.personaAsiento[i][j]);
									_flushall();
									printf("\nDeseas asignar otro asiento a otra persona? 1 para si, 0 para no:");
									scanf("%d", &asignarPersona);
									if(asignarPersona==0){
										j=60;
									}						
								}
						}						
					}
				}
			}	
			
			
			
			fseek(asientos, posicionPunteroAsientos, SEEK_SET);
			fseek(asientos, -sizeof(listarMes), SEEK_CUR);
			fwrite(&listarMes, sizeof(listarMes), 1, asientos);
		}
		
		fread(&listarMes, sizeof(registroAsientos), 1, asientos);
	}while(!feof(asientos) && encuentraMes==false);
	
	if(encuentraMes==false){
		printf("\nNo se encontro el mes requerido.\n");
	}
	
	fclose(asientos);	
}

void desagregarPersonaAsiento(){
	limpiarPantalla();
	FILE *asientos;
	
	asientos = fopen("asientos.dat", "r+b");
	
	if(asientos == NULL){
		perror("\n\nOcurrio un error al intentar leer los datos de asientos. Contacta al administrador.");
		exit(1);
	}
	
	registroAsientos listarMes;
	char mesListar[11], auxMesRegistrado[11];
	bool encuentraMes=false;
	int asignarPersona, asignarDia, borrarDni;
	long posicionPunteroAsientos;
	
	printf("\nIngresa el mes del que queres asignar asientos: ");
	_flushall();
	gets(mesListar);
	strlwr(mesListar);
	
	
	fread(&listarMes, sizeof(registroAsientos), 1, asientos);
	do{
		strcpy(auxMesRegistrado, listarMes.nombreMes);
		strlwr(auxMesRegistrado);
		
		if(strcmp(auxMesRegistrado, mesListar)==0){
			encuentraMes=true;
			posicionPunteroAsientos= ftell(asientos);
			
			printf("\nA continuacion mostraremos los dias del mes "); puts(listarMes.nombreMes);
			for(int i=0; i<31; i++){
				if(strlen(listarMes.dia[i])>7){
					printf("\nDia a desasignar "); puts(listarMes.dia[i]);
					
					printf("\nDesea desasignar personas a este dia? 1 para si, 0 para no.");
					scanf("%d", &asignarDia);
					if(asignarDia == 1){
						
						
						for(int j=0; j<60; j++){
								if(strlen(listarMes.personaAsiento[i][j])>0){
									printf("\nDni de la persona asignada: "); puts(listarMes.personaAsiento[i][j]);
									
									printf("\nIngresa 1 para borrarla del asiento, 0 para ver la siguiente persona asignada: ");
									scanf("%d", &borrarDni);
									
									if(borrarDni==1){
										strcpy(listarMes.personaAsiento[i][j], "");
									}
									
									printf("\nDeseas desasignar otro asiento a otra persona? 1 para si, 0 para no:");
									scanf("%d", &asignarPersona);
									if(asignarPersona==0){
										j=60;
									}						
								}
						}						
					}
				}
			}	
			
			
			
			fseek(asientos, posicionPunteroAsientos, SEEK_SET);
			fseek(asientos, -sizeof(listarMes), SEEK_CUR);
			fwrite(&listarMes, sizeof(listarMes), 1, asientos);
		}
		
		fread(&listarMes, sizeof(registroAsientos), 1, asientos);
	}while(!feof(asientos) && encuentraMes==false);
	
	if(encuentraMes==false){
		printf("\nNo se encontro el mes requerido.\n");
	}
	
	fclose(asientos);	
}

void moduloAsientos(){
		printf("\nModulo de Gestion Asientos disponibles.");
	
	char opcionInventario;
	
	do{
		printf("\nA continuacion, elige la opcion de lo que deseas hacer: \n");
		
		printf("\n1. Crear una nueva cantidad de asientos disponibles.");
		printf("\n2. Ver listado de asientos por dia y quienes lo ocupan.");
		printf("\n3. Asignar una persona a un asiento.");
		printf("\n4. Desasignar un asiento asignado por dia.");
		
		printf("\n5. Volver al menu anterior.\n");
		
		printf("\nIngresa la opcion correspondiente: ");
		_flushall();
		scanf("%c", &opcionInventario);
		
		switch(opcionInventario){
			case '1':
				crearAsientos();
				break;
					
			case '2':
				verListado();
				break;
			
			case '3':
				agregarPersonaAsiento();
				break;
			
			case '4':
				desagregarPersonaAsiento();
				break;
			
			case '5':
				printf("\nVolviendo al menu anterior.");		
				break;

			default:
				printf("\nLa opcion ingresada no es valida.");
				printf("\nPor favor, intenta nuevamente.");
				break;	
		}
		
	}while(opcionInventario!='5');
	
}