#include <stdio.h>
#include <stdlib.h>

int buscarSub(char *c,char *s,int n,int m){
	for(int i=0;i<n-m+1;i++){
		//printf("aa\n");
		int j = 0;
		//printf("c->%d\n", c[i]);
		while(j<m && s[j]==c[i+j]){
			printf("c->%c\n", c[i+j]);
			printf("s->%c\n", s[j]);
			j = j+1;
		}
		if(j==m){
			return i;
		}
	}
	return -1;
}

int main(){
	char *c = "PARALELEPIPEDO";
	char *s = "LEPI";
	int n = 14;
	int m = 4;

	int id = buscarSub(c,s,n,m);

	printf("->%d\n",id);
	return 0;
}	