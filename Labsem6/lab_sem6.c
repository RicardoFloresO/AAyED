/* ESTE ES EL PROGRAMA FUENTE lab_sem6.c QUE DEBE USAR 
   PARA RESOLVER LA GUIA DE LABORATORIO DE LA SEMANA 6  */

/*  PROBLEMA 1-A): Agregue las Cabeceras de librerías propias de C y de los TDAs */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "TDAlista.h"
#include "TDApila.h"


/*  PROBLEMA 2: Funcion(es)  */
Lista* intercalar(Lista *L1, Lista *L2){
	Lista *Laux = crearLista();

	Nodo *ptr1 = L1->head;
	Nodo *ptr2 = L2->head;
	while(ptr1 != NULL && ptr2 != NULL){
		insertarFin(Laux,ptr1->info);
		insertarFin(Laux,ptr2->info);
		ptr1 = ptr1->sig;
		ptr2 = ptr2->sig;

	}
	while(ptr1 != NULL){
		insertarFin(Laux,ptr1->info);
		ptr1 = ptr1->sig;
	}
	while(ptr2 != NULL){
		insertarFin(Laux,ptr2->info);
		ptr2 = ptr2->sig;
	}

	return Laux;
}



/*  PROBLEMA 3: Funcion(es)  */
int promedio(Lista *L1){
	int suma = 0;
	int cont = 0;
	Nodo *ptr1 = L1->head;
	while(ptr1 != NULL){
		suma = suma + ptr1->info;
		cont++;
		ptr1 = ptr1->sig;
	}
	int res = suma/cont;
	return res;
}

Lista* cercano(Lista *L1){
	Lista *Laux = crearLista();
	int prom = promedio(L1);
	Nodo *ptr1 = L1->head; //Recorre la lista 1
	int valorCerca = ptr1->info;
	int menor = abs(ptr1->info - prom);

	while(ptr1 != NULL){
		if(abs(ptr1->info - prom) < menor){
			menor = abs(ptr1->info - prom);
			valorCerca = ptr1->info;
		}

		ptr1 = ptr1->sig;
	}

	insertarFin(L1,valorCerca);

	return L1;
}



/*  PROBLEMA 4: Funcion(es)  */










/*  *********************************************** */
/*         FUNCIÓN   PRINCIPAL                      */
/*  *********************************************** */
int main(int argc,  char *argv[]){ 

	/* *************************************************************** */
	/*		                 P R O B L E M A    1					   */
	/* *************************************************************** */
	/* Valide el número de parámetros ingresados desde la Línea de Comando (LC) */
	if(argc != 4){
		printf("Ingrese los nombres de los archivos en al LC\n");
		return 1;
	}



	/* Cree las listas L1 y L2 desde archivo y valide que no vengan vacías*/
	Lista *L1 = crearInsertarLista_desde_archivo(argv[1]);
	Lista *L2 = crearInsertarLista_desde_archivo(argv[2]);

	if(L1 == NULL){
		printf("No se pudo leer el archivo de la Lista1.\n");
		return 1;
	}

	if(L2 == NULL){
		printf("No se pudo leer el archivo de la Lista2.\n");
		return 1;
	}


	/* Muestre cada una de las listas indicando cuál es L1 y cuál es L2 */

	printf("Se muestra la L1: \n");
	mostrarLista(L1);
	printf("Se muestra la L2: \n");
	mostrarLista(L2);

	/* Cree la pila  desde archivo  y valide que P no venga vacía*/
	Pila *P = crearInsertarPila_desde_archivo(argv[3]);

	if(P == NULL){
		printf("No se pudo leer el archivo de la pila.\n");
		return 1;
	}

	/* mestre el tope de pila P */

	Nodop *Top = tope(P);
	printf("El tope es: %d\n", Top->info);
	

	/* *************************************************************** */
	/*		                 P R O B L E M A    2					   */
	/* **************************************************************  */

	Lista *L3 = intercalar(L1,L2);
	printf("Se muestra la L3: \n");
	mostrarLista(L3);





	/* ***************************************************************** */
	/*		                 P R O B L E M A    3   					 */
	/* ***************************************************************** */


	printf("Se muestra la lista 1 antes de agregar el valor mas cercano al promedio.\n");
	mostrarLista(L1);
	Lista *L4 = cercano(L1);
	printf("Se muestra la lista 1 con el valor mas cercano al promedio agregado.\n");
	mostrarLista(L4);


	/* *************************************************************** */
	/*		                 P R O B L E M A    4					   */
	/* *************************************************************** */






    /* Destruya las listas y la pila */	


	return 0;
}
