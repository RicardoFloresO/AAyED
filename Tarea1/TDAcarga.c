#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "TDAcarga.h"

ListaCarga *crearListaCarga(){
	ListaCarga *L = malloc(sizeof(ListaCarga));
	L->head = NULL;
	return L;
}

/*
Verifica si la lista esta vacia
precond: recibe una lista con o sin elementos
postcond: devuelve TRUE si esta vacia o FALSE si no esta vacia
*/
bool isListaCargaVacia(ListaCarga *L){
	if(L->head == NULL){
		return true;
	}else{
		return false;
	}
}

/*
Crea un nodo que almacena una carga
precond: recibe una carga 
postcond: devuelve un nodo con la carga almacenada
*/
NodoCarga *crearNodoCarga(Carga cargaNueva){
	NodoCarga *Ncarga;
	Ncarga = malloc(sizeof(NodoCarga));
	Ncarga->carga = cargaNueva;
	Ncarga->sig = NULL;
	return Ncarga;
}

/*
Inserta una carga al inico de la lista creando un nodo nuevo
precond: recibe la lista donde se insertara y la carga que se inserta
postcond: devuelve la lista con un nodo nuevo que almacena la carga
*/
void insertarCargaInicio(ListaCarga *L, Carga cargaInsertar){
	NodoCarga *nvoNodo = crearNodoCarga(cargaInsertar);
	if(isListaCargaVacia(L) == false){
		nvoNodo->sig = L->head;
	}
	L->head = nvoNodo;
}

/*
Inserta una carga al final de la lista creando un nodo nuevo
precond: recibe la lista donde se insertara y la carga que se inserta
postcond: devuelve la lista con un nodo nuevo que almacena la carga
*/
void insertarCargaFin(ListaCarga *L, Carga cargaInsertar){
	NodoCarga *nvoNodo = crearNodoCarga(cargaInsertar);
	if(L->head == NULL){
		L->head = nvoNodo;
	}else{
		NodoCarga *ptr = L->head;
		while(ptr->sig != NULL){
			ptr = ptr->sig;
		}
		ptr->sig = nvoNodo;
	}
}
/*
Elimina el primer nodo de la lista
precond: recibe una lista no vacia a la cual se le eliminara el primer nodo
postcond: devuelve la lista sin el primer nodo y libera la memoria 
del nodo eliminado
*/
void eliminarCargaInicio(ListaCarga *L){
	if(isListaCargaVacia(L) == true){
		printf("Lista de carga vacia.\n");
	}else{
		NodoCarga *ptr = L->head;
		L->head = ptr->sig;
		ptr->sig = NULL;
		free(ptr);
	}
}

/*
Elimina el ultimo nodo de la lista
precond: recibe una lista no vacia a la cual se le eliminara el ultimo nodo
postcond: devuelve la lista sin el ultimo nodo y libera la memoria 
del nodo eliminado
*/
void eliminarCargaFin(ListaCarga *L){
	if(isListaCargaVacia(L) == true){
		printf("Lista de carga vacia.\n");
	}else{
		NodoCarga *ptr = L->head;
		if(ptr->sig == NULL){
			L->head = NULL;
		}else{
			NodoCarga *ant = NULL;
			while(ptr->sig != NULL){
				ant = ptr;
				ptr = ptr->sig;
			}
			ant->sig = NULL;
		}
		free(ptr);
	}
}
/*
Busca un nodo en la lista por su ID
precond: recibe una lista y un ID
postcond: devuelve el nodo si lo encuentra o NULL si no lo encuentra
*/
NodoCarga* buscarNodoCargaId(ListaCarga *L, int idBuscar){
	NodoCarga *ptr = L->head;
	while(ptr!=NULL){
		if(ptr->carga.id == idBuscar){
			return ptr;
		}
		ptr=ptr->sig;
	}
	return NULL;
}

