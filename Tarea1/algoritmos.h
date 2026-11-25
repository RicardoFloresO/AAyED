#include "TDAcarga.h"
#include "TDAcontenedor.h"

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
ListaContenedor* heuristica(ListaCarga *Acopio, int capMax);