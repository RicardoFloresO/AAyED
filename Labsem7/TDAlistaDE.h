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

