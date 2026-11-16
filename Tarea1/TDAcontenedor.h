/*Al igual que el TDAcarga, este TDAcontenedor se basa en el TDAlista con el fin
de almacenar todos los contenedores que se vayan generando.

Se importa el TDAcarga, ya que se utilizara para poder crear una lista de cargas
en cada contenedor.*/
#include "TDAcarga.h"

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

//Definicion de las operaciones del TDAcontenedor
