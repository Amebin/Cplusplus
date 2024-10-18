#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
	srand(time(0));
	int M=0, N=0, P=0;
	
	printf("Ingrese el orden M de la matriz: ");
	scanf("%d", &M);
	
	printf("Ingrese el orden N de la matriz: ");
	scanf("%d", &N);
	
	printf("Ingrese el orden P de la matriz: ");
	scanf("%d", &P);
	
	int Multi[M][N][P];
	
	for(int z=0; z<P; z++){
		printf("\nplano");
		
		for(int i=0; i<M; i++){
			printf("\nfila");
			
			for(int j=0; j<N; j++){
				Multi[i][j][z]= 1 + rand()%10;
				printf("\tcolumna %d", Multi[i][j][z]);
			}
		}
	}
	
	//produccion total de la fabrica
	int Produccion=0;
	for(int z=0; z<P; z++){
			
		for(int i=0; i<M; i++){
					
			for(int j=0; j<N; j++){
				Produccion+= Multi[i][j][z];
			}
		}
	}
	printf("\nLa produccion total fue de: %d", Produccion);
	
	
	//Prendas de un modelo M en la sucursal K (ingresada por teclado) 
	int Sucursal=0, Models=0, Cantidad=0;
	printf("\nIndica de cual sucusar queres conocer la produccion: ");
	scanf("%d", &Sucursal);
	printf("\nIndica el modelo del cual queres conocer la produccion: ");
	scanf("%d", &Models);
	for(int z=0; z<P; z++){
		
		if(z==Sucursal){	
			for(int i=0; i<M; i++){
				if(Models==i){
					for(int j=0; j<N; j++){
						Cantidad+=Multi[i][j][z];
					}
				}	
			}
		}	
	}
	
	printf("\nLa cantidad producida del modelo %d de la sucursal %d es de: %d", Models, Sucursal, Cantidad);
}
	
	