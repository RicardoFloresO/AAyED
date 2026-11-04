#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "TDAlistaDEv2.h"

int main(int argc, char *argv[]){
	ListaDE *L=crearListaDE();
	insertarInicioDE(L,40);
	insertarInicioDE(L,30);
	insertarInicioDE(L,20);
	printf("Primer nodo->%d\n", L->head->info);
	
	insertarFinDE(L,100);
	insertarFinDE(L,200);
	mostrarListaDE(L);

	if(argc != 2){
		printf("Ingrese el nombre del archivo en la LC\n");
		return 1;
	}
	ListaDE *L1 = crearInsertarListaDE_desde_archivo(argv[1]);
	mostrarListaDE(L1);

	eliminarInicioDE(L1);
	mostrarListaDE(L1);
	destruirListaDE(L1);
	mostrarListaDE(L1);
	
	return 0;
}