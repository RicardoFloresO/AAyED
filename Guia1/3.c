#include <stdio.h>
#include <stdlib.h>

int contar(int A[], int B[], int n, int m){
	int contador = 0;
	for(int i = 0;i<n;i++){
		//printf("for->%d A[%d]->%d\n",i,i,A[i]);
		int j =0;
		while(j<m){
			//printf("while->%d B[%d]->%d\n",j,j,B[j]);
			if(A[i]==B[j]){
				contador = contador + 1;
				//printf("cont->%d\n",contador);
				j = m; //se fuerza la condicion de borde para que el ciclo pare
			}
		j=j+1;	
		//printf("j->%d\n",j);
		}
	}
	return contador;
}

int main(){
	int A[] = {1,2,3,4,5};
	int B[] = {2,5,6,7};
	int n=5;
	int m=4;

	int cont = contar(A,B,n,m);
	printf("->%d\n",cont);


	return 0;
}