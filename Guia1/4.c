#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Josefo(int n, int m){
	int A[n];
	for(int i=0;i<n;i++){
		A[i]=0;
	}
	int vivos = n;
	int pos =0;
	while(vivos>1){
		int aux=0;
		while(aux<m){
			if(A[pos]==0){
				aux=aux+1;
				if(aux ==m){
					A[pos]=1;
					vivos = vivos-1;
				}
			}
		pos = (pos+1)%9;
		}
	}

	/*for(int i=0;i<n;i++){
		printf("A[i]->%d\n",A[i]);
	}*/

	int lider=0;
	for(int i =0;i<n;i++){
		if(A[i]==0){
			lider =i+1;
		}
	}
	return lider;
	
	
}

int main(){
	int n =9;
	int m=5;

	int res=Josefo(n,m);
	printf("->%d\n",res );

	return 0;
}