#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definicion de las estructuras de datos a usar
//Para le resolucion se usara el TDA lista como base

//struct Carga tendra la funcion del nodo
struct carga{
	int id;
	int peso;
};
typedef struct carga Carga;

struct contenedor{
	int id;
	int capMax;
	Carga carga;
	int capAct;
	int capDisp;
};
typedef struct contenedor Contenedor;

