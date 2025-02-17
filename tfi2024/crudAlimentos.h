
struct inventario{
	int id=NULL;
	char nombre[20];
	float pesoKg=0;
	bool banderaKg=false;
	float litros=0;	
	bool banderaLitros=false;
	bool activo=true;
};

void verificarIdUnico( inventario nuevoProducto, bool &productoUnico){
	FILE *productos;	
	
	if(fopen("productos.dat", "rb") ==NULL){
		productos = fopen("productos.dat", "wb");
		fclose(productos);
		productos = fopen("productos.dat", "rb");
	}else{
		productos = fopen("productos.dat", "rb");
	}
	
	if(productos == NULL){
		perror("\n\nOcurrio un error al intentar validar id unico de producto. Contacta al administrador.");
		exit(1);
	}
	
	inventario productoRegistrado;
	productoUnico=true;
	
	fread(&productoRegistrado, sizeof(inventario), 1, productos);
	do{
		
		if(productoRegistrado.id == nuevoProducto.id){
			
			productoUnico=false;
			printf("\nEl codigo del producto ya se encuentra en uso, por favor, intenta nuevamente.");
		}
		
		fread(&productoRegistrado, sizeof(inventario), 1, productos);
	}while(!feof(productos) && productoUnico==true);
	
	fclose(productos);
}

void almacenarProducto(inventario &nuevoProducto){
	FILE *productos;
	productos = fopen("productos.dat", "ab");
	if(productos == NULL){
		perror("\n\nOcurrio un error al intentar validar id unico de producto. Contacta al administrador.");
		exit(1);
	}
	int medicionProducto;
	
	printf("\nIngresa el nombre del producto: ");
	_flushall();
	gets(nuevoProducto.nombre);
	
	printf("\nIngresa 1 si se pesa en kg o 0 si se almacenaran los litros: ");
	scanf("%d", &medicionProducto);
	
	if(medicionProducto==1){
		printf("\nIngresa el peso sumados en kg de los productos en stock: ");
		scanf("%f", &nuevoProducto.pesoKg);
		nuevoProducto.banderaKg=true;
	}else{
		printf("\nIngresa litros sumados de los productos en stock: ");
		scanf("%f", &nuevoProducto.litros);
		nuevoProducto.banderaLitros=true;
	}
	
	fwrite(&nuevoProducto, sizeof(inventario), 1, productos);
	fclose(productos);
}

void crearProducto(){
	limpiarPantalla();
	inventario nuevoProducto;
	
	bool productoUnico=false;
	while(productoUnico!=true){
		printf("\nIngresa el codigo/id del alimento/producto: ");
		scanf("%d", &nuevoProducto.id);
		
		verificarIdUnico(nuevoProducto, productoUnico);
	}
	
	almacenarProducto(nuevoProducto);
}

void listarProductos(){
	FILE *productos;
	productos = fopen("productos.dat", "rb");
	if(productos == NULL){
		perror("\n\nOcurrio un error al intentar validar id unico de producto. Contacta al administrador.");
		exit(1);
	}
	inventario productoInventario;
	int contadorProductos=0;
	fread(&productoInventario, sizeof(inventario), 1, productos);
	while(!feof(productos)){
		if(productoInventario.activo==true){			
			printf("\n\nCodigo del producto: %d", productoInventario.id);
			printf("\nNombre del producto: ");
			puts(productoInventario.nombre);
			
			if(productoInventario.banderaLitros==true){
				printf("Los litros en stock son: %.2f", productoInventario.litros);
			}else if(productoInventario.banderaKg==true){
				printf("Los kg en stock son: %.2f", productoInventario.pesoKg);
			}else{
				printf("El producto no posee stock. Es Necesario realizar la compra del mismo.");
			}
			
			contadorProductos++;
			fread(&productoInventario, sizeof(inventario), 1, productos);
		}else{
			fread(&productoInventario, sizeof(inventario), 1, productos);
		}
		
	}
	
	printf("\n\nExiste un total de %d productos registrados en el inventario.",contadorProductos);
	fclose(productos);
}