/*
Elimina un nodo de la lista a partir de su ID
precond: recibe una lista y un ID para buscar el NodoCarga a eliminar
postcond: elimina el nodo de la lista y libera la memoria del nodo eliminado, 
si no se encuentra el ID no hace nada
*/
void eliminarCargaId(ListaCarga *L, int idEliminar){
	if(L->head == NULL){
		printf("Lista vacia\n");
	}else{
		NodoCarga *ptrEliminar = buscarNodoCargaId(L,idEliminar);
		if(ptrEliminar != NULL){
			if(ptrEliminar == L->head){
				eliminarCargaInicio(L);
			}else{
				if(ptrEliminar->sig == NULL){
					eliminarCargaFin(L);
				}else{
					NodoCarga *ant = L->head;
					while(ant->sig != ptrEliminar){
						ant = ant->sig;
					}
					ant->sig = ptrEliminar->sig;
					ptrEliminar->sig = NULL;
					free(ptrEliminar);
				}
			}
		}
	}
}

/*
Crea una copia de la lista de cargas para poder trabajar sin alterar la original
precond: recibe una lista de cargas para ser copiada
postcond: devuelve la copia de la lista de cargas
*/
ListaCarga *copiarListaCarga(ListaCarga *L){
	ListaCarga *Laux = crearListaCarga();
	NodoCarga *ptr = L->head;
	while(ptr != NULL){
		//NodoCarga *aux = crearNodoCarga(ptr->carga);
		insertarCargaFin(Laux,ptr->carga);
		ptr = ptr->sig;
	}
	return Laux;
}

/*
Elimina todos los nodos de la lista
precond: recibe una lista de cargas que sera eliminada
postcond: la lista queda vacia, se libera la memoria de todos los nodos
y finalmente de la lista
*/
void destruirListaCarga(ListaCarga *L){
	if(L != NULL){
		while(isListaCargaVacia(L) != true){
			eliminarCargaInicio(L);
		}
		free(L);
	}
}

/*
Se mostrara por consola la lista de cargas con su respectivo ID y peso
precond: recibe una lista de cargas que sera mostrada
postcond: muestra por consola los datos de cada carga en la lista
*/
void mostrarListaCarga(ListaCarga *L){
	if(L->head == NULL){
		printf("vacia\n");
	}else{
		NodoCarga *ptr = L->head;
		while(ptr != NULL){
			printf("c%d (%d) -> ",ptr->carga.id , ptr->carga.peso);
			ptr = ptr->sig;
		}
		printf("NULL\n");
	}
}

/*
Contara cuantas cargas se presentan en la lista
precond: recibe una lista de cargas
postcond: devuelve el numero total de cargas presentes en la lista
*/
int numCargas(ListaCarga *L){
	int cont = 0;
	NodoCarga *ptr = L->head;
	while(ptr != NULL){
		cont++;
		ptr = ptr->sig;
	}
	return cont;
}

/*
Sumara los pesos de cada carga presente en la lista
precond: recibe una lista de cargas
postcond: devuelve la suma total de los pesos presentes en la lista de carga
*/
int pesoListaCarga(ListaCarga *L){
	int pesoTot =0;
	NodoCarga *ptr = L->head;
	while(ptr != NULL){
		pesoTot = pesoTot + ptr->carga.peso;
		ptr = ptr->sig;
	}
	return pesoTot;
}

/*
Encuentra el primer nodo de la lista de cargas
precond: Recibe una lista de cargas a la cual se le encontrara el primer nodo
postcond: Devuelve el primer nodo de la lista
*/
NodoCarga* primerNodoCarga(ListaCarga *L){
	if(L == NULL){
		printf("La lista esta vacia.\n");
		return NULL;
	}else{
		return L->head;
	}
}

/*
Se mueve al nodo siguiente de la lista
precond: Recibe un nodo al cual se le encontrara cual sera su nodo siguiente
postcond: Devuelve el nodo siguiente del nodo recibido o NULL si es el ultimo nodo de la lista
*/
NodoCarga* siguienteNodoCarga(NodoCarga *N){
	if(N == NULL){
		return NULL;
	}else{
		return N->sig;
	}
}

/*
Muestra la carga almacenada en el nodo
precond: Recibe un nodo al cual se accedera a la carga
postcond: Devuelve la carga del nodo recibido
*/
Carga cargaNodo(NodoCarga *N){
	return N->carga;
}