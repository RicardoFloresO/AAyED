#include <stdio.h>
#include <stdlib.h>

#include "TDAcontenedor.h"
#include "TDAcarga.h"

/*
Inicializa los valores para un contenedor nuevo e inicializa la listaCarga presente en el contenedor
precond: Recibe el id y la capacidad maxima para el contenedor
postcond: Devuelve el contenedor inicializado con sus valores corrrespondientes
*/
Contenedor crearContenedor(int id, int capMax){
	Contenedor nvoCont;
	nvoCont.id = id;
	nvoCont.capMax = capMax;
	nvoCont.cargas = crearListaCarga();
	nvoCont.capAct = 0;
	nvoCont.capDisp = capMax;
	return nvoCont;
}

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
Elimina el ultimo nodo de la lista
precond: recibe una lista no vacia en la cual se eliminara el ultimo nodo
postcond: elimina el ultimo nodo de la lista y libera la memoria del nodo eliminado
*/
void eliminarContenedorFin(ListaContenedor *L){
	if(isListaContenedorVacia(L) == true){
		printf("La lista esta vacia.\n");
	}else{
		NodoContenedor *ptr = L->head;
		if(ptr->sig == NULL){
			L->head = NULL;
		}else{
			NodoContenedor *ant = NULL;
			while(ptr->sig != NULL){
				ant = ptr;
				ptr = ptr->sig;
			}
			ant->sig = NULL;
		}
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
	if(nodoCont == NULL){
		printf("El contenedor de destino no existe\n");
		return false;
	}else{
		if(cargaInsertar.peso <= nodoCont->conten.capDisp){
			insertarCargaFin(nodoCont->conten.cargas, cargaInsertar);
			nodoCont->conten.capAct = nodoCont->conten.capAct + cargaInsertar.peso;
			nodoCont->conten.capDisp = nodoCont->conten.capMax - nodoCont->conten.capAct;
			return true;
		}else{
			return false;
		}
	}
}

/*
Elimina una carga que esta almacenada en un contenedor en especifico
precond: Recibe el nodo en el cual se eliminara la carga de la lista y la carga a eliminar
postcond: Elimina la carga de la lista en el contenedor y actualiza los pesos
*/
void eliminarCargaContenedor(NodoContenedor *nodoCont, Carga cargaEliminar){
	if(nodoCont != NULL){
		eliminarCargaId(nodoCont->conten.cargas, cargaEliminar.id);
		nodoCont->conten.capAct = nodoCont->conten.capAct - cargaEliminar.peso;
		nodoCont->conten.capDisp = nodoCont->conten.capMax - nodoCont->conten.capAct;
	}
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
		Contenedor copiaCont = ptr->conten;
		copiaCont.cargas = copiarListaCarga(ptr->conten.cargas);
		insertarContenedorFin(Laux, copiaCont);
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
void mostrarListaContenedor(ListaContenedor *L){
	if (isListaContenedorVacia(L) == true) {
        printf("Lista vacia.\n");
    } else {
        NodoContenedor *ptr = L->head;
        while (ptr != NULL) {
            printf("Contenedor %d: ", ptr->conten.id);

            NodoCarga *ptrC = ptr->conten.cargas->head;
            while (ptrC != NULL) {
                printf("c%d", ptrC->carga.id);
                if (ptrC->sig != NULL) {
                    printf(", ");
                }
                ptrC = ptrC->sig;
            }

            printf(" | peso total: %d | espacio disponible: %d\n",
                   ptr->conten.capAct,
                   ptr->conten.capDisp);

            ptr = ptr->sig;
        }
    }
}

/*
obtiene el primer nodo contenedor de la lista
precond: Recibe una lista de contenedores
postcond: Devuelve el puntero al primer nodo de la lista
*/
NodoContenedor* primerNodoContenedor(ListaContenedor *L){
	if(L == NULL){
		return NULL;
	}else{
		return L->head;
	}
}

/*
obtiene el ultimo nodo contenedor de la lista
precond: Recibe una lista de contenedores
postcond: Devuelve el puntero al ultimo nodo de la lista
*/
NodoContenedor* ultimoNodoContenedor(ListaContenedor *L){
    if(L == NULL || L->head == NULL){
        return NULL;
    }else{
        NodoContenedor *ptr = L->head;
        while(ptr->sig != NULL){
            ptr = ptr->sig;
        }
        return ptr;
    }
}
/*
obtiene el nodo contenedor siguiente al actual
precond: Recibe un nodo contenedor
postcond: Devuelve el puntero al siguiente nodo
*/
NodoContenedor* siguienteNodoContenedor(NodoContenedor *N){
	if(N == NULL){
		return NULL;
	}else{
		return N->sig;
	}
}

/*
obtiene el id del contenedor
precond: Recibe un nodo contenedor no vacio
postcond: Devuelve el id del contenedor
*/
int idContenedor(NodoContenedor *N){
	return N->conten.id;
}

/*
obtiene la lista de cargas almacenadas dentro de un contenedor
precond: Recibe un nodo contenedor no vacio
postcond: Devuelve el puntero a la lista en el nodo contenedor
*/
ListaCarga* cargasDeContenedor(NodoContenedor *N){
	return N->conten.cargas;
}

/*
verifica si una carga cabe en el espacio disponible de un contenedor
precond: Recibe un nodo contenedor no vacio y una carga
postcond: Devuelve true si el peso cabe en capDisp, false en caso contrario
*/
bool cabeCarga(NodoContenedor *N, Carga cargaInsertar){
	//Verifica que el nodo no este vacio y que el peso de la carga sea menor o igual al de la capacidad disponible del contenedor
	if(N != NULL && cargaInsertar.peso <= N->conten.capDisp){ 
		return true;
	}else{
		return false;
	}
}

/*
Busca en que contenedor de la lista se encuentra una carga especifica
precond: Recibe una lista de contenedores y el id de la carga buscada
postcond: Devuelve el id del contenedor que la contiene o -1 si no esta
*/
int contenedorDeCarga(ListaContenedor *L, int idCarga){
	NodoContenedor *ptr = L->head;
	while(ptr != NULL){
		if(buscarNodoCargaId(ptr->conten.cargas ,idCarga) != NULL){
			return ptr->conten.id;
		}
		ptr = ptr->sig;
	}
	return -1;
}