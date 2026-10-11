#include <stdio.h>
#include <stdlib.h>

int buscarSub(char *c,char *s,int n,int m){
	for(int i=0;i<n-m+1;i++){
		//printf("aa\n");
		int j = 0;
		//printf("c->%d\n", c[i]);
		while(j<m && s[j+1]==c[i+j]){
			printf("c->%d\n", c[i+j]);
			printf("s->%d\n", s[j+1]);
			j = j+1;
		}
		if(j==m){
			return i;
		}
	}
	return -1;
}

int main(){
	char *c = "DICCIONARIO";
	char *s = "ION";
	int n = 11;
	int m = 3;

	int id = buscarSub(c,s,n,m);

	printf("%d\n",id);
	return 0;
}	