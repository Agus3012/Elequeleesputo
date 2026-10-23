#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10
#define M 3

typedef struct{
	char nombre[50];
	float precio;
}seguros;

typedef struct{
	int codigo;
	int arre[M];
}promotores;



void carga(seguros seg){
	int i;
	for(i=0;i<M;i++){
		printf("ingrese precio unitario del seguro %d\n",i+1);
		scanf("%f",&seg[i].precio);
		printf("ingrese el nombre del seguro\n");
		fgets(seg[i].nombre,50,stdin);
		fflush(stdin);
	}
}

void cereo()

void carga2(promotores, prom[N]){
	
}

void procesa(promotores prom[N]){
	int p, tipo;
	printf("Ingrese nro de promotor");
	scanf("%d", &p);
	while(p!=0){
		printf("Ingrese tipo de seguro: (1 para A, 2 para B, 3 para C)");
		scanf("%d", &tipo);
		prom[p-1].arre[tipo - 1]=prom[p-1].arre[tipo - 1] +1
		printf("Ingrese nro de promotor");
		scanf("%d", &p);
	}
	return;
}

int inciso3(promotores prom[N], int s){
	int i, max, aux;
	max = -1;
	for (i=0;i<N;i++){
		if(prom[i].arre[s-1]>max){
			max = prom[i].arre[s-1];
			aux = prom[i].sector
		}
	}
	return(aux);
}

int cuenta(promotores prom[N], int sector){
	int i, cont;
	max = -1;
	for (i=0;i<N;i++){
		if(prom[i].sector == sector){
			cont = cont+1;
		}
	}
	return(cont;
}

int main(){
	seguros seg[M];
	promotores prom[N];
	int tipo, sector;
	carga(seg);
	
	printf("Ingrese tipo de seguro: (1 para A, 2 para B, 3 para C)\n");
	scanf("%d", &tipo);
	sector = inciso3(prom, tipo);
	printf("El tipo de seguro %d se vendio mas en el sector %d\n", tipo, sector);
	printf("En el sector %d trabajan %d promotores\n", tipo, cuenta(prom, sector));
	printf("Ingrese sector 30 a 37");
	inciso4();
}


