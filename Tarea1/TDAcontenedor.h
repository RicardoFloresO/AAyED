#include <stdbool.h>
/*Se importa el TDAcarga, ya que se utilizara para poder crear una lista de cargas
en cada contenedor.*/
#include "TDAcarga.h"

#ifndef TDACONTENEDOR_H
#define TDACONTENEDOR_H
/*Al igual que el TDAcarga, este TDAcontenedor se basa en el TDAlista con el fin
de almacenar todos los contenedores que se vayan generando.

*/

/*Primero se define el struct contenedor, el cual tendra el id la capacidad maxima,
las cargas que estaran dentro de el, la capacidad actual y disponible*/
struct contenedor{
	int id;
	int capMax;
	ListaCarga *cargas;
	int capAct;
	int capDisp;
};
typedef struct contenedor Contenedor;

//El nodo contenedor almacenara el contenedor
struct nodoContenedor{
	Contenedor conten;
	struct nodoContenedor *sig;
};
typedef struct nodoContenedor NodoContenedor;

//Mismo proceso que usamos para la lista carga, pero esta vez con contenedores
struct listaContenedor{
	NodoContenedor *head;
};
typedef struct listaContenedor ListaContenedor;

//Definicion de las operaciones del TDAcontenedor

/*
Inicializa los valores para un contenedor nuevo e inicializa la listaCarga presente en el contenedor
precond: Recibe el id y la capacidad maxima para el contenedor
postcond: Devuelve el contenedor inicializado con sus valores corrrespondientes
*/
Contenedor crearContenedor(int id, int capMax);

/*
Se crea un nodo que almacena un contenedor
precond: recibe el contenedor que almacena
postcond: devuelve un nodo con un contenedor almacenado
*/
NodoContenedor* crearNodoContenedor(Contenedor conten);

/*
Crea una lista donde se almacenaran los NodoContenedor
precond: Ninguna
postcond: Devuelve una lista para almacenar contenedores
*/
ListaContenedor *crearListaContenedor();

/*
Verifica si la lista contenedor esta vacia
precond: recibe una lista
postcond: devuelve TRUE si esta vacia o FALSE si no esta vacia
*/
bool isListaContenedorVacia(ListaContenedor *L);

/*
Inserta un contenedor al final de la lista creando un nodo nuevo
precond: recibe una lista donde se insertara y el contenedor que se inserta
postcond: agrega el nodo al final de la lista
*/
void insertarContenedorFin(ListaContenedor *L, Contenedor conten);

/*
Elimina el primer nodo de la lista
precond: recibe una lista no vacia a la cual sele eliminara el primer nodo
postcond: elimina el primer nodo de la lista y libera la memoria del nodo eliminado
*/
void eliminarContenedorInicio(ListaContenedor *L);

/*
Elimina el ultimo nodo de la lista
precond: recibe una lista no vacia en la cual se eliminara el ultimo nodo
postcond: elimina el ultimo nodo de la lista y libera la memoria del nodo eliminado
*/
void eliminarContenedorFin(ListaContenedor *L);

/*
Contara cuantos contenedores hay presentes en la lista
precond: recibe una lista de contenedores
postcond: devuelve el numero total de contenedores presentes en la lista
*/
int numContenedores(ListaContenedor *L);

/*
Agrega una carga al contenedor seleccionado, verificando que la capacidad
disponible sea suficiente para poder almacenar dicha carga
precond: Recibe el nodo en el cual se agregara la carga y la carga
postcond: devuelve true si fue posible agregar la carga y false si no fue posible
*/
bool agregarCargaContenedor(NodoContenedor *nodoCont, Carga cargaInsertar);

/*
Elimina una carga que esta almacenada en un contenedor en especifico
precond: Recibe el nodo en el cual se eliminara la carga de la lista y la carga a eliminar
postcond: Elimina la carga de la lista en el contenedor y actualiza los pesos
*/
void eliminarCargaContenedor(NodoContenedor *nodoCont, Carga cargaEliminar);

/*
Crea una copia de la lista contenedor para poder trabajar sin alterar la original
precond: Recibe la lista que sera copiada
postcond: Devuelve la copia de la lista de contenedores
*/
ListaContenedor* copiarListaContenedor(ListaContenedor *L);

/*
Elimina todos los nodos de la lista
precond: Recibe la lista a eliminar
postcond: la lista queda vacia, se libera la memoria de todos los nodos
y finalmente de la lista
*/
void destruirListaContenedor(ListaContenedor *L);

/*
Se mostrara por consola la lista de contenedores
precond: recibe una lista de contenedores que sera mostrada
postcond: muestra por consola los datos de cada contenedor en la lista
*/
void mostrarListaContenedor(ListaContenedor *L);
#endif