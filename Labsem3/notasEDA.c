#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define num_notas 3

struct notas_EDA{
	int id_alum;
	int num_notass;
	float *peps;
	float *contrs;
};

typedef struct notas_EDA notasEDA;

notasEDA ingresar_notas(int idalum){
	notasEDA E;
	E.id_alum = idalum;
	E.num_notass = num_notas;
	
	E.peps = malloc(num_notas * sizeof(float));
	E.contrs = malloc(num_notas * sizeof(float));

	for(int i=0; i<num_notas; i++){
		printf("Ingrese la nota de pep %d: ",i+1);
		scanf("%f", &E.peps[i]);
	}
	for(int i=0; i<num_notas; i++){
		printf("Ingrese la nota del control %d: ",i+1);
		scanf("%f", &E.contrs[i]);
	}

	//Escribir archivo
	FILE *fp = fopen("salida.txt","w");

	fprintf(fp,"%d,2,%d\n",E.id_alum, num_notas);

	for(int i=0; i<num_notas;i++){
		fprintf(fp, "%.2f ", E.peps[i]);
	}
	fprintf(fp, "\n");

	for(int i=0;i<num_notas;i++){
		fprintf(fp, "%.2f ", E.contrs[i]);
	}
	fprintf(fp, "\n");

	fclose(fp);
	return E;
}

notasEDA leer_notas_salida(){
	notasEDA E;

	FILE *fp = fopen("salida.txt","r");
	if(fp==NULL){
		printf("\n Archivo no existe \n");
		exit(1);
	}
	fscanf(fp, "%d,%*d,%d",&E.id_alum,&E.num_notass);

	E.peps = malloc(E.num_notass * sizeof(float));
	E.contrs = malloc(E.num_notass * sizeof(float));

	for(int i=0; i < E.num_notass;i++){
		fscanf(fp, "%f",&E.peps[i]);
	}
	for(int i=0; i < E.num_notass;i++){
		fscanf(fp, "%f",&E.contrs[i]);
	}
	fclose(fp);
	return E;
}

void rendimiento(notasEDA E){
	float suma_pep = 0;
	float suma_control = 0;

	float peor_pep = E.peps[0];
	float mejor_control = E.contrs[0];

	for(int i=0;i<E.num_notass; i++){
		suma_pep = suma_pep + E.peps[i];
		if(E.peps[i]<peor_pep){
			peor_pep = E.peps[i];
		}
		suma_control = suma_control + E.contrs[i];
		if(E.contrs[i]>mejor_control){
			mejor_control = E.contrs[i];
		}
	}
	//promedios
	float prom_peps = suma_pep/E.num_notass;
	float prom_controles = suma_control/E.num_notass;

	printf("La peor PEP es %.2f y el promedio es %.2f\n",peor_pep,prom_peps);
	printf("El mejor control es %.2f y el promedio es %.2f\n",mejor_control,prom_controles);

}

int main(){
	int id_estudiante;

	printf("Ingrese id estudiante: \n");
	scanf("%d", &id_estudiante);

	notasEDA registro_alumno = ingresar_notas(id_estudiante);

	notasEDA notas = leer_notas_salida();
	rendimiento(notas);

	free(registro_alumno.peps);
	free(registro_alumno.contrs);
	free(notas.peps);
	free(notas.contrs);

	return 0;
}