#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "TDAlistaDE.h"

int main(){
	ListaDE *L=crearListaDE();
	insertarInicioDE(L,40);
	insertarInicioDE(L,30);
	insertarInicioDE(L,20);
	
	printf("Primer nodo->%d\n",L->head->info);

	return 0;
}