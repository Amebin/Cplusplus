#include <stdio.h>
int LADO1, LADO2, PERIMETRO;

main()
{
      printf("Para calcular el perimetro, por favor ingresa el lado 1\n");
      scanf("%d", &LADO1);
      printf("Ingrese el lado 2\n");
      scanf("%d", &LADO2);
      
      PERIMETRO = LADO1*2 + LADO2*2;
      
      printf("El perimetro es =%d", PERIMETRO);

}
