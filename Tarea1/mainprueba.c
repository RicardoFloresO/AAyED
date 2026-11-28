#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "TDAcarga.h"
#include "TDAcontenedor.h"
#include "algoritmos.h"

/*
Lee el archivo de entrada, valida el formato y la factibilidad de las cargas
precond: Recibe el nombre del archivo y la direccion donde guardar capMax
postcond: Devuelve la ListaCarga inicial con IDs de 1 a N, o NULL si hay algun error
*/
ListaCarga* archivoListaCarga(char *nom_archivo, int *capMax) {
    FILE *fp = fopen(nom_archivo, "r");
    if (fp == NULL) {
        printf("Error: No se pudo abrir el archivo '%s'.\n", nom_archivo);
        return NULL;
    }

    int n = 0;
    // Validar cabecera: dos enteros estrictamente positivos (N > 0 y C > 0)
    if (fscanf(fp, "%d %d", &n, capMax) != 2 || n <= 0 || *capMax <= 0) {
        printf("Error: Cabecera invalida en el archivo (N y C deben ser enteros positivos).\n");
        fclose(fp);
        return NULL;
    }

    ListaCarga *zonaAcopio = crearListaCarga();
    int peso = 0;

    // Leer exactamente N pesos y validar que cada uno cumpla 0 < peso <= capMax
    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &peso) != 1 || peso <= 0) {
            printf("Error: Faltan cargas o existe un peso no positivo en la linea %d.\n", i + 2);
            destruirListaCarga(zonaAcopio);
            fclose(fp);
            return NULL;
        }
        if (peso > *capMax) {
            printf("Error: La carga c%d (peso %d) supera la capacidad maxima (%d). Instancia sin solucion.\n",
                   i + 1, peso, *capMax);
            destruirListaCarga(zonaAcopio);
            fclose(fp);
            return NULL;
        }

        Carga nuevaCarga;
        nuevaCarga.id = i + 1;
        nuevaCarga.peso = peso;
        insertarCargaFin(zonaAcopio, nuevaCarga);
    }

    // Verificar que no sobren datos adicionales al final del archivo
    int extra = 0;
    if (fscanf(fp, "%d", &extra) == 1) {
        printf("Error: El archivo contiene mas de %d cargas.\n", n);
        destruirListaCarga(zonaAcopio);
        fclose(fp);
        return NULL;
    }

    fclose(fp);
    return zonaAcopio;
}

/*
Imprime el mapeo de asignacion (c1 -> X, ...) y retira las cargas embarcadas de la copia de acopio
precond: Recibe la copia de la zona de acopio, la lista de contenedores solucion y el total N
postcond: Muestra la asignacion por pantalla y deja copiaAcopio vacia
*/
void registrarEmbarque(ListaCarga *copiaAcopio, ListaContenedor *solucion, int totalCargas) {
    printf("Asignacion de cargas: ");
    for (int id = 1; id <= totalCargas; id++) {
        int idCont = contenedorDeCarga(solucion, id);
        printf("c%d -> %d", id, idCont);
        if (id < totalCargas) {
            printf(", ");
        }
        // Retirar la carga embarcada de la zona de acopio de trabajo
        eliminarCargaId(copiaAcopio, id);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // 1. Validar argumento por linea de comandos
    if (argc != 2) {
        printf("Uso correcto: %s <archivo_entrada.in>\n", argv[0]);
        return 1;
    }

    // 2. Lectura y validacion del archivo de entrada
    int capContenedor = 0;
    ListaCarga *zonaAcopioOriginal = archivoListaCarga(argv[1], &capContenedor);
    if (zonaAcopioOriginal == NULL) {
        return 1;
    }

    int totalCargas = numCargas(zonaAcopioOriginal);

    // Mostrar estado inicial de la zona de acopio
    printf("Zona de acopio (estado inicial): ");
    mostrarListaCarga(zonaAcopioOriginal);
    printf("\n");

    // =========================================================================
    // 3. EJECUCION DEL ALGORITMO EXACTO
    // =========================================================================
    ListaCarga *acopioExacto = copiarListaCarga(zonaAcopioOriginal);

    clock_t iniExacto = clock();
    ListaContenedor *solucionExacta = exacto(acopioExacto, capContenedor);
    clock_t finExacto = clock();
    double tiempoExacto = (double)(finExacto - iniExacto) / CLOCKS_PER_SEC;

    printf("=== ALGORITMO EXACTO ===\n");
    printf("Total de contenedores: %d\n", numContenedores(solucionExacta));
    mostrarListaContenedor(solucionExacta);
    registrarEmbarque(acopioExacto, solucionExacta, totalCargas);
    printf("Tiempo de ejecucion: %.6f s\n", tiempoExacto);
    printf("Zona de acopio (despues de exacto): ");
    mostrarListaCarga(acopioExacto);
    printf("\n");

    // =========================================================================
    // 4. EJECUCION DE LA HEURISTICA
    // =========================================================================
    ListaCarga *acopioHeuristica = copiarListaCarga(zonaAcopioOriginal);

    clock_t iniHeur = clock();
    ListaContenedor *solucionHeuristica = heuristica(acopioHeuristica, capContenedor);
    clock_t finHeur = clock();
    double tiempoHeuristica = (double)(finHeur - iniHeur) / CLOCKS_PER_SEC;

    printf("=== HEURISTICA ===\n");
    printf("Total de contenedores: %d\n", numContenedores(solucionHeuristica));
    mostrarListaContenedor(solucionHeuristica);
    registrarEmbarque(acopioHeuristica, solucionHeuristica, totalCargas);
    printf("Tiempo de ejecucion: %.6f s\n", tiempoHeuristica);
    printf("Zona de acopio (despues de heuristica): ");
    mostrarListaCarga(acopioHeuristica);
    printf("\n");

    // =========================================================================
    // 5. LIBERACION DE MEMORIA DINAMICA
    // =========================================================================
    destruirListaContenedor(solucionExacta);
    destruirListaContenedor(solucionHeuristica);
    destruirListaCarga(acopioExacto);
    destruirListaCarga(acopioHeuristica);
    destruirListaCarga(zonaAcopioOriginal);

    return 0;
}