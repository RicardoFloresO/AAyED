
/* Programa que define e implementa el TDA Lista simplemente enlazada
TDAlista.h */

//(I): ESTRUCTURA DE DATOS 
struct nodo{
  int info;
  struct nodo *sig;
};
typedef struct nodo Nodo; 

struct lista{
  Nodo *head;
};
typedef struct lista Lista; 

//ENCABEZADO DE LAS OPERACIONES  
Lista* crearLista();
bool isListaVacia(Lista *L);
Nodo* crearNodo(int val);
void insertarInicio(Lista *L, int val); 
void insertarFin(Lista *L, int val); 
void mostrarLista(Lista *L);
Lista* crearInsertarLista_desde_archivo(char *nom_archivo);
void eliminarInicio(Lista *L);
void destruirLista(Lista *L);

//IMPLEMENTACIÓN DE LAS OPERACIONES  

Lista* crearLista(){
	Lista *L = malloc(sizeof(Lista));
  	L->head = NULL;
	return L;
}

bool isListaVacia(Lista *L){
	if(L->head == NULL)
		return true;  
	else
		return false;
}

Nodo* crearNodo(int val){
	Nodo *N;
	N = malloc(sizeof(Nodo));
	N->info = val;
    N->sig = NULL;	
    return N;
}

void insertarInicio(Lista *L, int val){
	Nodo *nvo = crearNodo(val);
	if (!(isListaVacia(L))){ 
		nvo -> sig = L -> head;
	}
	L -> head = nvo;
}

void insertarFin(Lista *L, int val){
	Nodo *nvo = crearNodo(val);
	if (L->head == NULL){
		L->head = nvo;
	}else{
		Nodo *ptr = L->head;
		while (ptr->sig != NULL){
			ptr = ptr->sig;
		}
		ptr->sig = nvo;
	}
}
void mostrarLista(Lista *L){
	if (!(isListaVacia(L))){ 
	    Nodo *ptr = L -> head;
	    while(ptr != NULL){
		    printf("  %d", ptr -> info);
		    ptr = ptr -> sig;
	    }
		printf("\n");
	}else{
		printf("\n Lista Vacia \n");
    }
}



Lista* crearInsertarLista_desde_archivo(char *nom_archivo){
	int n, val;
	FILE *fp = fopen(nom_archivo, "r");
	if (fp==NULL){
		return NULL;
	}	
	Lista *lis=crearLista();
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++){
		fscanf(fp, "%d", &val);
		insertarFin(lis, val);
	}
	fclose(fp);	
	return lis;
}


void eliminarInicio(Lista *L){
	if (isListaVacia(L)){
		printf("\n Lista Vacia \n");
	}else{
		Nodo *ptr = L->head; 
		L->head = ptr->sig; //L->head->sig; 
		ptr->sig = NULL;
		free (ptr) ; 
	}
}

void destruirLista(Lista *L){
	if (!isListaVacia(L)){
		while (L->head != NULL){
			eliminarInicio(L);
		}
	}	
}
