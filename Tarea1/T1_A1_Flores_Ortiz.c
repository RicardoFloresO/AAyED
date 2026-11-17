#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "TDAcarga.h"
#include "TDAcontenedor.h"

/*Esta funcion creara la zona de acopio a partir de los datos que obtenga de los archivos
de prueba, de la primera linea del archivo se obtiene la capacidad maxima de los contenedores
y cuantas cargas tendra la zona de acopio.

A partir de la segunda linea se obtienen los pesos de cada carga, como no se pueden retornar 
dos valores de una funcion antes de llamar esta funcion se debe definir una capMax de carga
que luego sera sustituida por la correspondiente al contenedor.
*/ 
ListaCarga* archivoListaCarga(char *nom_archivo, int *capMax) {
    int n, pesos;
    FILE *fp = fopen(nom_archivo, "r");
    if (fp == NULL) {
        return NULL;
    }
    //Se crea la zona de acopio
    ListaCarga *zonaAcopio = crearListaCarga();

    //Se lee la cantidad de cargas y la capacidad maxima
    fscanf(fp, "%d %d", &n, capMax)

	//Se lee el peso de cada carga desde el archivo y se le asigna a una carga con id
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &pesos);
        Carga nuevaCarga;
        nuevaCarga.id = i + 1;
        nuevaCarga.peso = pesoLeido;

        insertarCargaFin(zonaAcopio, nuevaCarga);
        
    }

    fclose(fp);
    return zonaAcopio;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Ingrese el nombre del archivo en la LC.\n");
        return 1;
    }

    int capContenedor = 0;
    ListaCarga *zonaAcopio = archivoListaCarga(argv[1], &capContenedor);

    if (zonaAcopio == NULL) {
        printf("Error al abrir o leer el archivo %s\n", argv[1]);
        return 1;
    }

    printf("Capacidad maxima por contenedor (C): %d\n", capContenedor);
    printf("Cantidad de cargas leidas (N): %d\n", numCargas(zonaAcopio));
    printf("Peso total en Zona de Acopio: %d\n\n", pesoListaCarga(zonaAcopio));

    printf("--- Zona de Acopio Original ---\n");
    mostrarListaCarga(zonaAcopio);

    // Probamos copiar y eliminar en la copia sin dañar la original
    ListaCarga *copia = copiarListaCarga(zonaAcopio);
    eliminarCargaId(copia, 1);
    printf("\n--- Copia sin la carga c1 ---\n");
    mostrarListaCarga(copia);

    // Liberamos memoria
    destruirListaCarga(zonaAcopio);
    destruirListaCarga(copia);

    return 0;
}