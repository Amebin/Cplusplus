#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Ingrediente {
    char nombre[20];
    float cantidad;
};

struct Receta {
    char nombre[50];
    char pasos[500];
    struct Ingrediente ingredientes[20];
    int cantidadIngredientes;
};

struct StockIngrediente {
    char nombreIngrediente[20];
    float cantidadDisponible;
};

// Declaración de funciones
void crearReceta();
void listarRecetas();
void actualizarReceta();
void eliminarReceta();
void agregarIngredienteStock(struct StockIngrediente ingrediente);
void mostrarStock();
void actualizarStock(struct Receta receta);
void gestionarStock();

void crearReceta() {
    FILE *archivo = fopen("recetas.dat", "ab");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    struct Receta nuevaReceta;
    
    printf("Ingrese el nombre de la receta: ");
    scanf(" %[^\n]", nuevaReceta.nombre);

    nuevaReceta.cantidadIngredientes = 0;
    printf("Ingrese los ingredientes (ingrese '0' para terminar):\n");
    
    while (nuevaReceta.cantidadIngredientes < 20) {
        printf("Ingrediente: ");
        scanf(" %[^\n]", nuevaReceta.ingredientes[nuevaReceta.cantidadIngredientes].nombre);
        if (strcmp(nuevaReceta.ingredientes[nuevaReceta.cantidadIngredientes].nombre, "0") == 0)
            break;
        printf("Cantidad de kg necesarios del producto requerido: ");
        scanf("%f", &nuevaReceta.ingredientes[nuevaReceta.cantidadIngredientes].cantidad);
        nuevaReceta.cantidadIngredientes++;
    }

    printf("Ingrese los pasos y al terminar presiona enter: ");
    scanf(" %[^\n]", nuevaReceta.pasos);

    fwrite(&nuevaReceta, sizeof(struct Receta), 1, archivo);
    fclose(archivo);
    printf("Receta agregada correctamente.\n");

}

void listarRecetas() {
    FILE *archivo = fopen("recetas.dat", "rb");
    if (archivo == NULL) {
        printf("No hay recetas almacenadas.\n");
        return;
    }

    struct Receta receta;
    while (fread(&receta, sizeof(struct Receta), 1, archivo)) {
        printf("\nNombre: %s\n", receta.nombre);
        printf("Ingredientes necesarios:\n");
        for (int i = 0; i < receta.cantidadIngredientes; i++) {
            printf("- %s: %.2f kg\n", receta.ingredientes[i].nombre, receta.ingredientes[i].cantidad);
        }
        printf("Pasos: %s\n", receta.pasos);
    }
    fclose(archivo);
}

void actualizarReceta() {
    FILE *archivo = fopen("recetas.dat", "rb+");
    if (archivo == NULL) {
        printf("No hay recetas almacenadas.\n");
        return;
    }

    char nombreBuscado[50], auxNombreExistente[50];
    long punteroReceta;
    printf("Ingrese el nombre de la receta a actualizar: ");
    scanf(" %[^\n]", nombreBuscado);
	strlwr(nombreBuscado);

    struct Receta receta;
    while (fread(&receta, sizeof(struct Receta), 1, archivo)) {
    	strcpy(auxNombreExistente, receta.nombre);
    	
        if (strcmp(auxNombreExistente, nombreBuscado) == 0) {
        	punteroReceta= ftell(archivo);
        	
            printf("Ingrese el nuevo nombre: ");
            scanf(" %[^\n]", receta.nombre);
            
            receta.cantidadIngredientes = 0;
            printf("Ingrese los nuevos ingredientes (ingrese '0' para terminar):\n");
            
            while (receta.cantidadIngredientes < 20) {
                printf("Ingrediente: ");
                scanf(" %[^\n]", receta.ingredientes[receta.cantidadIngredientes].nombre);
                if (strcmp(receta.ingredientes[receta.cantidadIngredientes].nombre, "0") == 0)
                    break;
                printf("Cantidad en kg requeridos: ");
                scanf("%f", &receta.ingredientes[receta.cantidadIngredientes].cantidad);
                receta.cantidadIngredientes++;
            }
            
            printf("Ingrese los nuevos pasos: ");
            scanf(" %[^\n]", receta.pasos);
            
            fseek(archivo, punteroReceta, SEEK_SET);
            fseek(archivo, -sizeof(Receta), SEEK_CUR);
            fwrite(&receta, sizeof(Receta), 1, archivo);
            printf("Receta actualizada correctamente.\n");
            break;
        }
    }
    fclose(archivo);
}

void eliminarReceta() {
    FILE *archivo = fopen("recetas.dat", "rb");
    if (archivo == NULL) {
        printf("No hay recetas almacenadas.\n");
        return;
    }

    char nombreBuscado[50];
    printf("Ingrese el nombre de la receta a eliminar: ");
    scanf(" %[^\n]", nombreBuscado);

    FILE *temp = fopen("temp.dat", "wb");
    struct Receta receta;
    int eliminado = 0;
    
    while (fread(&receta, sizeof(struct Receta), 1, archivo)) {
        if (strcmp(receta.nombre, nombreBuscado) == 0) {
            eliminado = 1;
        } else {
            fwrite(&receta, sizeof(struct Receta), 1, temp);
        }
    }
    
    fclose(archivo);
    fclose(temp);
    
    remove("recetas.dat");
    rename("temp.dat", "recetas.dat");

    if (eliminado) {
        printf("Receta eliminada correctamente.\n");
    } else {
        printf("Receta no encontrada.\n");
    }
}

void agregarIngredienteStock(struct StockIngrediente ingrediente) {
    FILE *archivo = fopen("stock.dat", "ab");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de stock.\n");
        return;
    }
    fwrite(&ingrediente, sizeof(struct StockIngrediente), 1, archivo);
    fclose(archivo);
}

int main() {
    int opcion;
    do {
        printf("\n--- Modulo de Recetas ---\n");
        printf("1. Crear receta\n");
        printf("2. Listar recetas\n");
        printf("3. Actualizar receta\n");
        printf("4. Eliminar receta\n");
        printf("5. Volver al menu anterior\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case 1: crearReceta(); break;
            case 2: listarRecetas(); break;
            case 3: actualizarReceta(); break;
            case 4: eliminarReceta(); break;
           
            case 5: printf("Regresando al menu anterior...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 5);

    return 0;
}

