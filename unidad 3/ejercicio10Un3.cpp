#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
#define M 35

typedef struct{
	char nombre[N];
	float precio;
}infoPrenda;

typedef struct{
	int codigo;
	int cuil;
	char nombre[N];
	int arre[N];
}infoCome;

typedef struct{
	char nombre[50];
	int un;
}infoPrenda2;

void carga(infoPrenda prendas[N]){
	int i;
	for (i=0;i<N;i++){
		printf("Ingrese nombre de la prenda: \n");
		fgets(prendas[i].nombre, 50, stdin);
		printf("Ingrese precio unitario: \n");
		scanf("%f", &prendas[i].precio);
	}
	return;
}

void carga2(infoCome comercios[M]){
	int i, j;
	for (i=0;i<M;i++){
		comercios[i].codigo = i+60;
		printf("Ingrese cuil del comercio: \n");
		scanf("%d", &comercios[i].cuil);
		fflush(stdin);
		printf("Ingrese nombre del comercio ");
		fgets(comercios[i].nombre, 50, stdin);
		for (j=0;j<N;j++){
			comercios[i].arre[j] = 0;
		}
	}
	return;
}

int busqueda(infoPrenda prendas[N], char xnom[50]){
	int inf, sup, med, cmp;
	inf = 0;
	sup = N-1;
	med =(inf + sup)/2;
	while ((inf <= sup)&&(strcmp(prendas[med].nombre, xnom)!=0)){
		if(strcmp(prendas[med].nombre, xnom) > 0){
		    sup = med - 1;
		}else{
    		inf = med + 1;
   		}
		med = (inf+sup)/2;
	}
	if (inf<=sup){
		return(med);
	}else{
		return(-1);
	}
}

void procesa(infoCome comercios[M], infoPrenda prendas[N]){
	int un, cod, p;
	char xnom[50];
	printf("Ingrese codigo de comercio (0 para terminar)\n");
	scanf("%d", &cod);
	while (cod!=0){
		fflush(stdin);
		printf("Ingrese nombre de prenda \n");
		fgets(xnom, 50, stdin);
		p = busqueda(prendas, xnom);
		if (p!=-1){
			printf("Ingrese unidades vendidas de la prenda \n");
			scanf("%d", &un);
			comercios[cod-60].arre[p] = comercios[cod-60].arre[p] + un;
		}else{
			printf("Nombre de la prenda no encontrado, intente nuevamente..\n");
		}
		printf("Ingrese codigo de comercio (0 para terminar)\n");
		scanf("%d", &cod);
	}
}

void totalComercios(infoCome comercios[M], infoPrenda prendas[N]){
	int i, j;
	float total;
	for (i=0;i<M;i++){
		total = 0;
		for(j=0;j<N;j++){
			total = total + comercios[i].arre[j] * prendas[j].precio;
		}
		printf("CUIL: %d\n", comercios[i].cuil);
		printf("Nombre: %s\n", comercios[i].nombre);
		printf("Total a pagar del comercio %d: %f\n", i+1, total);
	}
	return;
}

void inciso4(infoCome comercios[M], infoPrenda prendas[N], infoPrenda2 subArre[N]){
	int i, j;
	for(j=0;j<N;j++){
		strcpy(subArre[j].nombre, prendas[j].nombre);
		subArre[j].un = 0;
		for (i=0;i<M;i++){
			subArre[j].un = subArre[j].un + comercios[i].arre[j];
		}
	}
	return;
}

void ordenar(infoPrenda2 subArre[N]){
	int i, k, cota;
	infoPrenda2 aux;
	k = 1;
	cota = N-1;
	while (k != -1){
		k = -1;
		for (i=0;i<cota;i++){
			if (subArre[i].un < subArre[i+1].un){
				aux = subArre[i];
				subArre[i] = subArre[i+1];
				subArre[i+1]=aux;
				k = i;
			}
		}
		cota = k;
	}
	return;
}

int main(){
	infoPrenda prendas[N];
	infoCome comercios[M];
	infoPrenda2 subArre[N];
	int i;
	carga(prendas);
	carga2(comercios);
	procesa(comercios, prendas);
	totalComercios(comercios, prendas);
	inciso4(comercios, prendas, subArre);
	ordenar(subArre);
	printf("Nombre de las 5 prendas líderes en ventas: \n");
	for(i=0;i<5;i++){
		printf("%s\n", subArre[i].nombre);
	}
	return 0;
}
