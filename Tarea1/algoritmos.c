#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "algoritmos.h"

/*
Aplica el algoritmo de asignacion exacto para encontrar la menor cantidad de contenedores posible
precond: Recibe la zona de acopio de donde se sacaran las cargas para ser asignadas y la 
capacidad maxima que tendran los contenedores
postcond: Devuelve una lista de contenedores con la distribucion
optima de cargas en los contenedores
*/
ListaContenedor* exacto(ListaCarga *Acopio, int capMax);

/*
Aplica la heuristica para asignar de manera eficiente una posible solucion optima
precond: Recibe la zona de acopio de donde se sacaran las cargas para ser asignadas y la
capacidad maxima que tendran los contenedores
postcond: Devuelve una lista de contenedores con una posible distribucion 
optima de cargas en los contenedores
*/

/*La idea principal es aplicar una heuristica de un algoritmo voraz, el cual encontrara una solucion buena pero no la mas optima aunque
en el algunos casos puede coincidir, funcionara de tal manera que se creara una copia de la zona de acopio, se creara una lista donde 
se almacenaran los contenedores que se ocuparan para llenar, luego se ira buscando la carga de mayor peso y se incertara en el contenedor
que tenga capacidad para almacenarlo, luego se tomara la segunda carga de mayor peso y se buscara un contenedor donde quepa, en caso de 
no caber en ningun contenedor creado, se creara un nuevo contenedor, esto se repetira sucesivamente hasta agregar las cargas de menor peso.

->El algoritmo voraz trabaja de tal manera 
*/
ListaContenedor* heuristica(ListaCarga *Acopio, int capMax){
	//Se crea una copia de la zona de acopio
	ListaCarga *Laux = copiarListaCarga(Acopio);

	//Se crea un lista de contenedores donde se almacenaran los contenedores que recibiran las cargas
	ListaContenedor *Contenedores = crearListaContenedor();
	int ids = 1; //Contador para asignar ids a los contenedores

	//Se ejecuta siempre y cuando la lista no este vacia
	while(isListaCargaVacia(Laux) == false){
		NodoCarga *ptrCarga = primerNodoCarga(Laux); //apuntador que marca el nodo que se usara para ir recorriendo la lista de carga
		Carga cargaMayor = cargaNodo(ptrCarga); //carga que se encontraba dentro del nodo ptr se asigna como la mayor
		//Busca la carga con el mayor peso mientras el nodo que tiene la carga no sea null
		while(ptrCarga != NULL){
			//evalua si la carga del nodo actual es mayor que la cargaMayor, de ser asi se actualiza la cargaMayor y el
			//apuntador pasa al nodo siguiente, en caso contrario solo se pasa al nodo siguiente
			if(cargaNodo(ptrCarga).peso > cargaMayor.peso){ 
				cargaMayor = cargaNodo(ptrCarga);
				ptrCarga = siguienteNodoCarga(ptrCarga);
				//printf("%d\n",cargaMayor.peso );
			}else{
				ptrCarga = siguienteNodoCarga(ptrCarga);
				//printf("%d\n",cargaMayor.peso );
			}
		}
		//printf("%d\n",cargaMayor.peso);
		bool flag = false; //bandera para ver si una carga cabe dentro de un contenedor o no
		NodoContenedor *ptrCont = primerNodoContenedor(Contenedores); //apuntador que marca el nodo que se usara para ir recorriendo la lista de contenedores
		//Verifica que exista un contenedor donde agregar la carga y que se pueda agregar la carga mediante el uso de bandera
		while(ptrCont != NULL && flag == false){
			//si la carga cabe en el contenedor que muestra ptrCont devuelve true y la agrega
			if(agregarCargaContenedor(ptrCont, cargaMayor) == true){
				//printf("Agrega carga %d(%d).\n",cargaMayor.id,cargaMayor.peso);
				flag = true; //la bandera cambia a true indicando que se pudo agregar la carga
			}else{ //en caso contrario se pasa el apuntador al nodo contenedor siguiente
				ptrCont = siguienteNodoContenedor(ptrCont);
			}
		}

		//en caso de que no se pueda agregar la carga quiere decir que hay que crear un nuevo contenedor
		if(flag == false){
			Contenedor nvo = crearContenedor(ids,capMax);
			ids++;
			insertarContenedorFin(Contenedores,nvo);
			agregarCargaContenedor(ultimoNodoContenedor(Contenedores), cargaMayor);
			//printf("Agrega carga %d(%d).\n",cargaMayor.id,cargaMayor.peso);		
		}

		eliminarCargaId(Laux,cargaMayor.id);	
	}

	destruirListaCarga(Laux);
	return Contenedores;
}