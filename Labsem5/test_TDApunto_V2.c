#include <stdio.h>
#include <stdlib.h>
#include "TDApunto.h"

Punto** datosFil_a_TDApunto(char *nom_archivo, int *n){ 
	float val1, val2;
	FILE *fp = fopen(nom_archivo, "r");
	if(fp==NULL){
		return NULL;
	}
	fscanf(fp, "%d",n);
	Punto **p = malloc(*n *sizeof(Punto *)); //Punto **p representa un arreglo de puntos
	for(int i=0; i< *n; i++){
		fscanf(fp, "%f %f", &val1, &val2);
		p[i] = crea_punto(val1,val2);
	}
	fclose(fp);
	return p;
}

int distancia_puntoSimetrico(Punto *A){
	Punto *Asim = crea_punto(A->coord_x*-1,A->coord_y*-1);
	int dis = distancia_origen(Asim);
	return dis;
}

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Ingrese el nombre del archivo en la LC");
		return 1;
	}
	int n=0;
	Punto **ptos = datosFil_a_TDApunto(argv[1],&n);
	if(ptos==NULL){
		printf("Problemas al abrir o leer el archivo\n");
		return 1;
	}
	for(int i=0; i<n; i++){
		printf("punto n: %d\n",i);
		mostrar_punto(ptos[i]);
		if(i<n-1){
			printf("dist entre puntos-> %d\n",calcula_distancia(ptos[i],ptos[i+1]));
		}
		printf("dist al origen(0,0)-> %d\n",distancia_origen(ptos[i]));
		printf("dist al origen(0,0) del Psim-> %d\n",distancia_puntoSimetrico(ptos[i]));
		printf("cuadrante-> %d\n", cuadrante(ptos[i]));

		int res = esta_en_eje(ptos[i]);
		if(res==1){
			printf("Punto P1 SI esta en uno de los ejes\n");
		}else{
			printf("Punto P1 NO esta en uno de los ejes\n");
		}
	}
	return 0;
}