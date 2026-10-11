//Ricardo Flores Lab semana 3 actividad 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int promedio(int *A,int n){
	int suma = 0;
	int prom;
	for(int i=0;i<n;i++){
		suma = suma + A[i];
	}
	//printf("n->%d\n",n);
	prom = suma / n;
	//printf("sum->%d\n",suma);
	//printf("->%d\n",prom);
	return prom;
}


int posCercana_Aprom(int *A, int n){
	int prom;
	prom = promedio(A,n);
	//Encontrar el valor mas cercano
	//Recorrer la lista y restar con el promedio e ir guardando en un arreglo
	int *Aux = malloc(sizeof(int)*n);
	int dif;
	for(int i=0;i<n;i++){
		dif = prom - A[i];
		dif = abs(dif);
		Aux[i] = dif;
		//printf("%d ",Aux[i]);
	}
	//Comparar datos para encontrar el menor
	int menor = Aux[0];
	int pos = 0;
	for(int i=0;i<n;i++){
		if(menor > Aux[i]){
			menor = Aux[i];
			pos = i;
		}
	}
	//printf("menor->%d",menor);
	//printf("pos->%d",pos);

	free(Aux);
	return pos;
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
	/*
	for (int i = 0; i < n; i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	*/
	int pos;
	pos = posCercana_Aprom(A,n);

	printf("El valor mas cercano es: %d\n", A[pos]);
	printf("La posicion del elemento mas cercano es : %d\n",pos);
	free(A);
	return 0;
}