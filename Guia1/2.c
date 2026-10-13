#include <stdio.h>
#include <stdlib.h>

void criba(int n){
	int primos[n];
	int i = 2;
	while(i<n){
		primos[i] = 0;
		i++;
	}
	i = 2;
	while(i<n){
		if(primos[i]==0){
			int j = i*2;
			while(j<n){
				primos[j] =1;
				j+=i;
			}
		}
		i++;
	}
	i=2;
	int cant=0;
	while(i<n){
		if(primos[i]==0){
			printf("%d\n",i);
			cant++;
		}
		i++;
	}

	printf("->%d\n",cant);
}

int main(){
	int n;
	printf("Ingrese un numero: \n");
	scanf("%d",&n);	

	criba(n);
	printf("n->%d",n);

	return 0;
}