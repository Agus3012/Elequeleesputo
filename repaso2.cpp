#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nomb[50];
	int edad;
}info;

void crear(info *&arre, int n);
void carga(info *arreglo, int N);
void mostrar(info *arreglo, int N);

int main(){
	info *arre = NULL;
	int tam;
	printf("Ingrese el tamaño del arreglo: \n");
	scanf("%d", &tam);
	while(getchar()!='\n');
	crear(arre, tam);
	carga(arre, tam);
	mostrar(arre, tam);
}

void crear(info *&arre, int n){
	arre = (info *) malloc(n* sizeof(info));
}

void carga(info *arreglo, int N){
	int i;
	for (i=0;i<N;i++){
		printf("Ingrese nombre del participante: \n");
		fgets(arreglo[i].nomb, 50, stdin);
		printf("Ingrese edad del participante: \n");
		scanf("%d", &arreglo[i].edad);
		while(getchar()!='\n');
	}
}

void mostrar(info *arreglo, int N){
	int i;
	float  acum, prom;
	acum = 0;
	printf("Nombre de los participantes:\n");
	for (i=0;i<N;i++){
		printf("%s", arreglo[i].nomb);
		acum = acum + arreglo[i].edad;
	}
	prom = acum / N;
	printf("Edad promedio: %.2f \n", prom);
}


