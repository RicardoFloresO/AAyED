#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int** matriz_pares(int**M, int n, int m){
	for(int i=0; i<n;i++){
		for(int j=0; j<m;j++){
			if(M[i][j]%2 != 0){
				M[i][j] = 0;
			}
		}
	}
	return M;
}

int** leer_datos_Fil(char *nom_archivo, int *n, int *m){
	FILE *fp = fopen(nom_archivo, "r");
	if(fp==NULL){
		printf("\n Archivo no existe \n");
		return NULL;
	}

	fscanf(fp, "%d,%d", n, m);
	int **matriz = malloc(*n * sizeof(int*));
	for (int i = 0; i < *n; i++){
		matriz[i] = malloc(*m * sizeof(int));
		for(int j = 0; j<*m;j++){
			fscanf(fp, "%d", &matriz[i][j]);
		}
	}
	fclose(fp);
	return matriz;
}


int main(int argc, char *argv[]){
	int n=0;
	int m=0;
	if (argc != 2){
		return 1;
	}

	int **M = leer_datos_Fil(argv[1], &n, &m);
	if ( M == NULL ){
		return 1;
	}

	M = matriz_pares(M, n, m);
	for(int i = 0; i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",M[i][j]);
		}
		printf("\n");
	}

	free(M);
	return 0;
}