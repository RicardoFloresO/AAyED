/* Archivo TDApila.h
   Define la ESTRUCTURA DE DATOS y las operaciones del TDA PILA para desarrollar la guia_lab_semana6 */
struct reg_nodo_pila{
  int info;
  struct reg_nodo_pila *sig;
};
typedef struct reg_nodo_pila Nodop;

struct reg_pila{
  Nodop *top;
};
typedef struct reg_pila Pila;

//ENCABEZADOS DE LAS OPERACIONES
Pila* crearPila();
bool isEmptyPila(Pila *P);
Nodop* crearNodoPila(int val);
void push(Pila *P, int val);
Nodop* pop(Pila *P);
Nodop* tope(Pila *P); 
Pila* crearInsertarPila_desde_archivo(char *nom_archivo);
void destruirPila(Pila *P);

// IMPLEMENTACIÓN OPERACIONES
Pila *crearPila(){
  Pila *P;
  P = malloc(sizeof(Pila));
  P->top = NULL;
  return P;
}

bool isEmptyPila(Pila *P){
  if(P->top == NULL){
    return true;  //pila vacía
  }else{
    return false;
  }
}

Nodop* crearNodoPila(int val){
  Nodop *nvo;
  nvo = malloc(sizeof(Nodop));
  nvo->sig = NULL;
  nvo->info = val;
  return nvo;
}

void push(Pila *P, int val){
	Nodop *Np = crearNodoPila(val);
	if (!isEmptyPila(P)){
		Np->sig = P->top;
	}
	P->top = Np;
}

Nodop* pop(Pila *P){
	if (!isEmptyPila(P)){
	  	Nodop *ptr = P->top;
	  	P->top = ptr->sig; 
	  	ptr->sig = NULL;
    	return ptr;
  	}
  return NULL;
}

Nodop* tope(Pila *P){
  return P->top;
}

Pila* crearInsertarPila_desde_archivo(char *nom_archivo){
	int n, val;
	FILE *fp = fopen(nom_archivo, "r");
	if (fp==NULL){
		return NULL;
	}	
	Pila *pila=crearPila();
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++){
		fscanf(fp, "%d", &val);
		push(pila, val);
	}
	fclose(fp);	
	return pila;
}

void destruirPila(Pila *P){
	if (!isEmptyPila(P)){
		while (P->top != NULL){
			pop(P);
		}
	}	
}