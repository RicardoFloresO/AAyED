//Ricardo Flores 20828060-0
#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"

int main(){
	Lista *L1=crearLista();
	insertarInicio(L1, 10);
	insertarInicio(L1, 20);
	insertarInicio(L1, 30);
	insertarFin(L1, 80);
	insertarFin(L1, 100);
	mostrarLista(L1);
	eliminarInicio(L1);
	eliminarFin(L1);
	mostrarLista(L1);

	return 0;
}