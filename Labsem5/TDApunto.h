#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Se crea estructura para la posicion del punto
struct reg_punto{
	int coord_x;
	int coord_y;

};
typedef struct reg_punto Punto;

//Se declaran las operaciones del TDApunto
Punto* crea_punto(int x, int y);
void mostrar_punto(Punto *A);
int calcula_distancia(Punto *A, Punto *B);
int distancia_origen(Punto *A);
int cuadrante(Punto *A);
void desplazar(Punto *A, int dx, int dy);
int esta_en_eje(Punto *A);

//Se implementan las operaciones del TDApunto
Punto* crea_punto(int x, int y){
	Punto *p = malloc(sizeof(Punto));
	p->coord_x = x;
	p->coord_y = y;
	return p;
}

void mostrar_punto(Punto *A){
	printf("El punto se encuentra en (%d,%d)\n",A->coord_x,A->coord_y);	
}

int calcula_distancia(Punto *A, Punto *B){
	int Ax = A->coord_x;
	int Ay = A->coord_y;
	int Bx = B->coord_x;
	int By = B->coord_y;
	int dx = (Ax-Bx);
	int dy = (Ay-By);
	int dist = sqrt(dx*dx+dy*dy);
	return dist;
}

int distancia_origen(Punto *A){
	Punto *origen = crea_punto(0,0);
	int dist =calcula_distancia(origen,A);
	return dist;
}

int cuadrante(Punto *A){
	int Ax = A->coord_x;
	int Ay = A->coord_y;
	int cuad;
	if(Ax > 0 && Ay>0){
		cuad = 1;
	}else if(Ax<0 && Ay>0){
		cuad = 2;
	}else if(Ax<0 && Ay<0){
		cuad = 3;
	}else if(Ax>0 && Ay<0){
		cuad = 4;
	}
	return cuad;
}

void desplazar(Punto *A, int dx, int dy){
	A->coord_x = A->coord_x+dx;
	A->coord_y = A->coord_y+dy;
}

int esta_en_eje(Punto *A){
	int x = A->coord_x;
	int y = A->coord_y;
	if(A->coord_x==0 || A->coord_y==0){
		//printf("Punto P1 SI esta en uno de los ejes");
		return 1;
	}else{
		//printf("Punto P1 NO esta en uno de los ejes");
		return 0;
	}
}

