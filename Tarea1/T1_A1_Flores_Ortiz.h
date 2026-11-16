#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definicion de las estructuras de datos a usar

/*Se tendra que usar una lista para almacenar las cargas en un contenedor y
luego se usara otra lista para almacenar los contenedores individuales
esto buscando simular una lista de lista
*/

/*En primera instancia se definirá una lista para almacenar cargas, 
la cual llamaremos TDAcarga que esta basado en el TDA lista con algunos ajustes
*/

//El struct carga almacenará el id y el peso de cada carga
struct carga{
	int id;
	int peso;
};
typedef struct carga Carga;

//Tendremos un NodoCarga el cual en vez de tener un info tendra una carga con 
//sus respectivos datos
struct nodoCarga{
	Carga carga;
	struct nodoCarga *sig;
};
typedef struct nodoCarga NodoCarga;

//ListaCarga tendra el mismo comportamiento que un TDA lista comun, la diferencia
//es que cada nodo estara asociado a una carga
struct listaCarga{
	NodoCarga *head;
};
typedef struct listaCarga ListaCarga;


/*Seguiremos el mismo procedimiento para crear un TDAlista para los contenedores,
el cual por conveniencia nombraremos TDAcontenedor*/

//Primero se define el struct contenedor, el cual tendra el id la capacidad maxima,
//las cargas que estaran dentro de el, la capacidad actual y disponible
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
	Contenedor contenedor;
	struct nodoContenedor *sig;
};
typedef struct nodoContenedor NodoContenedor;

//Mismo proceso que usamos para la lista carga, pero esta vez con contenedores
struct listaContenedor{
	NodoContenedor *head;
};
typedef struct listaContenedor ListaContenedor;

//Definicion de las funciones de los TDA

//Implementacion de las funciones de los TDA