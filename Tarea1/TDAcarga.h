#include <stdbool.h>

#ifndef TDACARGA_H
#define TDACARGA_H

/*El TDAcarga esta basado en el TDAlista con algunas modificaciones, 
la idea es generar una lista que pueda almacenar las cargas que se utilizaran,
donde cada nodo en vez de tener un info tendra una carga, esta carga presentará
un id y un peso

Entonces una lista de cargas representara a la zona de acopio o algun contenedor 
con las cargas presentes.
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

//Definicion de las operaciones del TDAcarga

/*
Crea una lista vacia
precond: niguna
postcond: devuelve una ListaCarga vacia
*/
ListaCarga *crearListaCarga();

/*
Verifica si la lista esta vacia
precond: recibe una lista con o sin elementos
postcond: devuelve TRUE si esta vacia o FALSE si no esta vacia
*/
bool isListaCargaVacia(ListaCarga *L);

/*
Crea un nodo que almacena una carga
precond: recibe una carga 
postcond: devuelve un nodo con la carga almacenada
*/
NodoCarga *crearNodoCarga(Carga cargaNueva);

/*
Encuentra el primer nodo de la lista de cargas
precond: Recibe una lista de cargas a la cual se le encontrara el primer nodo
postcond: Devuelve el primer nodo de la lista
*/
NodoCarga* primerNodoCarga(ListaCarga *L);

/*
Encuentra el nodo siguiente al nodo actual
precond: Recibe un nodo al cual se le encontrara cual sera su nodo siguiente
postcond: Devuelve el nodo siguiente del nodo recibido o NULL si es el ultimo nodo de la lista
*/
NodoCarga* siguienteNodoCarga(NodoCarga *N);

/*
Muestra la carga almacenada en el nodo
precond: Recibe un nodo al cual se accedera a la carga
postcond: Devuelve la carga del nodo recibido
*/
Carga cargaNodo(NodoCarga *N);

/*
Inserta una carga al inico de la lista creando un nodo nuevo
precond: recibe la lista donde se insertara y la carga que se inserta
postcond: devuelve la lista con un nodo nuevo que almacena la carga
*/
void insertarCargaInicio(ListaCarga *L, Carga cargaInsertar);

/*
Inserta una carga al final de la lista creando un nodo nuevo
precond: recibe la lista donde se insertara y la carga que se inserta
postcond: devuelve la lista con un nodo nuevo que almacena la carga
*/
void insertarCargaFin(ListaCarga *L, Carga cargaInsertar);

/*
Elimina el primer nodo de la lista
precond: recibe una lista no vacia a la cual se le eliminara el primer nodo
postcond: devuelve la lista sin el primer nodo y libera la memoria del nodo eliminado
*/
void eliminarCargaInicio(ListaCarga *L);

/*
Elimina el ultimo nodo de la lista
precond: recibe una lista no vacia a la cual se le eliminara el ultimo nodo
postcond: devuelve la lista sin el ultimo nodo y libera la memoria del nodo eliminado
*/
void eliminarCargaFin(ListaCarga *L);

/*
Busca un nodo en la lista por su ID
precond: recibe una lista y un ID
postcond: devuelve el nodo si lo encuentra o NULL si no lo encuentra
*/
NodoCarga* buscarNodoCargaId(ListaCarga *L, int idBuscar);

/*
Elimina un nodo de la lista a partir de su ID
precond: recibe una lista y un ID para buscar el NodoCarga a eliminar
postcond: elimina el nodo de la lista y libera la memoria del nodo eliminado, si no se encuentra el ID no hace nada
*/
void eliminarCargaId(ListaCarga *L, int id);

/*
Crea una copia de la lista de cargas para poder trabajar sin alterar la original
precond: recibe una lista de cargas para ser copiada
postcond: devuelve la copia de la lista de cargas
*/
ListaCarga *copiarListaCarga(ListaCarga *L);

/*
Elimina todos los nodos de la lista
precond: recibe una lista de cargas que sera eliminada
postcond: la lista queda vacia, se libera la memoria de todos los nodos
y finalmente de la lista
*/
void destruirListaCarga(ListaCarga *L);

/*
Se mostrara por consola la lista de cargas con su respectivo ID y peso
precond: recibe una lista de cargas que sera mostrada
postcond: muestra por consola los datos de cada carga en la lista
*/
void mostrarListaCarga(ListaCarga *L);

/*
Contara cuantas cargas se presentan en la lista
precond: recibe una lista de cargas
postcond: devuelve el numero total de cargas presentes en la lista
*/
int numCargas(ListaCarga *L);

/*
Sumara los pesos de cada carga presente en la lista
precond: recibe una lista de cargas
postcond: devuelve la suma total de los pesos presentes en la lista de carga
*/
int pesoListaCarga(ListaCarga *L);

#endif