//Lab semana 3 Ricardo Flores
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Actividad 1
int swap(int *a, int*b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

int invertir(int *A, int n){
	for(int i=0; i<n; i=i+2){
		swap(&A[i],&A[i+1]);
	}

}

//Actividad 2
int promedio(int *A, int n){
	int suma = 0;
	for(int i=0;i<n;i++){
		suma = suma + A[i];
	}
	suma = suma/n;
	//printf("El promedio es: %d\n",suma);
}

int posCercana_Aprom(int *A, int n){
	int prom;
	prom = promedio(A,n);


}

int* leer_datos_Fil(char *nom_archivo, int *n){
	FILE *fp = fopen(nom_archivo, "r");
	if(fp==NULL){
		printf("\n Archivo no existe \n");
		return NULL;
	}
	fscanf(fp, "%d", n);
	int *array = malloc(*n * sizeof(int));
	for (int i = 0; i < *n; i++){
		fscanf(fp, "%d", &array[i]);
	}
	fclose(fp);
	return array;
}

int main(int argc, char *argv[]){
	int n=0;
	if (argc != 2){
		return 1;
	}

	int *A = leer_datos_Fil(argv[1], &n);
	if ( A == NULL ){
		return 1;
	}

	for (int i = 0; i < n; i++){
		printf("%d ",A[i]);
	}
	printf("\n");

	invertir(A,n);
	for (int i = 0; i < n; i++){
		printf("%d ",A[i]);
	}
	printf("\n");

	//promedio(A,n);
	free(A);
	return 0;
}