#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hotels{
	int code;
	char name[50];
	int place[10][7];
};

int verificar(int codi, int pis, int hab);
void ocupadas();

main(){
	FILE *hotel;
	hotels h;
	int cod;
	if(fopen("hotel.dat", "rb") == NULL){
		hotel = fopen("hotel.dat", "w+b");
		
		if(hotel==NULL){
			perror("\nOcurrio un error inesperado, volve a intentarlo mas tarde");
			exit(1);
		}
		
		printf("\nIngresa el codigo del hotel: ");
		scanf("%d", &cod);
		while(cod!=0){
			h.code= cod;
			printf("\n\nIngresa el nombre del hotel: ");
			_flushall();
			gets(h.name);
			for(int i=0; i<10; i++){
				for(int j=0; j<7; j++){
					printf("\nIngresa las personas alojadas en la habitacion %d piso %d", j+1,i+1);
					scanf("%d", &h.place[i][j]);
				}
			}
			
			fwrite(&h, sizeof(h), 1, hotel);
			
			printf("\nIngresa el codigo del hotel: ");
			scanf("%d", &cod);
		}
		
		rewind(hotel);
		
		fread(&h, sizeof(h), 1, hotel);
		while(!feof(hotel)){
			printf("\n\nNombre del hotel: "); puts(h.name);
			printf("Codigo de hotel: %d", h.code);
			
			for(int i=0; i<10; i++){
				for(int j=0; j<7; j++){
					printf("\nPersonas alojadas en la habitacion %d piso %d: %d", j+1,i+1, h.place[i][j]);
					
				}
			}
			
			fread(&h, sizeof(h), 1, hotel);
		}
		
		fclose(hotel);
	}
	
	int c, p, ho;
	printf("\n\nDatos para verificar disponibilidad: ");
	printf("\nIngresa el codigo de hotel: ");
	scanf("%d", &c);
	printf("\nIngresa el piso: ");
	scanf("%d", &p);
	printf("\nIngresa la habitacion: ");
	scanf("%d", &ho);
	
	int dispo = verificar(c, p, ho);
	
	if(dispo == 0){
		printf("\n\nLa habitacion no esta disponible");
	}else{
		printf("\n\nLa habitacion esta disponible");
	}
	
	ocupadas();
	
	
}


verificar(int codi, int pis, int hab){
	FILE *hotel;
	hotel = fopen("hotel.dat", "r+b");
	hotels h;
	int dispo=0;
	
	if(hotel==NULL){
		perror("\nOcurrio un error inesperado.");
		exit(1);
	}
	
	fread(&h, sizeof(h), 1, hotel);
	
	while(!feof(hotel)){
			if(h.code==codi){
				for(int i=0; i<10; i++){
					if(i+1 == pis){
						for(int j=0; j<7; j++){
							if(j+1 == hab){
								if(h.place[i][j]==0){
									
									dispo=1;
								}else{
								
									dispo=0;
								}
							}
						
						}
					}
				}
			}
			
			fread(&h, sizeof(h), 1, hotel);
	}
	
	rewind(hotel);
		
		fread(&h, sizeof(h), 1, hotel);
		while(!feof(hotel)){
			printf("\n\nNombre del hotel: "); puts(h.name);
			printf("Codigo de hotel: %d", h.code);
			
			for(int i=0; i<10; i++){
				for(int j=0; j<7; j++){
					printf("\nPersonas alojadas en la habitacion %d piso %d: %d", j+1,i+1, h.place[i][j]);
					
				}
			}
			
			fread(&h, sizeof(h), 1, hotel);
		}
	
	fclose(hotel);
	
	return dispo;
}

void ocupadas(){
	FILE *hotel;
	hotel = fopen("hotel.dat", "r+b");
	hotels h;
	int ocupa=0;
	
	if(hotel==NULL){
		perror("\nOcurrio un error inesperado.");
		exit(1);
	}
	
	fread(&h, sizeof(h), 1, hotel);
	
	while(!feof(hotel)){
		for(int i=0; i<10; i++){
			for(int j=0; j<7; j++){
				if(h.place[i][j]!=0){	
					ocupa+=1;
				}					
			}
		}
		fread(&h, sizeof(h), 1, hotel);
	}
	
	printf("\n\nLa cantidad de plazas ocupadas son: %d", ocupa);
	
	fclose(hotel);
}