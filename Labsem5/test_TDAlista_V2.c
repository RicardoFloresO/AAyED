//Ricardo Flores 20828060-0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TDAlista.h" 

Lista* archivo_a_Lista(char *nom_archivo){
	int n, val;
	FILE *fp = fopen(nom_archivo, "r");
	if (fp==NULL){
		return NULL;
	}
	Lista *lis=crearLista();
	fscanf(fp, "%d", &n);
	for(int i = 0; i < n; i++){
		fscanf(fp, "%d", &val);
		insertarInicio(lis, val);
	}
	fclose(fp);
	return lis;
}


int main(int argc, char *argv[]){
	if (argc != 3){
		return 1;
	}
	Lista *L1 = archivo_a_Lista(argv[1]);
	Lista *L2 = archivo_a_Lista(argv[2]);

	if(L1==NULL){
		return 1;
	}
	if(L2==NULL){
		return 1;
	}
	printf("Lista despues de insertarInicio desde archivo:\n");

	printf("Mostrando L1:");
	mostrarLista(L1);
	printf("\nMostrando L2:");
	mostrarLista(L2);

	Lista *Lpos = positivo(L1,L2);
	printf("\nMostrando Lpos:");
	mostrarLista(Lpos);

	printf("\nIntercambiando las posiciones L1[4] y L1[9]");

	intercambiar(L1, 4, 9);
	mostrarLista(L1);

	Lista *Ljuntas = juntar(L1,L2);
	printf("\nMostrando Ljuntas:");
	mostrarLista(Ljuntas);

	printf("\nVerificando si las listas son iguales:");
	int n = iguales(L1,L2);
	if(n==1){
		printf("\nLas listas son iguales");
	}else{
		printf("\nLas listaas NO son iguales");
	}

	destruir_lista(L1);
	destruir_lista(L2);
	destruir_lista(Lpos);
	destruir_lista(Ljuntas);
	return 0;
}