void listarSinStock(){
	FILE *productos;
	productos = fopen("productos.dat", "rb");
	if(productos == NULL){
		perror("\n\nOcurrio un error al intentar controlar la cantidad de stock. Contacta al administrador.");
		exit(1);
	}
	inventario productoInventario;
	int contadorSinStock=0;
	
	while(fread(&productoInventario, sizeof(inventario), 1, productos)){
		if(productoInventario.activo==true){	
			if(productoInventario.pesoKg<5 && productoInventario.banderaKg==true || productoInventario.litros<5 && productoInventario.banderaLitros==true){
				contadorSinStock++;
				
				printf("\n\nCodigo del producto: %d", productoInventario.id);
						
				printf("\nNombre del producto: ");
				puts(productoInventario.nombre);
				
				if(productoInventario.banderaLitros==true){
					printf("Los litros en stock son: %.2f", productoInventario.litros);
				}else if(productoInventario.banderaKg==true){
					printf("Los kg en stock son: %.2f", productoInventario.pesoKg);
				}else{
					printf("El producto no posee stock. Es Necesario realizar la compra del mismo.");
				}
			}
		}	
	}
	
	printf("\n\nExiste un total de %d productos que requieren comprar en el inventario.", contadorSinStock);
	fclose(productos);	
}

void buscarProducto(){
	FILE *productos;
	productos = fopen("productos.dat", "rb");
	if(productos == NULL){
		perror("\n\nOcurrio un error al intentar validar id unico de producto. Contacta al administrador.");
		exit(1);
	}
	inventario productoInventario;
	int codigoBuscado;
	bool banderaEncuentraProducto=false;
	printf("\nA continuacion, deberas buscar por codigo el producto. \nPor favor, ingresa el codigo del producto a buscar: ");
	scanf("%d", &codigoBuscado);
	
	fread(&productoInventario, sizeof(inventario), 1, productos);
	while(!feof(productos) && banderaEncuentraProducto==false){
		if(productoInventario.activo ==true){
			if(codigoBuscado==productoInventario.id){
				printf("\nCodigo del producto: %d", productoInventario.id);
				printf("\nNombre del producto: ");
				puts(productoInventario.nombre);
				
				if(productoInventario.banderaLitros==true){
					printf("Los litros en stock son: %.2f\n", productoInventario.litros);
				}else if(productoInventario.banderaKg==true){
					printf("Los kg en stock son: %.2f\n", productoInventario.pesoKg);
				}else{
					printf("El producto no posee stock. Es Necesario realizar la compra del mismo.\n");
				}
				
				banderaEncuentraProducto=true;
			}		
		}
		fread(&productoInventario, sizeof(inventario), 1, productos);
	}
	fclose(productos);
}

