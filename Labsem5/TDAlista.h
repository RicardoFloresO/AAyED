//Ricardo Flores 20828060-0
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

//ejercicios propuestos
Lista* positivo(Lista *L1, Lista *L2); //2 
void intercambiar(Lista *L, int pos1, int pos2); //3
Lista* juntar(Lista *L1, Lista *L2); //4
int iguales(Lista *L1, Lista *L2); //5

void destruir_lista(Lista *L);

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
	printf("\n");
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

Nodo* buscarNodo(Lista *L, int val){ //ejercicio 1
	Nodo *ptr = L->head;
	while(ptr != NULL){
		if(ptr->info == val){
			return ptr;
		}
		ptr=ptr->sig;
	}
	return NULL;
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

/*Se recorre la lista 1 y se guardan todos los positivos en una lista aux, luego
se hace lo mismo con la lista 2
*/
Lista* positivo(Lista *L1, Lista *L2){
    Lista *Laux = crearLista();
    
    Nodo *ptr1 = L1->head;
    while(ptr1 != NULL){
        if(ptr1->info > 0){
            insertarFin(Laux, ptr1->info);
        }
        ptr1 = ptr1->sig;
    }
    
    Nodo *ptr2 = L2->head;
    while(ptr2 != NULL){
        if(ptr2->info > 0){
            insertarFin(Laux, ptr2->info);
        }
        ptr2 = ptr2->sig;
    }    
    return Laux;
}

/*
*/
void intercambiar(Lista *L, int pos1, int pos2){
    if(L->head != NULL && pos1 != pos2){
        Nodo *ptr = L->head;
        Nodo *nodo1 = NULL;
        Nodo *nodo2 = NULL;
        int contador = 0;

        while(ptr != NULL){
            if(contador == pos1){
            	nodo1 = ptr; 
            }
            if(contador == pos2){
            	nodo2 = ptr; 
            }
            ptr = ptr->sig;
            contador = contador + 1;
        }
        if(nodo1!=NULL && nodo2!=NULL){
        	int aux = nodo1->info;   
        	nodo1->info = nodo2->info; 
        	nodo2->info = aux;       
        }else{
            printf("Pos fuera rango\n");
        }

    }else{
        if(L->head == NULL){
			printf("La lista esta vacia\n");
        }else{
        	printf("Misma pos\n");
        }
    }
}

Lista* juntar(Lista *L1, Lista *L2){
    Lista *Laux = crearLista();
    
    Nodo *ptr1 = L1->head;
    while(ptr1 != NULL){
        insertarFin(Laux, ptr1->info);
        ptr1 = ptr1->sig;
    }

    Nodo *ptr2 = L2->head;
    while(ptr2 != NULL){
        insertarFin(Laux, ptr2->info);
        ptr2 = ptr2->sig;
    }

    return Laux;
}

/*Revisa si las listas son iguales*/
int iguales(Lista *L1, Lista *L2){
    Nodo *p1 = L1->head;
    Nodo *p2 = L2->head;

    while(p1 != NULL && p2 != NULL){
        if(p1->info != p2->info){
            return 0; //falso
        }
        p1 = p1->sig; 
        p2 = p2->sig; 
    }

    if(p1 == NULL && p2 == NULL){
        return 1; //verdadero
    }else{
        return 0; 
    }
}


void destruir_lista(Lista *L){
    if(L!=NULL){
        Nodo *actual = L->head;
        Nodo *siguiente;
        while(actual != NULL){
            siguiente = actual->sig;
            free(actual);       
            actual = siguiente;     
        }
        free(L); 
    }
}