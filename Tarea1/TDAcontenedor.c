#include <stdio.h>
#include <stdlib.h>

#include "TDAcontenedor.h"
#include "TDAcarga.h"

/*
Se crea un nodo que almacena un contenedor
precond: recibe el contenedor que almacena
postcond: devuelve un nodo con un contenedor almacenado
*/
NodoContenedor* crearNodoContenedor(Contenedor contenNuevo){
	NodoContenedor *nodo = malloc(sizeof(NodoContenedor));
	nodo->conten = contenNuevo;
	nodo->sig = NULL;
	return nodo;

}

/*
Crea una lista donde se almacenaran los NodoContenedor
precond: Ninguna
postcond: Devuelve una lista para almacenar contenedores
*/
ListaContenedor *crearListaContenedor(){
	ListaContenedor *L = malloc(sizeof(ListaContenedor));
	L->head = NULL;
	return L;
}

/*
Verifica si la lista contenedor esta vacia
precond: recibe una lista
postcond: devuelve TRUE si esta vacia o FALSE si no esta vacia
*/
bool isListaContenedorVacia(ListaContenedor *L){
	if(L->head == NULL){
		return true;
	}else{
		return false;
	}
}

/*
Inserta un contenedor al final de la lista creando un nodo nuevo
precond: recibe una lista donde se insertara y el contenedor que se inserta
postcond: devuelve al lista con un nodo nuevo que almacena un contenedor
*/
void insertarContenedorFin(ListaContenedor *L, Contenedor conten){
	NodoContenedor *contenInsert = crearNodoContenedor(conten);
	if(L->head == NULL){
		L->head = contenInsert;
	}else{
		NodoContenedor *ptr = L->head;
		while(ptr->sig != NULL){
			ptr = ptr->sig;
		}
		ptr->sig = contenInsert;
	}
}

/*
Elimina el primer nodo de la lista
precond: recibe una lista no vacia a la cual sele eliminara el primer nodo
postcond: devuelve la lista sin el primer nodo y libera la memoria del nodo eliminado
*/
void eliminarContenedorInicio(ListaContenedor *L){
	if(isListaContenedorVacia(L) == true){
		printf("La lista esta vacia.\n");
	}else{
		NodoContenedor *ptr = L->head;
		L->head = ptr->sig;
		ptr->sig = NULL;
		destruirListaCarga(ptr->conten.cargas);
		free(ptr);
	}
}

/*
Contara cuantos contenedores hay presentes en la lista
precond: recibe una lista de contenedores
postcond: devuelve el numero total de contenedores presentes en la lista
*/
int numContenedores(ListaContenedor *L){
	int contador = 0;
	NodoContenedor *ptr = L->head;
	while(ptr != NULL){
		contador++;
		ptr = ptr->sig;
	}
	return contador;
}

/*
Agrega una carga al contenedor seleccionado, verificando que la capacidad
disponible sea suficiente para poder almacenar dicha carga
precond: Recibe el nodo en el cual se agregara la carga y la carga
postcond: devuelve true si fue posible agregar la carga y false si no fue posible
*/
bool agregarCargaContenedor(NodoContenedor *nodoCont, Carga cargaInsertar){
	
}

/*
Crea una copia de la lista contenedor para poder trabajar sin alterar la original
precond: Recibe la lista que sera copiada
postcond: Devuelve la copia de la lista de contenedores
*/
ListaContenedor* copiarListaContenedor(ListaContenedor *L){
	ListaContenedor *Laux = crearListaContenedor();
	NodoContenedor *ptr = L->head;
	while(ptr != NULL){
		insertarContenedorFin(Laux, ptr->conten);
		ptr = ptr->sig;
	}
	return Laux;
}

/*
Elimina todos los nodos de la lista
precond: Recibe la lista a eliminar
postcond: la lista queda vacia, se libera la memoria de todos los nodos
y finalmente de la lista
*/
void destruirListaContenedor(ListaContenedor *L){
	if(L != NULL){
		while(isListaContenedorVacia(L) != true){
			eliminarContenedorInicio(L);
		}
		free(L);
	}
}

/*
Se mostrara por consola la lista de contenedores
precond: recibe una lista de contenedores que sera mostrada
postcond: muestra por consola los datos de cada contenedor en la lista
*/
void mostrarListaContenedor(ListaContenedor *L);