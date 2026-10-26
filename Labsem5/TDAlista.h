#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Se crea la estructura para el TDA lista
struct nodo{
	int info;
	struct nodo *sig;
};
typedef struct nodo Nodo;

struct lista{
	Nodo *head;
};
typedef struct lista Lista;

//Declaracion de las operaciones del TDAlista
Lista* crearLista();
Nodo* crearNodo(int val);
void insertarInicio(Lista *L, int val);
void insertarFin(Lista *L, int val);
void mostrarLista(Lista *L);
void eliminarInicio(Lista *L);
void eliminarFin(Lista *L);
Nodo* buscarNodo(Lista *L, int val);
void eliminarNodo(Lista *L, int val);
void insertarDspsDe(Lista *L, int valAnt, int valIns);

//Implementacion de las operaciones del TDAlista
Lista* crearLista(){
	Lista *L = malloc(sizeof(Lista));
	L->head = NULL;
	return L;
}

Nodo* crearNodo(int val){
	Nodo *nvoNodo = malloc(sizeof(Nodo));
	nvoNodo->info = val;
	nvoNodo->sig = NULL;
	return nvoNodo;
}

void insertarInicio(Lista *L, int val){
	Nodo *N = crearNodo(val);
	if(L->head != NULL){
		N->sig = L->head;
	}
	L->head = N;
}

void insertarFin(Lista *L, int val){
	Nodo *N = crearNodo(val);
	if(L->head == NULL){
		L->head = N;
	}else{
		Nodo *ptr = L->head;
		while(ptr->sig != NULL){
			ptr = ptr->sig;
		}
		ptr->sig = N;
	}
}

void mostrarLista(Lista *L){
	if(L->head == NULL){
		printf("Lista vacia\n");
	}else{
		Nodo *ptr = L->head;
		while(ptr != NULL){
			printf("%d ->",ptr->info);
			ptr = ptr->sig;
		}
	}

}

void eliminarInicio(Lista *L){
	if(L->head == NULL){
		printf("Lista vacia\n");
	}else{
		Nodo *ptr = L->head;
		L->head = ptr->sig;
		ptr->sig = NULL;
		free(ptr);
	}
}

void eliminarFin(Lista *L){
	if(L->head==NULL){
		printf("Lista vacia\n");
	}else{
		Nodo *ptr = L->head;
		if(ptr->sig == NULL){
			L->head = NULL;
		}else{
			Nodo *ant = NULL;
			while(ptr->sig != NULL){
				ant = ptr;
				ptr = ptr->sig;
			}
			ant->sig = NULL;
		}
		free(ptr);
	}
}

Nodo* buscarNodo(Lista *L, int val){

}

void eliminarNodo(Lista *L, int val){
	if(L->head == NULL){
		printf("Lista vacia\n");
	}else{
		Nodo *ptrEliminar = buscarNodo(L,val);
		if(ptrEliminar !=NULL){
			if(ptrEliminar == L->head){
				eliminarInicio(L);
			}else{
				if(ptrEliminar->sig == NULL){
					eliminarFin(L);
				}else{
					Nodo *ptrAnt = L->head;
					while(ptrAnt->sig != ptrEliminar){
						ptrAnt = ptrAnt->sig;
					}
					ptrAnt->sig = ptrEliminar->sig;
					ptrEliminar->sig = NULL;
					free(ptrEliminar);
				}
			}
		}else{
			printf("Nodo a eliminar NO ENCONTRADO\n");
		}
	}
}

void insertarDspsDe(Lista *L, int valAnt, int valIns){
	Nodo *N = crearNodo(valIns);
	if(L->head == NULL){
		L->head = N;
	}else{
		Nodo *auxAnt = buscarNodo(L,valAnt);
		if(auxAnt != NULL){
			if(L->head->info==auxAnt->info || auxAnt->sig==NULL){
				insertarFin(L,valIns);
			}else{
				N->sig = auxAnt->sig;
				auxAnt->sig = N;
			}
		}else{
			printf("Nodo a eliminar no encontrado\n");
			free(N);
		}
	}
}