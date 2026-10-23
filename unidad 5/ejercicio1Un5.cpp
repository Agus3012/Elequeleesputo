#include <stdio.h>
#include <stdlib.h>

void crearArre(int *&arre, int n);
void cargaArre(int *arre, int N, int i);
int productoEsc(int *arre1, int *arre2, int N, int *pE);
int contar(int *arre, int N);


int main(){
	int *arreglo1 = NULL, *arreglo2 = NULL, *subArre = NULL, tam, pE;
	pE = 0;
	printf("Ingrese el tamaño de los arreglos \n");
	scanf("%d", &tam);
	crearArre(arreglo1, tam);
	crearArre(arreglo2, tam);
	cargaArre(arreglo1, tam, 0);
	cargaArre(arreglo2, tam, 0);
	productoEsc(arreglo1, arreglo2, tam, &pE);
	printf("El producto escalar entre ambos arreglo es de: %d \n", pE);
	contar(arreglo1, tam);
	printf("Direccion: %p \n", (void*)subArre)
	return 0;
}

void crearArre(int *&arre, int n){ //solamente se utiliza la referencia cuando se crea el arreglo en un subprograma
	arre = (int *) malloc(n* sizeof(int));
}

void cargaArre(int *arre, int N, int i){
	if (i < N){
		printf("Ingrese valor del arreglo: ");
		scanf("%d", &arre[i]);
		cargaArre(arre, N, i+1);
	}
}

int productoEsc(int *arre1, int *arre2, int N, int *pE){
	int i;
	for (i=0;i<N;i++){
		*pE = *pE + (arre1[i]*arre2[i]);
	}
}

int contar(int *arre, int N){
	int i, cont;
	cont = 0;
	for(i=0; i<N;i++){
		if (arre[i]%2 == 0){
			cont = cont +1;
		}
	}
	crearArre(subArre, j);
	j = 0;
	for (i=0;i<N;i++){
		if (arre[i]%2 == 0){
			subArre[j] = arre[i];
			j = j+1;
		}
	}
}





