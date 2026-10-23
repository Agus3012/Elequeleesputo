#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h>  // time

void cargaArre(int arre[], int N){
	int i;
	for (i = 0; i < N; i++) {
		arre[i]= rand () % 100;
	}
    return;
}

void mostrarArre(int arre[], int N){
	int i;
	for (i = 0; i < N; i++) {
		printf("%d \n", arre[i]);
	}
    return;
}


void intercambio (int arre[], int N, int xind1, int xind2){
	int aux;
	aux = arre[xind1];
	arre[xind1] = arre[xind2];
	arre[xind2] = aux;
	return;
}

void mostrar(int arre[], int N){
	int i;
	for (i = 0; i < N; i++){
		printf("%d \n", arre[i]);
	}
	return;
}

void calculoMulti(int arre[] , int N, int xmul){
 	int i;
 	for (i =0; i < N; i ++){
 		if (i % 2 != 0){      //% = mod
 			printf("%d \n", arre[i] * xmul);
		 }
	 }
	 return;
}
 
int generarSubArre(int arre[], int N, int xvalor, int subArre[]){
	int i, j;
	j = 0;
	for (i = 0; i<N; i++){
		if (arre[i]< xvalor){
			subArre[j] = arre[i];
			j = j+1;
		}
	}
	return j;
}

void mostrarSubArre(int subArre[], int xj){
	int i;
	for (i = 0; i < xj; i++){
		printf("%d \n", subArre[i]);
	}
	return;
}

int main (){
	srand(time(NULL)); // esto hace que los numeros cambien cada vez que se ejecuta el programa
	int N = (rand()% 10) + 1; // con rand se genera un valor aleatorio(grande) lo tenemos que limitar con % N
	int arre[N], ind1, ind2, mul, valor, subArre[N], j;
	cargaArre(arre, N);
	mostrarArre(arre, N);
	printf("Ingrese el primer índice \n");
	scanf("%d", &ind1);
	printf("Ingrese el segundo índice \n");
	scanf("%d", &ind2);
	intercambio(arre, N, ind1, ind2); 
	mostrar(arre, N);
	printf("Ingrese un valor para multiplicar los indices impares \n");
	scanf("%d", &mul);
	calculoMulti(arre, N, mul);
	printf("Ingrese un valor: \n");
	scanf("%d", &valor);
	j = generarSubArre(arre, N, valor, subArre);
	mostrarSubArre(subArre, j);
	
	return 0;
}
