#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct reg_nodoDE{
	int info;
	struct reg_nodoDE *prev;
	struct reg_nodoDE *sig;
};
typedef struct reg_nodoDE NodoDE;

struct reg_listaDE{
	NodoDE *head;
};
typedef struct reg_listaDE ListaDE;

//Declaracion de las funciones del TDAlistaDE

//problema 1
ListaDE* crearListaDE();
bool isListaVaciaDE(ListaDE *L);
NodoDE* crearNodoDE(int val);
void insertarInicioDE(ListaDE *L, int val);

//problema 2
void insertarFinDE(ListaDE *L, int val);
void mostrarListaDE(ListaDE *L);
ListaDE* crearInsertarListaDE_desde_archivo(char *nom_archivo);
void eliminarInicioDE(ListaDE *L);
void destruirListaDE(ListaDE *L);

//Implementacion de las funciones del TDAlistaDE
//problema 1
ListaDE* crearListaDE(){
	ListaDE *L = malloc(sizeof(ListaDE));
	L->head = NULL;
	return L;
}

bool isListaVaciaDE(ListaDE *L){
	if(L->head == NULL){
		return true;
	}else{
		return false;
	}
}

NodoDE* crearNodoDE(int val){
	NodoDE *N = malloc(sizeof(NodoDE));
	N->info = val;
	N->prev = NULL;
	N->sig = NULL;
	return N;
}

void insertarInicioDE(ListaDE *L, int val){
	NodoDE *nvo = crearNodoDE(val);
	if(isListaVaciaDE(L) != true){
		nvo->sig = L->head;
	}
	L->head = nvo;
}

//problema 2
void insertarFinDE(ListaDE *L, int val){
	NodoDE *nvo = crearNodoDE(val);
	if (L->head == NULL){
		L->head = nvo;
	}else{
		NodoDE *ptr = L->head;
		while (ptr->sig != NULL){
			ptr = ptr->sig;
		}
		ptr->sig = nvo;
		nvo->prev = ptr;
	}
}

void mostrarListaDE(ListaDE *L){
	if (isListaVaciaDE(L) != true){ 
	    NodoDE *ptr = L -> head;
	    while(ptr != NULL){
		    printf("  %d", ptr -> info);
		    ptr = ptr -> sig;
	    }
		printf("\n");
	}else{
		printf("\n Lista Vacia \n");
    }
}

ListaDE* crearInsertarListaDE_desde_archivo(char *nom_archivo){
	int n, val;
	FILE *fp = fopen(nom_archivo, "r");
	if(fp==NULL){
		return NULL;
	}
	ListaDE *lis=crearListaDE();
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++){
		fscanf(fp, "%d", &val);
		insertarFinDE(lis, val);
	}
	fclose(fp);	
	return lis;
}

void eliminarInicioDE(ListaDE *L){
	if(isListaVaciaDE(L) == true){
		printf("La lista esta vacia\n");
	}else{
		NodoDE *ptr = L->head;
		L->head = ptr->sig;
		ptr->sig = NULL;
		free(ptr);
	}
}

void destruirListaDE(ListaDE *L){
	if(isListaVaciaDE(L) != true){
		while(L->head != NULL){
			eliminarInicioDE(L);
		}
	}
}
