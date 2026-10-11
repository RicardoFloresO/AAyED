/*Pseudocodigo:
1. Dados dos enteros muestre el menor
int a 
int b
if a<b
	print("a es menor")
else
	print("b es menor")


2. Suma de dos numeros enteros
int a
int b
int suma

suma = a+b
print("La suma es suma")

3.Suma de los primeros n numeros enteros
int a
int b
int suma
suma = a*(a+1)/2
print("La suma de los primeros n numeros es: suma")

4. Dados dos numeros enteros a y b, retorne el valor de a^b
int a
int b
int pot
int i

pot = a
while i<b:
	pot = pot*a
	i=i+1

5. Dado un arreglo A de n numeros, muestre el menor elemento del arreglo
int sacar_menor
*/

#include <stdio.h>
#include <stdlib.h>

int menor(){
	int a;
	int b;

	printf("Ingrese el valor de a: \n");
	scanf("%d", &a);
	printf("Ingrese el valor de b: \n");
	scanf("%d", &b);
	
	if(a<b){
		printf("a es menor\n");
	}else{
		printf("b es menor\n");
	}

}

int suma(){
	int a;
	int b;
	int sum;

	printf("Ingrese el primer numero que quiere sumar: \n");
	printf("->");
	scanf("%d", &a);
	printf("Ingrese el segundo numero que quiere sumar: \n");
	printf("->");
	scanf("%d", &b);

	sum = a + b;
	printf("La suma de %d + %d es %d\n", a, b, sum);

}

int nprimeros(){
	int a;
	int sum;

	printf("Ingrese que primeros n numeros quiere sumar: \n");
	scanf("%d", &a);
	sum = ((a*(a+1))/2);

	printf("La suma de los primeros %d numeros naturales es %d\n", a, sum);
}

int pot(){
	int a;
	int b;
	int mult;

	printf("Para realizar la potencia de forma a^b\n");
	printf("Ingrese un numero a:\n->");

	scanf("%d", &a);
	printf("Ingrese un numero b:\n->");
	scanf("%d", &b);

	mult = a;
	for (int i = 1; i < b; ++i){
		mult = mult * a;
	}
	printf("la potencia %d^%d es: %d",a,b,mult);

}

int main(){

	int opcion;
	printf("##Seleccione una opcion##\n");
	printf("->Opcion 1: Numero menor\n");
	printf("->Opcion 2: Suma de dos numeros\n");
	printf("->Opcion 3: Suma de los primeros n numeros\n");
	printf("->Opcion 4: Potencia de a^b\n");
	scanf("%d",&opcion);

	if(opcion == 1){
		menor();
	}else if(opcion == 2){
		suma();
	}else if(opcion == 3){
		nprimeros();
	}else if(opcion == 4){
		pot();
	}else{
		printf("Ingrese una opcion valida.\n");
	}


	return 0;
}