void listarBuscarProducto(){
	limpiarPantalla();
	char opcionLeer;
	do{
		printf("\nElegi una de las siguientes opciones: ");
		printf("\n1. Listar la totalidad de productos.");
		printf("\n2. Listar productos sin stock o con stock menor a 5 kg/litros.");
		printf("\n3. Buscar un producto especifico.");
		printf("\n4. Volver al menu anterior.");
		
		printf("\nIngresa la opcion deseada: ");
		_flushall();
	
		scanf("%c", &opcionLeer);
		
		switch(opcionLeer){
			case '1':
				limpiarPantalla();
				printf("\nA Continuacion, veras codigo, nombre y cantidad de todos los productos registrados.");
				listarProductos();
				break;
			
			case '2':
				limpiarPantalla();
				printf("\nA Continuacion, veras solo los encargados y administradores registrados.");
				listarSinStock();
				break;
			
			case '3':
				limpiarPantalla();
				printf("\nA Continuacion, podras buscar una persona en especifico.");
				buscarProducto();
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

void updateProducto(){
	FILE *productos;
	productos = fopen("productos.dat", "r+b");
	if(productos == NULL){
		perror("\n\nOcurrio un error al intentar validar id unico de producto. Contacta al administrador.");
		exit(1);
	}
	inventario productoInventario;
	int codigoBuscado, confirmaUpdate;
	bool banderaEncuentraProducto=false;
	printf("\nDeberas buscar por codigo el producto. \nPor favor, ingresa el codigo del producto a buscar: ");
	scanf("%d", &codigoBuscado);
	
	long posicionPunteroProductos;
	fread(&productoInventario, sizeof(inventario), 1, productos);
	while(!feof(productos) && banderaEncuentraProducto==false){
		if(codigoBuscado==productoInventario.id && productoInventario.activo==true){
			
			printf("\nCodigo del producto: %d", productoInventario.id);
			printf("\nNombre del producto: ");
			puts(productoInventario.nombre);
			
			if(productoInventario.banderaLitros==true){
				printf("Los litros en stock son: %.2f\n", productoInventario.litros);
			}else if(productoInventario.banderaKg==true){
				printf("Los kg en stock son: %.2f\n", productoInventario.pesoKg);
			}else{
				printf("El producto no posee stock. Es Necesario realizar la compra del mismo.\n");
			}
			
			banderaEncuentraProducto=true;
			
			printf("\nAtencion, solo prodra actualizar nombre y cantidad de stock, no el codigo del producto. Tampoco podra modificar si se medira los kg o litros\nIngresa 1 si desea actualizar este producto, 0 para cancelar.");
			scanf("%d", &confirmaUpdate);
			
			if(confirmaUpdate==1){
				posicionPunteroProductos= ftell(productos);
				printf("\nIngresa el nuevo nombre del producto: ");
				_flushall();
				gets(productoInventario.nombre);
				
				if(productoInventario.banderaLitros==true){
					printf("Ingresa la nueva cantidad en Litros: ");
					scanf("%f", &productoInventario.litros);
				}else if(productoInventario.banderaKg==true){
					printf("Ingresa la nueva cantidad en Kg: ");
					scanf("%f", &productoInventario.pesoKg);
				}else{
					printf("El producto no posee stock. Es Necesario realizar la compra del mismo.\n");
				}
				
				fseek(productos, posicionPunteroProductos, SEEK_SET);
				fseek(productos, -sizeof(inventario), SEEK_CUR);
				
				fwrite(&productoInventario, sizeof(inventario), 1, productos);
				
			}else{
				printf("\nElegiste el 0, no se actualizara este producto.");
			}			
			
		}		
		fread(&productoInventario, sizeof(inventario), 1, productos);
	}
	
	if(banderaEncuentraProducto==false){
		printf("\nNo se encontro el producto, por favor, verifica el codigo en la opcion de listar productos e intenta mas tarde");
	}
	fclose(productos);
}

void borradoLogicoProducto(){
	FILE *productos;
	productos = fopen("productos.dat", "r+b");
	if(productos == NULL){
		perror("\n\nOcurrio un error al intentar validar id unico de producto. Contacta al administrador.");
		exit(1);
	}
	inventario productoInventario;
	int codigoBuscado, confirmaUpdate;
	bool banderaEncuentraProducto=false;
	printf("\nDeberas buscar por codigo el producto. \nPor favor, ingresa el codigo del producto a buscar: ");
	scanf("%d", &codigoBuscado);
	
	long posicionPunteroProductos;
	fread(&productoInventario, sizeof(inventario), 1, productos);
	while(!feof(productos) && banderaEncuentraProducto==false){
		if(codigoBuscado==productoInventario.id){
			
			printf("\nCodigo del producto: %d", productoInventario.id);
			printf("\nNombre del producto: ");
			puts(productoInventario.nombre);
			
			if(productoInventario.banderaLitros==true){
				printf("Los litros en stock son: %.2f\n", productoInventario.litros);
			}else if(productoInventario.banderaKg==true){
				printf("Los kg en stock son: %.2f\n", productoInventario.pesoKg);
			}else{
				printf("El producto no posee stock. Es Necesario realizar la compra del mismo.\n");
			}
			printf("Activo: %s\n", productoInventario.activo ? "si" : "no");
			
			banderaEncuentraProducto=true;
			
			printf("\nIngresa 1 si desea %s este producto, 0 para cancelar: ", productoInventario.activo ? "borrar" : "activar");
			scanf("%d", &confirmaUpdate);
			
			if(confirmaUpdate==1){
				posicionPunteroProductos= ftell(productos);
				
				productoInventario.activo= !productoInventario.activo;
				
				fseek(productos, posicionPunteroProductos, SEEK_SET);
				fseek(productos, -sizeof(inventario), SEEK_CUR);
				
				fwrite(&productoInventario, sizeof(inventario), 1, productos);
				
			}else{
				printf("\nElegiste 0, no se va a %s este producto", productoInventario.activo ? "borrar" : "activar");
			}			
			
		}		
		fread(&productoInventario, sizeof(inventario), 1, productos);
	}
	
	if(banderaEncuentraProducto==false){
		printf("\nNo se encontro el producto, por favor, verifica el codigo en la opcion de listar productos e intenta mas tarde");
	}
	fclose(productos);
}

void moduloAlimentos(){
	printf("\nModulo de Gestion de Stock de alimentos");
	
	char opcionInventario;
	
	do{
		printf("\nA continuacion, elige la opcion de lo que deseas hacer: \n");
		
		printf("\n1. Crear nuevo producto.");
		printf("\n2. Ver listado inventario o buscar una en particular");
		printf("\n3. Actualizar inventario.");
		printf("\n4. Borrar un producto.");
		
		printf("\n5. Volver al menu anterior.\n");
		
		printf("\nIngresa la opcion correspondiente: ");
		_flushall();
		scanf("%c", &opcionInventario);
		
		switch(opcionInventario){
			case '1':
				crearProducto();
				break;
					
			case '2':
				listarBuscarProducto();
				break;
			
			case '3':
				updateProducto();
				break;
			
			case '4':
				borradoLogicoProducto();	
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

