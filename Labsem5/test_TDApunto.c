#include <stdio.h>
#include <stdlib.h>
#include "TDApunto.h"

int main(int argc, char *argv[]){

	if(argc!=5){
		printf("Ingrese los datos de 2 puntos en la LC\n");
		return 1;
	}
	Punto *P1=crea_punto(atoi(argv[1]),atoi(argv[2]));
	Punto *P2=crea_punto(atoi(argv[3]),atoi(argv[4]));
	printf("dist entre puntos-> %d\n",calcula_distancia(P1,P2));
	printf("dist al origen(0,0)-> %d\n",distancia_origen(P1));
	printf("dist al origen(0,0)-> %d\n",distancia_origen(P2));
	printf("cuadrante-> %d\n", cuadrante(P1));
	printf("cuadrante-> %d\n", cuadrante(P2));
	mostrar_punto(P1);
	desplazar(P1,2,-2);
	mostrar_punto(P1);
	
	int res = esta_en_eje(P1);
	if(res==1){
		printf("Punto P1 SI esta en uno de los ejes");
	}else{
		printf("Punto P1 NO esta en uno de los ejes");
	}

	return 0;
}