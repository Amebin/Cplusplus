#include<stdio.h>

main(){
	float Vdeclarado=0, Cfinal=0;
	
	printf("Ingresa el valor declarado del bien: ");
	scanf("%f", &Vdeclarado);
	
	if(Vdeclarado<=1500){
		Cfinal= Vdeclarado + Vdeclarado*0.15 + 200 + 0.02*Vdeclarado;
	} else{
		Cfinal= Vdeclarado + Vdeclarado*0.2 + 200 + 0.02*Vdeclarado;
	}
	
	printf("El costo final de importacion es de: %.2f", Cfinal);
}